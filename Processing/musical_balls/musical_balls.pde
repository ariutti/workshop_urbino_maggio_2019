import processing.sound.*;

SinOsc triOsc;
Env env;

float attackTime = 0.01;
float sustainTime = 0.02;
float sustainLevel = 0.7;
float releaseTime = 0.1;

// time variables
long dur = 1000;
long current, previous;
float MINRADIUS = 50;
float MAXRADIUS = 200;
float radius = MAXRADIUS;

// notes
int musicalphrase[] = {60, 62, 64, 67, 69, 72,74, 76, 79, 81};

import processing.serial.*;
Serial myPort;
int inByte;

void setup() 
{
  size(640, 360);
  
  //print( Serial.list() );
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  
  // Create triangle wave
  triOsc = new SinOsc(this);

  // Create the envelope 
  env  = new Env(this); 
  
  current = 0;
  previous = 0;
  
  background(0);
}      


void draw() {
  
  if ( myPort.available() > 0) {  // If data is available,
    inByte = myPort.read();         // read it and store it in val
    //println(inByte);
  }
  
  noStroke();
  fill(0, 0, 0, 10);
  rect(0,0, width, height);
  
  
  current = millis();
  if( current - previous > dur) {
     playTheSound();
     previous = current;
  }
  
}

void playTheSound() {
  triOsc.freq( midicps( musicalphrase[ int(random(musicalphrase.length))] ) );
  triOsc.play();
  env.play(triOsc, attackTime, sustainTime, sustainLevel, releaseTime);
  
  fill( random(255), random(255), random(255) );
  noStroke();
  ellipse( random(width), random(height), radius, radius);
  //reverb.process(env);
}

float midicps(int _midinote) {
    float a = 440.0; //frequency of A (coomon value is 440Hz)
    float freq = (a / 32.0) * (pow(2,((_midinote - 9.0) / 12.0)));
    //println( freq );
    return freq;  
}

void mouseDragged() {
  manageDurationAndRadius( mouseX );
}

void manageDurationAndRadius(int value) {
  float mapped = map(value, 0, width, 1000, 100);
  mapped = constrain(mapped, 100, 1000) ;
  dur = int( mapped );
  radius =  map(mapped, 100, 1000, MINRADIUS, MAXRADIUS);
}
