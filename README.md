Trinket-Timer
=============

Keep time with your Trinket

Hardware
------------
* Adafruit Trinket 3.3 or 5 volt __OR__
* Any Arduino or Arduino Clone
* Adafruit 0.56" 4-Digit 7-segment Display w/I2C Backpack
* 2 Buttons

Usage
------------
Connect a button to pin 1, this button will be used to Start and Stop the timer. Next, connect a second button to pin 4, this button will serve to reset the timer.

Connect the 7-sgement display to the I2C port of your Arduino. On the Trinket use the table below.

If you are using an Arduino, you need to use the Wire.h library, just un-comment the appropriate line at the top of the code. The Trinket uses the TimyWireM.h library, M stands for Master.

| Trinket | LED BackPack|
| :-----: | :---------: |
| 5V/3.3V | +           |
| Gnd     | -           |
| Pin #0  | D (Data)    |
| Pin #2  | C (Clock)   |


Libraries
------------
* Timer by Simon Monk
* Adafruit LEDBackPack
* Adafruit GFX
* Wire or TinyWireM (Depending on the Board)
