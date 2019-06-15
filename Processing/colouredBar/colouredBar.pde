import processing.serial.*;
Serial myPort;
int inByte;

// coloured bar
float barW = 100;
float value = 0;

void setup() {
  size(800, 600);
  print( Serial.list() );
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(0);
  
  if ( myPort.available() > 0) {  // If data is available,
    inByte = myPort.read();         // read it and store it in val
    //println(inByte);
    value = map(inByte, 255, 0, 0, height-50);
  }
  
  noFill();
  stroke(255,129,0);
  rect( (width - barW)*0.5, 25, barW, height-50);
  
  noStroke();
  fill(220,100,0);
  rect( (width - barW)*0.5, height-25-value, barW, value);   
}

/*
void mouseMoved() {
  value = map(mouseY, height, 0, 0, height-50);
}
*/
