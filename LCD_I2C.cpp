#include "Arduino.h"
#include "LCD_I2C.h"
#include <Wire.h>

#define LCD_EN      0x80
LCD::LCD(int row,int column, int adress)
{
  _row=row;
  _column=column;
  _adress=adress;
  }
void LCD::lcdinit()
{

  delay(20);
  writei2c(0x30);
  delay(10);
  writei2c(0x30);
  delay(1);
  writei2c(0x30);
  delay(1);
  writei2c(0x20);
  delay(1);
  
  
 }
void LCD::lcdreset()
{
  writei2c(0xFF);
  delay(20);
  writei2c(0x03+LCD_EN);
  writei2c(0x03);
  delay(10);
  writei2c(0x03+LCD_EN);
  writei2c(0x03);
  delay(1);
  writei2c(0x02+LCD_EN);
  writei2c(0x02);
  delay(1);
  }

 
void LCD::writetext(char lista [])
{
  
  
  
  
  }
void LCD::writei2c(byte value)
{
  Wire.beginTransmission(_adress);
  Wire.write(value);
  Wire.endTransmission();  
  }
  
