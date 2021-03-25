#include "Arduino.h"
#include "DrivenLED.h"

DrivenLED::DrivenLED(int pinNumber_input,int minLevel_input,int maxLevel_input) {
  // Copy the values to private variables
  _pinNum=pinNumber_input;
  _min=minLevel_input;
  _max=maxLevel_input;
  //Declare LED pin as output
  pinMode(_pinNum, OUTPUT);  
}

void randomDelay() {delay(2*random(2,12));}

void DrivenLED::turnOn(){analogWrite(_pinNum,_max);}
void DrivenLED::turnOff(){analogWrite(_pinNum,_min);}

int DrivenLED::fade(int fromLevel, int toLevel, int time) {
  int _difference=(toLevel-fromLevel); // How many steps
  if(_difference>0) { //Fade Up
    Serial.print("Fade up "); Serial.print(_pinNum); Serial.print(" from "); Serial.print(fromLevel); Serial.print(" to "); Serial.print(toLevel); Serial.print("\n"); Serial.print(_difference); Serial.print(" steps in "); Serial.print(time); Serial.print("milliseconds");
    for (int i = fromLevel; i <= toLevel; i++) {
      analogWrite(_pinNum,i);
      randomDelay();
    }
  }
  if(_difference<0) { //Fade Down
    Serial.print("Fade down "); Serial.print(_pinNum); Serial.print(" from "); Serial.print(fromLevel); Serial.print(" to "); Serial.print(toLevel); Serial.print("\n"); Serial.print(_difference); Serial.print(" steps in "); Serial.print(time); Serial.print("milliseconds");
    if(toLevel<_min){toLevel=0;} //Prevent fading below minlevel
    for (int i=fromLevel; i>= toLevel; i--){
      analogWrite(_pinNum,i);
      randomDelay();
    }
  }
  if(_difference=0) {delay(2*random(100,400));} //Stay the same 
  return toLevel;
}