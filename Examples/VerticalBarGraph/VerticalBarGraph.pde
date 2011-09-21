/*
   Vertical bar graph demo for Matrix Orbital LCD 2041 Display
   Written by Benjamin Konosky
*/

#include <Wire.h>
#include <MatrixOrbitali2c.h>
#include <stdlib.h>

MatrixOrbitali2c lcd(0x2E);

int adcout; 
int i;
int tmpc;

void setup() {
  Serial.begin(9600);
  Serial.println("LCD SETUP");
  lcd.begin(4,20);
}

void loop() {
  i = 1;
  lcd.clear();
  lcd.initWideVertical();
  while (i < 21 ) {
    adcout = analogRead(0);
    Serial.println(i);
    Serial.println(adcout);
    tmpc = adcout * 32 / 1024;
    Serial.println(tmpc);
    lcd.drawVertical(i,tmpc);
    i++;
    delay(1000);
  }
}
  
  
