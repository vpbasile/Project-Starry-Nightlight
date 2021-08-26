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

int redPin=3;
int greenPin=6;
int bluexPin=9;
const int shutoffPin = 2;

int redBound; int redCurrent; int redTmp; int redDiff; int redNext;
int greenBound; int greenCurrent; int greenTmp; int greenDiff; int greenNext;
int bluexBound; int bluexCurrent; int bluexTmp; int bluexDiff; int bluexNext;

void setup() {
	Serial.begin(9600);
	Serial.println("-------Beginning Setup-------");
	digitalWrite(shutoffPin,LOW);
	analogWrite(redPin,0);
	analogWrite(greenPin,0);
	analogWrite(bluexPin,0);
	// Fade up the red LED
	redBound = ledMaxLevel;
	for (int i = 0; i <= redBound; i++) {
	  analogWrite(redPin,i);
	  delay(7);
	  }
	redCurrent=redBound;
	// Fade up the green LED
	greenBound = ledMaxLevel;
for (int i = 0; i <= greenBound; i++) {
    analogWrite(greenPin,i);
    delay(9);
    }
	greenCurrent=greenBound;
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
	  greenBound=255*((loops-((float)i/0.85))/loops); if(greenBound<0) {greenBound=0;}
	  redBound=255*((loops-((float)i/1.00))/loops); if(redBound<0) {redBound=0;}
    
    bluexNext=random(bluexBound); bluexDiff=bluexNext-bluexCurrent;
    greenNext=random(greenBound); greenDiff=greenNext-greenCurrent;
    redNext=random(redBound); redDiff=redNext-redCurrent;
    
   Serial.println("bluexCurrent,bluexNext");
   Serial.println(bluexCurrent);
   Serial.println(bluexNext);

   Serial.println("greenCurrent,greenNext");
   Serial.println(greenCurrent);
   Serial.println(greenNext);

   Serial.println("redCurrent,redNext");
   Serial.println(redCurrent);
   Serial.println(redNext);
    
    for (int step=0;step<=stepsPerLoop;step++) {
      stepFrac=(float)step/stepsPerLoop;
      
      bluexTmp=bluexCurrent+(bluexDiff*stepFrac); analogWrite(bluexPin,bluexTmp);
      greenTmp=greenCurrent+(greenDiff*stepFrac); analogWrite(greenPin,greenTmp);
      redTmp=redCurrent+(redDiff*stepFrac); analogWrite(redPin,redTmp);      

      delay(delayTime);
    }
    
    bluexCurrent=bluexNext;
    greenCurrent=greenNext;
    redCurrent=redNext;
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
