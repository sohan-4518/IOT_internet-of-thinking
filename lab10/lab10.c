#define TRIG 9
#define ECHO 10
long duration;
float distance;
float tankDepth = 30.0;
float waterLevel;
void setup(){
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}
void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO,HIGH);
  distance = duration * 0.034/2;
  waterLevel = tankDepth-distance;
  if(waterLevel<0) waterLevel = 0;
  if(waterLevel > tankDepth) waterLevel = tankDepth;
  Serial.print("Distance");
  Serial.print(distance);
  Serial.println("cm");
  delay(1000);
}
  
                     














  
  
  
  
 

