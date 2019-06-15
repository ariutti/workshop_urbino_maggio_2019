import processing.serial.*;
Serial myPort;

void setup() {
  size(200, 200);
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(0);
}

void mousePressed() {
  myPort.write('P'); 
}

void mouseReleased() {
  myPort.write('R'); 
}
