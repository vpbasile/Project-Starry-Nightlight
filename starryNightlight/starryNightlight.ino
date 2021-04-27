// ---Customize these paramters---
const int mins=15;
const int loopsPerMin=20;
const int stepsPerLoop=256;
// ---Stop customizing---

const int loops=mins*loopsPerMin;
const long delayTime = 60000/loopsPerMin/stepsPerLoop;
float stepFrac;

// These can be adjusted to fix drivers that don't dither well
int ledMaxLevel=255;
int ledMinLevel=0;

int whitePin=3;
int amberPin=6;
int bluexPin=9;
const int shutoffPin = 2;

int whiteBound; int whiteCurrent; int whiteTmp; int whiteDiff; int whiteNext;
int amberBound; int amberCurrent; int amberTmp; int amberDiff; int amberNext;
int bluexBound; int bluexCurrent; int bluexTmp; int bluexDiff; int bluexNext;

void setup() {
	Serial.begin(9600);
	Serial.println("-------Beginning Setup-------");
	digitalWrite(shutoffPin,LOW);
	analogWrite(whitePin,0);
	analogWrite(amberPin,0);
	analogWrite(bluexPin,0);
	// Fade up the white LED
	whiteBound = ledMaxLevel;
	for (int i = 0; i <= whiteBound; i++) {
	  analogWrite(whitePin,i);
	  delay(7);
	  }
	whiteCurrent=whiteBound;
	// Fade up the amber LED
	amberBound = ledMaxLevel;
for (int i = 0; i <= amberBound; i++) {
    analogWrite(amberPin,i);
    delay(9);
    }
	amberCurrent=amberBound;
	// Fade up the bluex LED
	bluexBound = ledMaxLevel;
for (int i = 0; i <= bluexBound; i++) {
    analogWrite(bluexPin,i);
    delay(11);
    }
	bluexCurrent=bluexBound;
	randomSeed(analogRead(0)); // Set the random number seed by reading noise from pin 0
	Serial.println("-------Setup complete-------");
	// Loop from full to off very slowly
  
  for (int i=1;i<=loops;i++) {
	  // Get a set of max values (decreases over time
	  bluexBound=255*((loops-((float)i/0.75))/loops); if(bluexBound<0) {bluexBound=0;}
	  amberBound=255*((loops-((float)i/0.85))/loops); if(amberBound<0) {amberBound=0;}
	  whiteBound=255*((loops-((float)i/1.00))/loops); if(whiteBound<0) {whiteBound=0;}
    
    bluexNext=random(bluexBound); bluexDiff=bluexNext-bluexCurrent;
    amberNext=random(amberBound); amberDiff=amberNext-amberCurrent;
    whiteNext=random(whiteBound); whiteDiff=whiteNext-whiteCurrent;
    
   Serial.println("bluexCurrent,bluexNext");
   Serial.println(bluexCurrent);
   Serial.println(bluexNext);

   Serial.println("amberCurrent,amberNext");
   Serial.println(amberCurrent);
   Serial.println(amberNext);

   Serial.println("whiteCurrent,whiteNext");
   Serial.println(whiteCurrent);
   Serial.println(whiteNext);
    
    for (int step=0;step<=stepsPerLoop;step++) {
      stepFrac=(float)step/stepsPerLoop;
      
      bluexTmp=bluexCurrent+(bluexDiff*stepFrac); analogWrite(bluexPin,bluexTmp);
      amberTmp=amberCurrent+(amberDiff*stepFrac); analogWrite(amberPin,amberTmp);
      whiteTmp=whiteCurrent+(whiteDiff*stepFrac); analogWrite(whitePin,whiteTmp);      

      delay(delayTime);
    }
    
    bluexCurrent=bluexNext;
    amberCurrent=amberNext;
    whiteCurrent=whiteNext;
  }
  shutDown();
}

void loop() {
}

void shutDown(){
  Serial.print("Shutting down. ");
  int runtimeResult=millis();
  digitalWrite(shutoffPin,HIGH);
  Serial.print("Runtime was: "); Serial.print(runtimeResult);
  digitalWrite(shutoffPin,LOW);
}
