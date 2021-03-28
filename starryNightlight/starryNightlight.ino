// ---Customize these paramters---
const int mins=16; // This value determines how long the program will run
const int loopsPerMin=16; // This value determines how fast the light twinkles 
const int stepsPerLoop=256;
// ---Stop customizing---

// These can be adjusted to fix drivers that don't dither well
int ledMinLevel = 0;
int ledMaxLevel = 255;

//Digesting the customized parameters
const int loops=mins*loopsPerMin;
const int delayTime = 60000/loopsPerMin/stepsPerLoop;

const int bluexPin=9;
int bluexTmp; int bluexDiff;
const int whitePin=3;
int whiteTmp; int whiteDiff;
const int amberPin=6;
int amberTmp; int amberDiff;
const int shutoffPin = 2;
float stepFrac;

//Initialize the LEDs with the pin number
#include <DrivenLED.h>
DrivenLED bluex(bluexPin,ledMinLevel,ledMaxLevel);
DrivenLED amber(amberPin,ledMinLevel,ledMaxLevel);
DrivenLED white(whitePin,ledMinLevel,ledMaxLevel);
DrivenLED indicator(LED_BUILTIN,ledMinLevel,ledMaxLevel);

void setup() {
  Serial.begin(9600);
  Serial.println("-------Beginning Setup-------");
  // Fade up the amber LED to ledMaxLevel and store that value into the Current variable
  amberBound = ledMaxLevel;
  amber.fade(ledMinLevel,amberBound,1000);
  amberCurrent=amberBound;
  // Fade up the white LEDto ledMaxLevel and store that value into the Current variable
  whiteBound = ledMaxLevel;
  white.fade(ledMinLevel,whiteBound,1000);
  whiteCurrent=whiteBound;
  // Fade up the bluex LEDto ledMaxLevel and store that value into the Current variable
  bluexBound = ledMaxLevel;
  bluex.fade(ledMinLevel,bluexBound,1000);
  bluexCurrent=bluexBound;
  randomSeed(analogRead(0)); // Set the random number seed by reading noise from pin 0
  Serial.println("-------Setup complete-------");
  // Loop from full to off very slowly
for (int i=1;i<=loops;i++) {
		// Decrease the bound for each color so that the random values get smaller as time goes by
		bluexBound=(loops-4*i);
		whiteBound=(loops-2*i);
		amberBound=(loops-i);
		
		// Choose a next value that is random, but not too close to zero
		bluexNext=random(bluexBound*random(0,1),bluexBound);
		whiteNext=random(whiteBound*random(0,1),whiteBound);
		amberNext=random(amberBound*random(0,1),amberBound);
		
		// Take a look at how much each color is going to change
		bluexDiff=bluexNext-bluexCurrent;
		whiteDiff=whiteNext-whiteCurrent;
		amberDiff=amberNext-amberCurrent;
		
		for (int step=0;step<=stepsPerLoop;step++) {
			stepFrac=step/stepsPerLoop;
			
			bluexTmp=bluexCurrent+(bluexDiff*stepFrac);
			whiteTmp=whiteCurrent+(whiteDiff*stepFrac);
			amberTmp=amberCurrent+(amberDiff*stepFrac);

			//set the pins
			analogWrite(bluexPin,bluexTmp);
			analogWrite(whitePin,whiteTmp);
      analogWrite(amberPin,amberTmp);

			// Write stuff to the serial monitor for debugging purposes
			Serial.print("bluex:" + bluexBound + "-" + bluexCurrent + "-" + bluexTmp + "-" + bluexNext + "\n");
			Serial.print("white:" + whiteBound + "-" + whiteCurrent + "-" + whiteTmp + "-" + whiteNext + "\n");
			Serial.print("amber:" + amberBound + "-" + amberCurrent + "-" + amberTmp + "-" + amberNext + "\n");
			
			delay(delayTime);
		}
		
		bluexCurrent=bluexNext;
		whiteCurrent=whiteNext;
		amberCurrent=amberNext;
	}
  shutDown();
}

void serialOutput(int current, int next, long bound){ 
  Serial.print(bound);
  Serial.print("-");
  Serial.print(current);
  Serial.print("-");
  Serial.print(next);
  Serial.print("\n");
}

void loop() {
}

void randomPause() {
  delay(2*random(250,1250));
}

void shutDown(){
  Serial.print("Shutting down. ");
  runtimeResult=millis();
  digitalWrite(shutoffPin,HIGH);
  Serial.print("Runtime was: "); Serial.print(runtimeResult);
}
