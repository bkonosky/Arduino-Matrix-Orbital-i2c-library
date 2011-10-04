/* 
  MatrixOrbitali2c.cpp - Library for accessing the Matrix Orbital LCD 2041 v1.50 over i2c
  Created by Benjamin Konosky, Created 9/6/11
  Released into the Public Domain.
  Version 0.5 - For the Arduino pre 1.0 Wire library.
*/  

#include <MatrixOrbitali2c.h>
#include "WProgram.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Wire.h>

// When the display firsts gets power, it is configured as follows:
//
// 1. Displays Matrix Orbital info.
// 2. No underline cursor.
// 3. No blinking cursor.
// 4. No line wrap.
// 5. No auto scroll.
// 6. Contrast is set to 128.
//
// Arduino reset does not reset the display, so can't assume the display is in that
// state when the constructor is called.


MatrixOrbitali2c::MatrixOrbitali2c ( uint8_t i2cport)

{
  init(i2cport);
}

void MatrixOrbitali2c::init(uint8_t i2cport)
{
  _i2cport = i2cport;
}

void MatrixOrbitali2c::begin(uint8_t rows, uint8_t cols)
{
  Wire.begin();	
  clear();
  noBlink();
  noCursor();
  noAutoScroll();
  noLineWrap();
  setContrast(128);
}

// High Level Commands

void MatrixOrbitali2c::clear()
{
  write(MO_COMMANDCHAR);
  write(MO_CLEARDISPLAY);
}

void MatrixOrbitali2c::home()
{
  write(MO_COMMANDCHAR);
  write(MO_HOME);
}

void MatrixOrbitali2c::autoScroll()
{
  write(MO_COMMANDCHAR);
  write(MO_AUTOSCROLLON);
}

void MatrixOrbitali2c::noAutoScroll()
{
  write(MO_COMMANDCHAR);
  write(MO_AUTOSCROLLOFF);
}

void MatrixOrbitali2c::lineWrap()
{
  write(MO_COMMANDCHAR);
  write(MO_LINEWRAPON);
}

void MatrixOrbitali2c::noLineWrap()
{
  write(MO_COMMANDCHAR);
  write(MO_LINEWRAPOFF);
}
void MatrixOrbitali2c::cursor()
{
  write(MO_COMMANDCHAR);
  write(MO_CURSORON);
}

void MatrixOrbitali2c::noCursor()
{
  write(MO_COMMANDCHAR);
  write(MO_CURSOROFF);
}
void MatrixOrbitali2c::blink()
{
  write(MO_COMMANDCHAR);
  write(MO_CURSORBLINKON);
}

void MatrixOrbitali2c::noBlink()
{
  write(MO_COMMANDCHAR);
  write(MO_CURSORBLINKOFF);
}
void MatrixOrbitali2c::cursorLeft()
{
  write(MO_COMMANDCHAR);
  write(MO_CURSORLEFT);
}

void MatrixOrbitali2c::cursorRight()
{
  write(MO_COMMANDCHAR);
  write(MO_CURSORRIGHT);
}
void MatrixOrbitali2c::gpioOn()
{
  write(MO_COMMANDCHAR);
  write(MO_GPIOON);
}

void MatrixOrbitali2c::gpioOff()
{
  write(MO_COMMANDCHAR);
  write(MO_GPIOOFF);
}
void MatrixOrbitali2c::initNarrowVertical()
{
  write(MO_COMMANDCHAR);
  write(MO_NARROWVERTICALBAR);
}

void MatrixOrbitali2c::initWideVertical()
{
  write(MO_COMMANDCHAR);
  write(MO_WIDEVERTICALBAR);
}
void MatrixOrbitali2c::initHorizontal()
{
  write(MO_COMMANDCHAR);
  write(MO_HORIZONTALBAR);
}

void MatrixOrbitali2c::initLargeDigits()
{
  write(MO_COMMANDCHAR);
  write(MO_INITLARGEDIGITS);
}

void MatrixOrbitali2c::drawVertical(uint8_t col, uint8_t height)
{
  write(MO_COMMANDCHAR);
  write(MO_DRAWVERTICALBAR);
  write(col);
  write(height);
}

void MatrixOrbitali2c::drawHorizontal(uint8_t col, uint8_t row, uint8_t dir, uint8_t length)
{
  write(MO_COMMANDCHAR);
  write(MO_DRAWHORIZONTALBAR);
  write(col);
  write(row);
  write(dir);
  write(length);
}

void MatrixOrbitali2c::placeLargeDigit(uint8_t col, uint8_t digit)
{
  write(MO_COMMANDCHAR);
  write(MO_PLACELARGEDIGIT);
  write(col);
  write(digit);
}

void MatrixOrbitali2c::backlightOff()
{
  write(MO_COMMANDCHAR);
  write(MO_BACKLIGHTOFF);
}

void MatrixOrbitali2c::backlightOn()
{
  backlightOn(0);
}

void MatrixOrbitali2c::backlightOn(uint8_t ontime)
{
  write(MO_COMMANDCHAR);
  write(MO_BACKLIGHTON);
  write(ontime);
}
 
void MatrixOrbitali2c::setContrast(uint8_t contrast)
{
  write(MO_COMMANDCHAR);
  write(MO_SETCONTRAST);
  write(contrast);
}

void MatrixOrbitali2c::createChar(uint8_t location, uint8_t charmap[])
{
  location &= 0x7; // There are only 8 locations 0-7
  write(MO_COMMANDCHAR);
  write(MO_CUSTOMCHAR);
  for (int i=0; i<8; i++) {
   write(charmap[i]);
 }
}

void MatrixOrbitali2c::setCursor(uint8_t h, uint8_t v)
{
 write(MO_COMMANDCHAR);
 write(MO_SETCURSORPOS);
 write(h);
 write(v);
}


// Mid level commands for sending data to the display

inline void MatrixOrbitali2c::write(uint8_t value)
{
  Wire.beginTransmission(_i2cport);
  Wire.send(value);
  Wire.endTransmission();
}

void MatrixOrbitali2c::write(const char *str)
{
  Wire.beginTransmission(_i2cport);
  while (*str)
     Wire.send(*str++);
  Wire.endTransmission();
}

void MatrixOrbitali2c::write(const uint8_t *buffer, size_t size)
{
  Wire.beginTransmission(_i2cport);
  while (size--)
    Wire.send(*buffer++);
  Wire.endTransmission();
}
/*
void MatrixOrbitali2c::print(const String &s)
{
  Wire.beginTransmission(_i2cport);
  for (int i = 0; i < s.length(); i++) {
    Wire.send(s[i]);
  }
  Wire.endTransmission();
}
*/  





