int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, value);
  delay(100);
}


void serialEvent()
{
  while (Serial.available()) {
    byte b = Serial.read();
    if(b == 'P')
    {
      value = true;
    }
    else if (b == 'R')
    {
      value = false;
    }
  }
}
