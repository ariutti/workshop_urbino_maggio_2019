#define BUTTON 7

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);

}

int value = 0;

void loop() {
  value = digitalRead( BUTTON );
  Serial.write(value);
  delay(250);
  
  // put your main code here, to run repeatedly:

}
