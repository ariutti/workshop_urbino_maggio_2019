// Servo stuff
#include <Servo.h>
Servo myservo;
float value;


// Lyquid Crystal stuff
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


#include "transport_dataset.h"
#define BUTTON 8
int index = 0;
boolean pressed = false;

// SETUP /////////////////////////////////////////////////////////////
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Print a message to the LCD.
  lcd.print("welcome!");
  delay(2000);
  lcd.clear();

  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);

  myservo.attach(9);
  
}


// LOOP //////////////////////////////////////////////////////////////
void loop() {
  if( !digitalRead(BUTTON ) && !pressed )
  {
    pressed = true;
    index = (++index) % NUMBEROFRECORDS;
    printNewData(index);
  } else if (digitalRead(BUTTON) && pressed )
  {
    pressed = false;
  }

  writeToServo( values[index] );
  
  delay(10);
}

// UTILITY ///////////////////////////////////////////////////////////
void printNewData(int _index)
{
  //Serial.print(_index); 
  //Serial.print(" - ");
  //Serial.print(years[_index]);
  //Serial.print(") ");
  //Serial.println(values[_index]);
  lcd.clear();
  lcd.print( _index );
  lcd.print(" - ");
  lcd.print( transport[_index] );
  lcd.setCursor(0, 1);
  lcd.print( values[_index] );
  lcd.print(" CO2 g/pKm");
}

void writeToServo(int _value) 
{
  float val = map(_value, DATAMIN, DATAMAX, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);  
}
