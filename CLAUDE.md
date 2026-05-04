# My Personal Voyager's Keyboard Setup

The 2 key files that are related to my voyager keyboard setup are:

- keyboards/zsa/voyager/keymaps/getreuer/keymap.c
- getreuer.c

To apply the settings and upload the firmware to the keyboard:

```bash
# ZSA Voyager
cd /d/lab/paper/keyboard-qmk
qmk compile -kb zsa/voyager -km getreuer
qmk flash -kb zsa/voyager -km getreuer
```
