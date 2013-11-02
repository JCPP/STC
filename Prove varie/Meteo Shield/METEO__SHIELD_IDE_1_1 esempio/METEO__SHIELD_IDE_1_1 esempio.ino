//CODE MADE BY VINCENZO MENDOLA USING THE SAME RTC LIBRARY AND RTC CODE MADE BY FUTURA ELETTRONICA//

// LIBRARIES

#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>

// LCD PINS 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

RTC_DS1307 RTC;

// VARIABLES DEFINITION AND INITIALIZATION

#define TEMP 2      //TEMPERATURE ACQUISITION ON ANALOG PIN 2
#define UMID 1      //HUMIDITY ACQUISITION ON ANALOG PIN 1
#define PRESS 0     //PRESSURE ACQUISITION ON ANALOG PIN 0
float val = 0.0;
float T= 0.0;
double umidita = 0.0;
double RH = 0.0;
double RHout = 0.0;
double UM = 0.0;
double Pascal=0.0;
double PS=0.0;
double P=0.0;
float VADC= 5;
int DPR = 0;
int RHCORR = 0;
int PCORR = 0;
int TCORR= 0;
double STAMPA_T = 0;
double STAMPA_U = 0;
double STAMPA_P = 0 ;
byte degree[8] = { //  CHARACTER "°C" DEFINITION
  B10111,
  B01000,
  B10000,
  B10000,
  B10000,
  B01000,
  B00111,
};

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.createChar(0, degree); // "°C" SYMBOL
  Wire.begin();
  RTC.begin();
  RTC.sqw(1);		//0 Led off - 1 Freq 1Hz - 2 Freq 4096kHz - 3 Freq 8192kHz - 4 Freq 32768kHz

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}  

void loop() {

  // RTC LCD OUTPUT

  DateTime now = RTC.now();
  lcd.setCursor(0, 1);
  if (now.hour() < 10) {
    lcd.print("0");
  }
  lcd.print(now.hour(),DEC);    // HOUR
  lcd.print(":");
  if (now.minute() < 10) {      
    lcd.print("0");
  }
  lcd.print(now.minute(), DEC);// MINUTES

  lcd.setCursor(6, 1);
  if (now.day() < 10) {        
    lcd.print("0");
  }
  lcd.print(now.day(), DEC);  // DAY
  lcd.print('-');
  if (now.month ()<10) {       
    lcd.print("0");
  }
  lcd.print(now.month(), DEC);//MONTH
  lcd.print('-');
  lcd.print(now.year(), DEC);  //YEAR


  // SERIAL RTC OUPUT

  if (now.hour() < 10) {
    Serial.print("0");
  }
  Serial.print(now.hour(),DEC);    
  Serial.print(":");
  if (now.minute() < 10) {
    Serial.print("0");
  }
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  if (now.second() < 10) {
    Serial.print("0");
  }
  Serial.print(now.second(), DEC);
  Serial.print("; ");

  if (now.day() < 10) {
    Serial.print("0");
  }
  Serial.print(now.day(), DEC);
  Serial.print('-');
  if (now.month ()<10) {
    Serial.print("0");
  }
  Serial.print(now.month(), DEC);
  Serial.print('-');
  Serial.println(now.year(), DEC);

  Serial.println();

  // SERIAL METEO OUTPUT

  STAMPA_T= (temp()); 
  STAMPA_U= (readUMID());
  STAMPA_P = (pressure());


  Serial.print("TEMPERATURA ");
  Serial.print(STAMPA_T);
  Serial.write(176);
  Serial.print("C; ");

  Serial.print("UMIDITA' ");
  Serial.print(STAMPA_U);
  Serial.print("%; ");

  Serial.print("PRESSIONE ");
  Serial.print(STAMPA_P);
  Serial.println("mbar");

  // LCD METEO OUTPUT

  lcd.setCursor(0, 0);   
  lcd.print(STAMPA_T,1); //SHOW ONLY THE FIRST DECIMAL
  lcd.write((uint8_t)0); //PRINT "°C" CHARACTER (IDE 1.0.1)
  delay(200);

  lcd.setCursor(6, 0);
  lcd.print(STAMPA_U,1);//SHOW ONLY THE FIRST DECIMAL
  lcd.setCursor(10,0);
  lcd.print("%");
  delay(200);

  lcd.setCursor(12, 0);
  lcd.print(STAMPA_P,0);//SHOW ONLY THE INTEGER PART
  delay(200);
}


float temp() {
  double nread = 100.0;          // NUMBER OF READINGS
  double somma = 0.0; 
  for (int i=0; i<nread; i++)
  {
    val = analogRead(TEMP);
    T = (((VADC/1024.0*val)-0.5)* 100)+TCORR;   //TEMPERATURE 
    somma += T;
  }
  delay(100);
  return (somma/nread);
}

double readUMID(){
  double nread = 100.0;          // NUMBER OF READINGS 
  double somma = 0.0; 
  for (int i=0; i<nread; i++)
  {
    UM = analogRead( UMID );              
    RHout=(((UM*VADC/1024.0/3.3)-0.1515)/0.00636)+RHCORR;    //HUMIDITY
    somma += RHout;       
  }
  delay(100);
  return  ( somma / nread );
}

float pressure(){
  double nread = 100.0;           // NUMBER OF READINGS 
  double somma = 0.0; 
  for (int i=0; i<nread; i++)
  {
    Pascal=analogRead(PRESS);
    P=(((Pascal*VADC/1024)/VADC+0.095)/0.009)*10+DPR+PCORR;  //PRESSURE TRANSFERT FUNCTION
    somma += P;
  }
  delay(100);
  return  ( somma / nread ); 
}















