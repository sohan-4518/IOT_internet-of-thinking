
void setup()
{
  pinMode(8, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int temp =digitalRead(8);
  Serial.println("Intensity");
  Serial.println(temp);
  delay(300);
  if(temp == HIGH)
    digitalWrite(9,HIGH);
    else
    digitalWrite(9,LOW);
}
