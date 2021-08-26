// ---Customize these paramters---
const int loopsPerMin=20;
const int stepsPerLoop=256;
// ---Stop customizing---

const long delayTime = 60000/loopsPerMin/stepsPerLoop;
float stepFrac;

// These can be adjusted to fix drivers that don't dither well
int ledMaxLevel=255;
int ledMinLevel=0;

int redPin=3;
int grnPin=6;
int bluPin=9;
const int shutoffPin = 2;

int redBound; int redCurrent; int redTmp; int redDiff; int redNext;
int grnBound; int grnCurrent; int grnTmp; int grnDiff; int grnNext;
int bluBound; int bluCurrent; int bluTmp; int bluDiff; int bluNext;

void setup() {
	Serial.begin(9600);
	Serial.println("-------Beginning Setup-------");
	digitalWrite(shutoffPin,LOW);
	analogWrite(redPin,0);
	analogWrite(grnPin,0);
	analogWrite(bluPin,0);
// Fade up the blu LED
	bluBound = ledMaxLevel;
for (int i = 0; i <= bluBound; i++) {
    analogWrite(bluPin,i);
    delay(11);
    }
	bluCurrent=bluBound;
// Fade up the grn LED
  grnBound = ledMaxLevel;
for (int i = 0; i <= grnBound; i++) {
    analogWrite(grnPin,i);
    delay(9);
    }
  grnCurrent=grnBound;
// Fade up the red LED
  redBound = ledMaxLevel;
  for (int i = 0; i <= redBound; i++) {
    analogWrite(redPin,i);
    delay(7);
    }
  redCurrent=redBound;

	
	
	// Other stuff
	randomSeed(analogRead(0)); // Set the random number seed by reading noise from pin 0
	Serial.println("-------Setup complete-------");
	// Loop from full to off very slowly  
//   for (int i=1;i<=loops;i++) {
//  }
//  shutDown();
}

void loop() {
    
    bluNext=random(bluBound); bluDiff=bluNext-bluCurrent;
    grnNext=random(grnBound); grnDiff=grnNext-grnCurrent;
    redNext=random(redBound); redDiff=redNext-redCurrent;
    
   Serial.println("bluCurrent,bluNext");
   Serial.println(bluCurrent);
   Serial.println(bluNext);

   Serial.println("grnCurrent,grnNext");
   Serial.println(grnCurrent);
   Serial.println(grnNext);

   Serial.println("redCurrent,redNext");
   Serial.println(redCurrent);
   Serial.println(redNext);
    
    for (int step=0;step<=stepsPerLoop;step++) {
      stepFrac=(float)step/stepsPerLoop;
      
      bluTmp=bluCurrent+(bluDiff*stepFrac); analogWrite(bluPin,bluTmp);
      grnTmp=grnCurrent+(grnDiff*stepFrac); analogWrite(grnPin,grnTmp);
      redTmp=redCurrent+(redDiff*stepFrac); analogWrite(redPin,redTmp);      

      delay(delayTime);
    }
    
    bluCurrent=bluNext;
    grnCurrent=grnNext;
    redCurrent=redNext;
}

void shutDown(){
  Serial.print("Shutting down. ");
  int runtimeResult=millis();
  digitalWrite(shutoffPin,HIGH);
  Serial.print("Runtime was: "); Serial.print(runtimeResult);
  digitalWrite(shutoffPin,LOW);
}
