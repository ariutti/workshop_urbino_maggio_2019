import processing.serial.*;
Serial myPort;
int inByte;

void setup()
{
  size(400, 400);
  
  //print( Serial.list() );
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  if ( myPort.available() > 0) {  // If data is available,
    inByte = myPort.read();         // read it and store it in val
    //println(inByte);
  }
  
  background(0);
  fill( map(inByte, 0, 255, 0, 255), 0, 0 );
  ellipse( width/2.0, height/2.0, 150, 150);
  
}


/*
#define PHOTO A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(PHOTO);
  Serial.write( value/4 );
  delay(10);
}
*/
