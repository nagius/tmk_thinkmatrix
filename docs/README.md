= Documentation, schematics and drawing =

You will find in this directory the files needed to buid the keyboard. Everything is released under GNU/GPLv3 Licence if not specified otherwise.
 
 - keyboard-layout.json: Data file for http://www.keyboard-layout-editor.com/
 - CAD: All LibreCAD needed to build the case and the plate
 - PCB: the KiCad project to make the PCB

Please note there is a couple of errors on this PCB design:

 - The pins labelling of the Teensy module are wrong, please refer to the table below for the correct pinout.
 - When soldering the Teensy, pins C6 and D7 must be swapped (with a couple of wire for example).
 - Clearance around the Cherry MX stabilizers is not good enough in few cases, 5 of the resistors need to be soldiered on the back of the board.
 - The diodes are in the wrong way around for the tmk_keyboard firmware, the matrix need to be rotated in the source code. Note this is tmk specific, it does not apply if you're using a qmk_keyboard firmware.


= Teensy pinout =

 - Matrix

| Row | 0  | 1  | 2  | 3  | 4  | 5  | 6  |
|-----|----|----|----|----|----|----|----|
| Pin | B2 | B0 | B1 | E6 | B3 | B7 | D0 |


| Col | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 | 13 |
|-----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
| Pin | F0 | F1 | F4 | B4 | F5 | D3 | D2 | C7 | F7 | B6 | B5 | D5 | D4 | C6 |

 - Front leds: D1, D6, F6
 - Backlight: D7


= Parts list =

 - 1x  Teensy 2.0
 - 85x Cherry MX switches
 - 9x  Cherry MX stabilizers
 - 85x Diodes 1N4148
 - 89x Orange LEDs (1.92V @ 7mA)
 - 43x Resistors 36 ohms
 - 4x  Resistors 200 ohms
 - 1x  Resistors 1.4k ohms
 - 1x  Capacitor 100µF
 - 1x  Transistor 2N3904
 - 1x  Transistor PN2907A