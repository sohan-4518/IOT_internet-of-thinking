#define PIEZO_PIN 9
const int trigger =6;
const int echo =7;
const int  soundPin=A0;
float distance;
float dist_inches;

const  float DIST_THRESHOLD=5.0;
const int SOUND_THRESHOLD=520;

void setup() {
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(PIEZO_PIN,OUTPUT);
}

void loop() {
  digitalWrite(trigger,LOW);
  delayMicroseconds(5);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  distance=pulseIn(echo,HIGH);
  distance=distance*0.0001657;
  dist_inches=distance*39.37;
  
  int soundValue=analogRead(soundPin);

  if(dist_inches<DIST_THRESHOLD && soundValue>SOUND_THRESHOLD){
    tone(PIEZO_PIN,1500);
    delay(200);
    noTone(PIEZO_PIN);

    Serial.print("Intrusion Detected!. Object with sound at Distance:");
    Serial.print(dist_inches);
    Serial.println("inches");
  }
  else if(dist_inches<DIST_THRESHOLD){
    Serial.print("Object Detected at distance: ");
    Serial.print(dist_inches);
    Serial.println("inches");
  }
  else if(soundValue>SOUND_THRESHOLD){
    Serial.println("Sound Detected");
  }
  else{
    Serial.println("No Intrusion Detected");
  }
  delay(200);
  }
