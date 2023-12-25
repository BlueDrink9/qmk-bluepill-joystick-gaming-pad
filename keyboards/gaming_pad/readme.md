# gaming_pad

![gaming_pad](imgur.com image replace me!)

*One handed 20 key custom keyboard for gaming, with included joystick*

* Keyboard Maintainer: [bluedrink9](https://github.com/bluedrink9)

Make example for this keyboard (after setting up your build environment):

    make gaming_pad:default

Flashing example for this keyboard:

    dfu-util -a 2 -d 1EAF:0003 -D .build/gaming_pad_default.bin

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: On the bluepill, hold the KEY0 button then press the NRST button.
* **Keycode in layout**: Hold 5, then press space

The bootloader only persists briefly, so start the dfu flash asap.
