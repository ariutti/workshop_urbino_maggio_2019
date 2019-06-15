#define POT A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead( POT );
  Serial.write( value / 4 );
  delay(100);
}
