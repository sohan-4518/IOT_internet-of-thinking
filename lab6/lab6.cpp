const int sensorPin=A1;
const int ledPin=13;
const int dryThreshold=800;
const int wetThreshold=500;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  Serial.println("soil moisture sensor test starting...");
}

void loop(){
  int sensorValue=analogRead(sensorPin);
  Serial.print("soil moisture level");
  Serial.println(sensorValue);
  if(sensorValue>dryThreshold){
    Serial.println("soil is dry, water required");
    digitalWrite(ledPin,HIGH);
  }else{
    Serial.println("soil is wet");
    digitalWrite(ledPin,LOW);
  }
}
