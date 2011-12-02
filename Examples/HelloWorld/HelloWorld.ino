/*
  Hello World demo for Matrix Orbital LCD 2041 Display.
  
*/

#include <Wire.h>
#include <MatrixOrbitali2c.h>
#include <stdlib.h>

MatrixOrbitali2c lcd(0x2E);

void setup() {
  Serial.begin(9600);
  Serial.println("LCD SETUP");
  lcd.begin(4,20);
}

void loop() {
  Serial.println("LCD Clear");
  lcd.clear();
  delay(2000);
  Serial.println("Hello World");
  lcd.print("Hello World");
  delay(2000);
}
