
//#include "Wire.h" // Enable this line if using Arduino Uno, Mega, etc.
#include <TinyWireM.h> // Enable this line if using Adafruit Trinket, Gemma, etc.

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Timer.h"

Timer t;
Adafruit_7segment disp = Adafruit_7segment();

int startstop = 1;    // The Green Button, Starts and Stops the Timer
int reset = 4;        // The Red Button, Restets the Timer AFTER is has been stopped.

// The Clock Variables
int mins = 0;  
int secs = 0;

boolean timerActive = false;  // Is the timer running?

void setup(){
  //  Serial.begin(9600);

  disp.begin(0x70);   // The address of our display

  resetDisplay();

  pinMode(startstop, INPUT);
  pinMode(reset, INPUT);

  t.every(1000, updateDisplay);  // Triggers the UpdateDisplay funcion every second
}

void loop(){

  if (digitalRead(startstop) == HIGH){
    // Serial.println("Timer Started/Stopped!");
    // Toggels the Timer State
    timerActive = !timerActive;
    delay(250);
  }

  if (!timerActive && digitalRead(reset) == HIGH){
    // Serial.println("Timer Reset!");
    mins = secs = 0;   //Resets the Clock Variables
    resetDisplay();    //Resets the Display to 00:00
    delay(250);
  }

  if (timerActive) {
    t.update();   //This is what cycles the timer, ie. tells it to count
  }

}

void updateDisplay(){
  // Increment the Display
  secs += 1;
  if (secs >= 60){
    // This increments the mins after 60 seconds.
    secs = 0;
    mins += 1; 
  }

  // Wirte the new value to the display
  disp.writeDigitNum(0, (mins / 10));
  disp.writeDigitNum(1, mins % 10);
  disp.drawColon(true);
  disp.writeDigitNum(3, (secs / 10));
  disp.writeDigitNum(4, secs % 10);

  disp.writeDisplay(); // Writes the changes to the display, moving the numbers from the buffer
}

void resetDisplay(){
  // Write 00:00 to the diplay
  disp.writeDigitNum(0, 0);
  disp.writeDigitNum(1, 0);
  disp.drawColon(true);
  disp.writeDigitNum(3, 0);
  disp.writeDigitNum(4, 0);

  disp.writeDisplay(); 

}






