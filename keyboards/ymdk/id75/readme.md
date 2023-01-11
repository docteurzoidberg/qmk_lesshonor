# Idobao x YMDK ID75

![Idobao x YMDK ID75](https://imgur.com/bhVfzrzl.jpg)

A 75-key, 5-row ortholinear keyboard with per-key and downward-facing RGB LEDs.

* Keyboard Maintainer: [The QMK Community](https://github.com/qmk)
* Hardware Supported: [Idobao x YMDK ID75 PCB (F103)](https://www.aliexpress.com/item/3256804537842097.html)
  *  This PCB uses an "F103-compatible" MCU with 128kb flash. **It is not the same as idobao/id75 or ymdk/ymd75.**
* Hardware Availability: [YMDK](https://ymdkey.com/)

Make example for this keyboard (after setting up your build environment):

    make ymdk/id75:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key and plug in the keyboard. This will also clear the emulated EEPROM, so it is a good first step if the keyboard is misbehaving.
* **Physical reset button**: Press the button on the back of the PCB twice in quick succession.
* **Keycode in layout**: Press the key mapped to `QK_BOOT`. In the pre-supplied keymaps it is on the second layer, in the bottom-right corner.

After entering the bootloader through one of the three methods above, the keyboard will appear as a USB mass storage device named `???`. Copy the compiled `.uf2` file onto this device. The keyboard will reboot on completion with the new firmware loaded.
