# Thumb tap-hold misfire fix

**Date:** 2026-05-04
**Scope:** Voyager keymap (`getreuer` keymap) — fix `<Enter>e` misfires when chording the left-thumb-small layer key with right-hand keys.

## Problem

When typing strings like `alpha_cc_1`, the user holds `LEFT_THUMB_SMALL` (= `LT(LAY_CTRL, KC_ENT)`) and presses a right-hand key to type a symbol on the `LAY_CTRL` layer (e.g. `_` at slot k73 = the `E` finger position on Graphite). On fast input, the firmware emits the tap value `<Enter>` followed by the next key (`e`) instead of the layered symbol (`_`).

## Root cause

QMK settles a layer-tap before achordion runs. The current config has:

| Setting | State |
|---|---|
| `TAPPING_TERM` | 170 ms (`config_getreuer.h:22`) |
| `PERMISSIVE_HOLD` | enabled (`config_getreuer.h:24`) |
| `HOLD_ON_OTHER_KEY_PRESS` | not defined |
| Achordion thumb whitelist | allows same-hand chords for thumbs (`getreuer.c:396-400`) |

`PERMISSIVE_HOLD` only resolves to "hold" when the other key is **fully nested** (pressed *and released*) inside the LT window. A fast roll where the user lifts the thumb before releasing the symbol key — i.e. thumb-down → E-down → thumb-up → E-up, all under 170 ms — does **not** match the permissive-hold pattern. QMK falls back to "tap", emits `<Enter>`, and achordion never gets a chance to override because the decision was already made.

## Fix

Enable `HOLD_ON_OTHER_KEY_PRESS` **only for the four thumb layer-tap keys**. This makes a thumb LT settle as "hold" the instant any other key goes down, which is the correct semantics for thumb-driven layer activation. Home-row mods and other tap-hold keys keep their current `PERMISSIVE_HOLD`-only behavior, preserving alpha-roll ergonomics.

### Files changed

**`config_getreuer.h`** — add adjacent to existing tap-hold defines:

```c
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
```

**`getreuer.c`** — add new callback near `get_quick_tap_term` (around line 345):

```c
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LEFT_THUMB_SMALL:
    case LEFT_THUMB_BIG:
    case RIGHT_THUMB_SMALL:
    case RIGHT_THUMB_BIG:
      return true;
  }
  return false;
}
```

The four whitelisted symbols are defined at `getreuer.c:203-208`:
- `LEFT_THUMB_SMALL` = `LT(LAY_CTRL, KC_ENT)`
- `LEFT_THUMB_BIG` = `RCTL_T(KC_ESC)`
- `RIGHT_THUMB_SMALL` = `LT(SYM1, KC_SPC)`
- `RIGHT_THUMB_BIG` = `RALT_T(KC_BSPC)`

`LEFT_THUMB_BIG` and `RIGHT_THUMB_BIG` are mod-taps not layer-taps; including them is safe and matches the existing achordion thumb whitelist (`getreuer.c:396-400`) and `get_quick_tap_term` thumb list (`getreuer.c:351-354`) for consistency.

### What does NOT change

- `TAPPING_TERM` stays at 170 ms.
- `PERMISSIVE_HOLD` stays globally enabled.
- All achordion logic stays untouched.
- All home-row mods (`gMOD_*`, `MOD_*`) and other LT keys (`S_MOD`, `T_MOD`, `G_MOD`, `LAY_NAV`, `gLAY_NUM`, `CKC_CAPS`) return `false` from the new callback → unchanged behavior.

## Validation

After flashing:

1. **Primary case:** Type `alpha_cc_1` ten times rapidly. Expect zero `<Enter>e` artifacts; all underscores produced cleanly.
2. **Other thumb-layer chords:** Type `()`, `{}`, `==`, `:` via thumb-small + symbol. Should fire reliably.
3. **Tap regression:** Press and release Enter alone in a chat/terminal. Still types Enter (single, not held).
4. **Home-row mod regression:** Type `the`, `that`, `where`, `there` rapidly. Home-row mods must NOT fire prematurely (e.g. the `t` on `T_MOD` should not drop the user into `T_BASIC` mid-word).
5. **Combo regression:** `LEFT_THUMB_SMALL + S_MOD` (Ctrl+F12 / tmux), `H + RIGHT_THUMB_SMALL` (F14 / Flow Launcher). Both fire correctly.

## Risk and reversibility

Low risk. The four thumbs are the only behavior change; the rest of the keymap is untouched. The one ergonomic regression is "tap-roll" patterns — pressing a thumb and another key in quick succession while intending the tap value (`<Enter>` then `<letter>` or `<Space>` then `<letter>`). This is rare for Enter and Backspace, and the user can fully release the thumb in a deliberate beat for those cases.

Reversible by deleting the two defines and the callback (~10 lines).

## Out of scope

- Migrating to `CHORDAL_HOLD` (QMK 0.25+, would replace achordion). Tracked as a future option; not needed to resolve this misfire.
- Adding `_` to `custom_shift_keys` on `KC_MINS`. Sidesteps only this one symbol; doesn't fix the underlying tap-hold timing problem for the rest of the layer.
