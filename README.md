# godshottimer
This is a toy project my sister and I developed together which times extraction
time of espresso. It's essentially a manually multiplexed 7-segment display
which acts as a clock and 25-second timer.

## Pictures
Here's a picture of the timer when it is off

![Timer when it's off](https://raw.githubusercontent.com/johndoe31415/godshottimer/master/docs/gst01_front_off.jpg)

This is the backside. It uses 0805 SMD components:

![Backside](https://raw.githubusercontent.com/johndoe31415/godshottimer/master/docs/gst02_back_off.jpg)

In clock mode:

![Clock mode](https://raw.githubusercontent.com/johndoe31415/godshottimer/master/docs/gst03_clock.jpg)

And in timer mode:

![Timer mode](https://raw.githubusercontent.com/johndoe31415/godshottimer/master/docs/gst04_timer.jpg)

## Usage
After reset the timer clock is in "set time" mode. Pressing the inner button
sets hours, the outer button sets minutes.

Pressing both buttons at the same time changes between clock and stopwatch
mode. In stopwatch mode, the outer button starts/stops the timer. The inner
button resets the timer. The timer starts at 25.0 seconds and counts down
towards -99.9 seconds, at which point it stops.

## Hardware
  - ATmega88PA ([Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061B.pdf))
  - 8 MHz external crystal
  - Fuse configuration `-U lfuse:w:0xf6:m -U hfuse:w:0xdf:m -U efuse:w:0xf9:m`
    (no CKDIV, Ext. Full Swing, Startup 14 CK + 4.1ms)
 
## Pinout
  - External connections, viewed from top: +5V, GND, Switch
  - Digit 4 (+): Pin 2, PD0
  - Segment D (-): Pin 3, PD1
  - Segment C (-): Pin 4, PD2
  - Digit 3 (+): Pin 24, PC1
  - Digit 2 (+): Pin 6, PD4
  - Segment E (-): Pin 14, PB0
  - Digit 1 (+): Pin 13, PD7
  - Segment G (-): Pin 12, PD6
  - Segment F (-): Pin 11, PD5
  - Segment Dot (-): Pin 15, PB1
  - Segment A (-): Pin 16, PB2
  - Segment B (-): Pin 23, PC0
  - Outer switch: Pin 28, PC5
  - Inner switch: Pin 27, PC4,
  - External switch: Pin 26, PC3 (unused)
  - Buzzer (+): Pin 5, PD3

## License
GNU GPL-3.
