
//Flapy PACMAN GAME
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,20,4); 

int value=8;
volatile int jump=1;
volatile bool shoot=false;
int image=0;
int score=0;
int air=0;
volatile bool arriba=true;
bool loser=true;

byte pacman[8]=
{
B00000,
B01110,
B10101,
B10010,
B10100,
B10010,
B01001,
B00110, 
  };
byte eat[8]=
{
B00000,
B01110,
B10101,
B10001,
B10111,
B10001,
B01001,
B00110, 
  };
byte Ghost[8]=
{
 B00000,
B01110,
B10001,
B11011,
B10101,
B10001,
B01010,
B10101,  
  };
byte Ghost1[8]=
{
 B00000,
B01110,
B10001,
B11011,
B10101,
B10001,
B10101,
B01010,  
  };  







void setup() {
  // put your setup code here, to run once:
Wire.begin();
Wire.beginTransmission(0x27);
lcd.begin(16, 2); // initialize the lcd
lcd.setBacklight(255);
lcd.createChar (0,pacman);
lcd.createChar(1,eat);
lcd.createChar(2,Ghost);
lcd.createChar(3,Ghost1);

lcd.home();
lcd.clear();

pinMode(2,INPUT_PULLUP);

attachInterrupt(digitalPinToInterrupt(2), salida, FALLING);

  lcd.setCursor(5,0);
  lcd.print(" Score:"); 



}


void dibujar(int k, int i)
{
lcd.setCursor(0,1);
lcd.print("             ");
lcd.setCursor(1,0);
lcd.print("     "); 
lcd.setCursor(1,jump);
lcd.write (byte (k));
lcd.setCursor(i,1);
lcd.write (byte (k+2));
  
  
  
  }
void avoid()
{
  jump=(jump+1)%2;
  
  
  }

void show()
{
  if (value<0 && loser)
{
  value=8;
  score=(score+1)%100;
  lcd.setCursor(13,0);
  lcd.print(score);
  
  

  
  
  }
  
  
  }

void retar(int time1)
{
  int t=millis();

  while(millis()-t<time1)
  {
    
    
    }
  
  
  
  }

void condition()
{
  if (jump==1 && value==1)
{
  lcd.setCursor(1,0);
  lcd.print(" you Lose    "); 
  loser=false;
  }

  
  
  }

void loop() {


if(loser)
{
  // put your main code here, to run repeatedly:
retar(500);
value=(value-1)%8;
dibujar(image,value);
image=(image+1)%2;
show();
condition();
if (!arriba)
{
++air;
}
if(air>2)
{
  jump=1;
  air=0;
  arriba=true;
  dibujar(image,value);
  }


}



}

void salida()
{

  if (arriba)
  {
  jump=(jump+1)%2;
  arriba=false;
  }
  
  
  }
