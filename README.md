# ThinkMatrix Keyboard Firmware

This is the firmware for my custom ortholinear keyboard, based on the [tmk keyboard library](https://github.com/tmk/tmk_core).  

The keyboard runs on a [Teensy 2.0](http://www.pjrc.com/store/teensy.html). You can find more detail about the design of keyboard itself in the directory `docs`.

Images and a buildlog of the keyboard can be found [here](https://geekhack.org/index.php?topic=76167.0).


## Cloning, building & flashing

You need the AVR cross-compilation toolstack to compile the firmware.

See [tmk keyboard](https://github.com/tmk/tmk_keyboard) and [Teensy howto](https://www.pjrc.com/teensy/gcc.html) for more informations.

Since this repository has a submodule the cloning needs an additional argument to init and update the submodule.

```
git clone --recursive https://github.com/nagius/tmk_thinkmatrix
cd tmk_thinkmatrix
make
```

This will generate the firmware file `thinkmatrix-fw.hex`.

### Upload

Start the graphical [loader tool](https://www.pjrc.com/teensy/loader_linux.html) :

```
teensy.64bit &
```

Plug the Teensy on USB, push the program button, select the generated file `thinkmatrix-fw.hex` and click 'Upload'.


## Update to the lastest version

```
git pull
git submodule sync --recursive
git submodule update --init --recursive
```
