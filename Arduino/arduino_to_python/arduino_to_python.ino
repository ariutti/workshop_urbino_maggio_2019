#define POT A0

void setup() 
{  
  Serial.begin(9600);
}

void loop() 
{
  int valore = analogRead(POT);
  Serial.write(valore/4);
  delay(100);
}
