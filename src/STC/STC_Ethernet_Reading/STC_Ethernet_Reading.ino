//CODE MADE BY VINCENZO MENDOLA USING THE SAME RTC LIBRARY AND RTC CODE MADE BY FUTURA ELETTRONICA//

// LIBRARIES
#include <LiquidCrystal.h>
#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0x90, 0xA2, 0xDA, 0xDE, 0xB2, 0x12 };
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
char server[] = "192.168.1.3";    // name address for Google (using DNS)

// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192,168,1,4);

// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;
// LCD PINS 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



// VARIABLES DEFINITION AND INITIALIZATION

#define TEMP 2      //TEMPERATURE ACQUISITION ON ANALOG PIN 2
#define UMID 1      //HUMIDITY ACQUISITION ON ANALOG PIN 1
#define PRESS 0     //PRESSURE ACQUISITION ON ANALOG PIN 0

/* Work around a bug with PROGMEM and PSTR where the compiler always
 * generates warnings.
 */
#undef PROGMEM 
#define PROGMEM __attribute__(( section(".progmem.data") )) 
#undef PSTR 
#define PSTR(s) (__extension__({static prog_char __c[] PROGMEM = (s); &__c[0];}))


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
int sendDelay = 10000; //Number of milliseconds

void setup() {
  Serial.begin(9600);
  
    lcd.begin(16,2);
    lcd.createChar(0, degree); // "°C" SYMBOL
  
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println(F("Failed to configure Ethernet using DHCP"));
    // no point in carrying on, so do nothing forevermore:
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.println(F("connecting..."));

  
  connectToServer();
}  

void loop() {
  
  // LCD METEO OUTPUT

  lcd.setCursor(0, 0);   
  lcd.print(STAMPA_T,1); //SHOW ONLY THE FIRST DECIMAL
  lcd.write((uint8_t)0); //PRINT "°C" CHARACTER (IDE 1.0.1)
  //delay(200);

  lcd.setCursor(6, 0);
  lcd.print(STAMPA_U,1);//SHOW ONLY THE FIRST DECIMAL
  lcd.setCursor(10,0);
  lcd.print("%");
  //delay(200);

  lcd.setCursor(12, 0);
  lcd.print(STAMPA_P,0);//SHOW ONLY THE INTEGER PART
  //delay(200);
  
  // SERIAL METEO OUTPUT

  STAMPA_T = (temp()); 
  STAMPA_U = (readUMID());
  STAMPA_P = (pressure());
  
  String stringT = doubleToString(STAMPA_T,2);
  String stringU = doubleToString(STAMPA_U,2);
  String stringP = doubleToString(STAMPA_P,2);

  /*
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
  */
  
  //If connection is dead try to reconnect
  if(!client.connected()){
    connectToServer();
  }
  else{
    sendData(stringT, stringU, stringP);
    
    //Waiting until the server is connected
    while(client.connected()){
      while (client.available()) {
        char c = client.read();
        Serial.print(c);
      }
    }
    
    
    client.stop();

    delay(sendDelay);
  }
}


float temp() {
  double nread = 100.0;          // NUMBER OF READINGS
  double somma = 0.0; 
  for (int i=0; i<nread; i++)
  {
    val = analogRead(TEMP);
    T = (val-32)/1.8;  //TEMPERATURE  
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



//Rounds down (via intermediary integer conversion truncation)
String doubleToString(double input, int decimalPlaces){
    if(decimalPlaces!=0){
      String string = String((int)(input*pow(10,decimalPlaces)));
      if(abs(input)<1){
        if(input>0)
          string = "0"+string;
        else if(input<0)
          string = string.substring(0,1)+"0"+string.substring(1);
      }
      return string.substring(0,string.length()-decimalPlaces)+"."+string.substring(string.length()-decimalPlaces);
    }
    else {
      return String((int)input);
    }
}

//Send data of sensors
void sendData(String temperatura, String umidita, String pressione){
  Serial.println(F("Sending data to the server..."));
  
  String postData = "t=" + temperatura + "&u=" + umidita + "&p=" + pressione;
  
  //DATA TRANSMISSION
  client.println(F("POST /ricevi HTTP/1.1"));
  client.println(F("Host: 192.168.1.3")); //Change this to the server address
  client.println(F("Content-Type: application/x-www-form-urlencoded"));
  client.println(F("User-Agent: Arduino/1.0"));
  client.println(F("Connection: close"));
  client.print(F("Content-Length:"));
  client.println(postData.length());
  
  client.println();
  client.print(postData);
  client.println();
  
  //Serial.println(postData.length());
  Serial.println(postData);
}


//Connect to server
void connectToServer(){
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connected");
  } 
  else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed..reconnecting");
    client.stop();
  }
}



