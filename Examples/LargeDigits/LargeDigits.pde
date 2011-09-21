/*
   Large Digits demo for Matrix Orbital LCD 2041 Display
   Written by Benjamin Konosky
*/

#include <Wire.h>
#include <MatrixOrbitali2c.h>
#include <stdlib.h>

MatrixOrbitali2c lcd(0x2E);

int adcout; 
char adcstr[5];
int i, p;
int tmpc;

void setup() {
  Serial.begin(9600);
  Serial.println("LCD SETUP");
  lcd.begin(4,20);
}

void loop() {
  i = 0;
  p = 1;
  lcd.clear();
  lcd.initLargeDigits();
  adcout = analogRead(0);
  itoa(adcout, adcstr, 10);
  Serial.println(adcstr);
  while (adcstr[i]) {
    tmpc = (int) adcstr[i] - 48;
    lcd.placeLargeDigit(p,tmpc);
    i++;
    p = p+3;
  }
  delay(1000);
}
  
  
