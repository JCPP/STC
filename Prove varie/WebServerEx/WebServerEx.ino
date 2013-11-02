/*
  Web Server
 
 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)
 
 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 
 */

#include <SPI.h>
#include <Ethernet.h>

#define fotoresistenza A0
#define led 8
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 
  0x90, 0xA2, 0xDA, 0x00, 0x73, 0x80 };
IPAddress ip(192,168,0,253);

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup() {
   //pinMode(fotoresistenza,INPUT);
   pinMode(led,OUTPUT);
   // Open serial communications and wait for port to open:
   Serial.begin(9600);
   while (!Serial) {
     ; // wait for serial port to connect. Needed for Leonardo only
   }


   // start the Ethernet connection and the server:
   Ethernet.begin(mac, ip);
   server.begin();
   Serial.print("server is at ");
   Serial.println(Ethernet.localIP());
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          stampa(client);
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}


void stampa(EthernetClient client){
    // send a standard http response header
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");  // the connection will be closed after completion of the response
    client.println("Refresh: 5");  // refresh the page automatically every 5 sec
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html xmlns='http://www.w3.org/1999/xhtml' dir='ltr' lang='en'>");
    client.println("<head>");
    client.println("<meta http-equiv='content-type' content='text/html; charset=iso-8859-1'/>");
    client.println("<title>Lettura analogica</title>");
    client.println("</head>");
    client.println("<body>");
    client.println("<h1 style='text-aling:center'>Lettura analogica</h1>");
    // output the value of an analog input
    int analogChannel = fotoresistenza;
    int sensorReading = analogRead(analogChannel);
    Serial.println(sensorReading, DEC); // Scrivo il valore della fotoresistenza, espresso in numeri decimali
         
    if(sensorReading<500) //se il valore letto dalla fotoresistenza (luminosit&agrave;) &egrave; basso, accendo il led
       digitalWrite(led, HIGH);
    else
       digitalWrite(led, LOW); //altrimenti lo spengo (o lo lascio spento)
          
    client.print("Lettura fotoresistenza [");
    client.print(analogChannel);
    client.print("]: ");
    client.print(sensorReading);
    client.print("<br />Il led è : ");
    client.print(digitalRead(led));
    client.println("</body>");
    client.println("</html>"); 
}
