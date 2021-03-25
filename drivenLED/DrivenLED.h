/*
DrivenLED - Library to simplify controlling an LED driver with an Arduino PWM pin
Created by Vincent P. Basile, 2021 March 3
Released into the public domain
*/

#ifndef DrivenLED_h
#define DrivenLED_h

#include "Arduino.h"

class DrivenLED {
    public:
        DrivenLED(int pinNumber,int minLevel_input,int maxLevel_input);
        void turnOn();
        void turnOff();
        int fade(int fromLevel, int toLevel, int time);
    private:
        int _pinNum;
        int _min; 
        int _max;
        int randomDelayTime;
        
};

#endif