#ifndef lcd_h
#define lcd_h
#include "Arduino.h"

Class LCD
{
public:
LCD(int row,int column, int adress);
void lcdinit();
void lcdcreatechar();
void clear();
void setcursor(int x,int y);
void writetetx( char lista []);
void writei2c(byte value);
void lcdreset();

  
};

#endif
