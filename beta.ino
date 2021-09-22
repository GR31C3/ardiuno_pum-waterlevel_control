//VARIABLE WATER BUCKET
//define pin for led water basket
int redLed=10;
int greenLed=9;
int blueLed=8;
//define pin for sensor
int waterSensor=analogRead(A1);
//define water level water bucket
float maxLev=400.00;
float midLev=200.00;

//VARIABLE PUMP
//define pin relay pump// need to connect pump and adapter throgh a relay
int relayPin=A5;
//define value pump turn off/on
int pumpOn=5*60000;
int pumpOff=50*60000;

//DEFINE OVERLAPPING
const unsigned long intervall=56*60000;
unsigned long previusTime=0;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
 //loop for on/off pump
 digitalWrite(relayPin,HIGH);
 delay(pumpOn);
 digitalWrite(relayPin,LOW);
 delay(pumpOff);
  
 //loop led water bucket
 unsigned long currenTime=millis();
 if(currenTime-previusTime >= intervall){
  if (waterSensor > maxLev){
    Serial.println("Full");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, LOW);
 }
  else if ((waterSensor > midLev) && (waterSensor <= maxLev)) {
    Serial.println("Middle");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(blueLed, LOW);
 }
  else{
    Serial.println("No water");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, HIGH);
 }
 previusTime=currenTime;
}
}
