
//#include "Wire.h" // Enable this line if using Arduino Uno, Mega, etc.
#include <TinyWireM.h> // Enable this line if using Adafruit Trinket, Gemma, etc.

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Timer.h"

Timer t;
Adafruit_7segment disp = Adafruit_7segment();

int startstop = 1;
int reset = 4;

int mins = 0;
int secs = 0;

boolean timerActive = false;

void setup(){
//  Serial.begin(9600);

  disp.begin(0x70);

  resetDisplay();

  pinMode(startstop, INPUT);
  pinMode(reset, INPUT);

  t.every(1000, updateDisplay);
}

void loop(){

  if (digitalRead(startstop) == HIGH){
//    Serial.println("Timer Started/Stopped!");
    timerActive = !timerActive;
    delay(250);
  }

  if (!timerActive && digitalRead(reset) == HIGH){
//    Serial.println("Timer Reset!");
    mins = secs = 0; 
    resetDisplay();
    delay(250);
  }

  if (timerActive) {
    t.update(); 
  }

}

void updateDisplay(){
  // Increment the Display
  secs += 1;
  if (secs >= 60){
    secs = 0;
    mins += 1; 
  }

  disp.writeDigitNum(0, (mins / 10));
  disp.writeDigitNum(1, mins % 10);
  disp.drawColon(true);
  disp.writeDigitNum(3, (secs / 10));
  disp.writeDigitNum(4, secs % 10);

  disp.writeDisplay();
}

void resetDisplay(){
  disp.writeDigitNum(0, 0);
  disp.writeDigitNum(1, 0);
  disp.drawColon(true);
  disp.writeDigitNum(3, 0);
  disp.writeDigitNum(4, 0);

  disp.writeDisplay(); 

}





