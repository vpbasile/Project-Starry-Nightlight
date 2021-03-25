//Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

#include <DrivenLED.h>

int ledMinLevel = 0;
int ledMaxLevel = 255;
long runtimeResult=0;

const int bluePin=9;
const int amberPin=6;
const int whitePin=3;

//Initialize the LEDs with the pin number
DrivenLED blue(bluePin,ledMinLevel,ledMaxLevel);
DrivenLED amber(amberPin,ledMinLevel,ledMaxLevel);
DrivenLED white(whitePin,ledMinLevel,ledMaxLevel);
DrivenLED indicator(LED_BUILTIN,ledMinLevel,ledMaxLevel);
const int shutoffPin = 2;

const int runTime = 900; //15 minutes=900000ms
const int twinkleTime = 2; //Half a second
long amberSlope = -1; long amberBound;
int amberCurrent; int amberNext;
long whiteSlope = -2; long whiteBound;
int whiteCurrent; int whiteNext; 
long blueSlope = -3; long blueBound;
int blueCurrent; int blueNext; 

void setup() {
  Serial.begin(9600);
  Serial.println("-------Beginning Setup-------");
  // Fade up the amber LED
  amberBound = ledMaxLevel;
  amber.fade(ledMinLevel,amberBound,1000);
  amberCurrent=amberBound;
  // Fade up the white LED
  whiteBound = ledMaxLevel;
  white.fade(ledMinLevel,whiteBound,1000);
  whiteCurrent=whiteBound;
  // Fade up the blue LED
  blueBound = ledMaxLevel;
  blue.fade(ledMinLevel,blueBound,1000);
  blueCurrent=blueBound;
  randomSeed(analogRead(0)); // Set the random number seed by reading noise from pin 0
  Serial.println("-------Setup complete-------");
  // Loop from full to off very slowly
  for (int i=1;i<256;i++){
    blueBound=(256-4*i);
    if (blueBound>-1){
      blueNext=random(blueBound*random(0,1),blueBound);
      Serial.print("blue:"); Serial.print(blueBound);Serial.print("-");Serial.print(blueCurrent);Serial.print("-");Serial.print(blueNext);Serial.print("\n");
      blueCurrent=blue.fade(blueCurrent,blueNext,700);
      randomPause();
    }
    whiteBound=(256-2*i);
    if (whiteBound>-1){
      whiteNext=random(0.7*whiteBound,whiteBound);
      Serial.print("white:"); serialOutput(whiteCurrent,whiteNext,whiteBound);
      whiteCurrent=white.fade(whiteCurrent,whiteNext,500);
      randomPause();
    }
    amberBound=(256-i);
    if (amberBound>-1){
      amberNext=random(0.7*amberBound,amberBound);
      Serial.print("amber:"); serialOutput(amberCurrent,amberNext,amberBound);
      amberCurrent=amber.fade(amberCurrent,amberNext,200);
      randomPause();
    }
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
