/*
  MatrixOrbitali2c.h - Library for accessing the Matrix Orbital LCD 2041 v1.50 over i2c
  Created by Benjamin Konosky, Created 9/6/11
  Released into the Public Domain.
  Version 1.0 - For the Arduino 1.0 Wire library.
*/

#ifndef MatrixOrbitali2c_h
#define MatrixOrbitali2c_h

#include <inttypes.h>
#include "Print.h"
#include "Arduino.h"
#include <Wire.h>

// Command character

#define MO_COMMANDCHAR 0xFE


// Display commands
#define MO_CLEARDISPLAY 0x58
#define MO_HOME 0x48
#define MO_AUTOSCROLLON 0x51
#define MO_AUTOSCROLLOFF 0x52
#define MO_LINEWRAPON 0x43
#define MO_LINEWRAPOFF 0x44
#define MO_SETCURSORPOS 0x47

// Cursor commands
#define MO_CURSORON 0x4A
#define MO_CURSOROFF 0x4B
#define MO_CURSORBLINKON 0x53
#define MO_CURSORBLINKOFF 0x54

#define MO_CURSORLEFT 0x4C
#define MO_CURSORRIGHT 0x4D


// Bar Graphs
#define MO_WIDEVERTICALBAR 0x76
#define MO_NARROWVERTICALBAR 0x73
#define MO_DRAWVERTICALBAR 0x3D
#define MO_HORIZONTALBAR 0x68
#define MO_DRAWHORIZONTALBAR 0x7C

// Large Digits
#define MO_INITLARGEDIGITS 0x6E
#define MO_PLACELARGEDIGIT 0x23

// Custom Character
#define MO_CUSTOMCHAR 0x4E

// Misc commands
#define MO_SETCONTRAST 0x50
#define MO_BACKLIGHTON 0x42
#define MO_BACKLIGHTOFF 0x46
#define MO_GPIOOFF 0x56
#define MO_GPIOON 0x57

class MatrixOrbitali2c : public Print {
public:
  MatrixOrbitali2c(uint8_t i2cport);

  void init(uint8_t port);
  void begin(uint8_t cols, uint8_t rows);

  void clear();
  void home();

  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void autoScroll();
  void noAutoScroll();
  void lineWrap();
  void noLineWrap();
  void cursorLeft();
  void cursorRight();
  void initNarrowVertical();
  void initWideVertical();
  void initHorizontal();
  void drawVertical(uint8_t, uint8_t);
  void drawHorizontal(uint8_t, uint8_t, uint8_t, uint8_t);
  void initLargeDigits();
  void placeLargeDigit(uint8_t, uint8_t);
  void setContrast(uint8_t);
  void gpioOff();
  void gpioOn();
  void backlightOff();
  void backlightOn();
  void backlightOn(uint8_t);

  void createChar(uint8_t, uint8_t[]);
  void setCursor(uint8_t, uint8_t);
  virtual size_t write(uint8_t);
  virtual size_t write(const char *str);
//  virtual void write(const uint8_t *buffer, size_t size);
//  void print(const String &);

private:

  uint8_t _i2cport;
};
#endif
