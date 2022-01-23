#ifndef lcd_h
#define lcd_h
#include "Arduino.h"


//prueba de ramas
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
void lcd_cmd (char cmd);

  
};

#endif
