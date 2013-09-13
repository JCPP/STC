
#ifndef Communication_h
#define Communication_h

#include "Arduino.h"
#include <WiFlyHQ.h>
#include <SoftwareSerial.h>

/* Work around a bug with PROGMEM and PSTR where the compiler always
 * generates warnings.
 */
#undef PROGMEM 
#define PROGMEM __attribute__(( section(".progmem.data") )) 
#undef PSTR 
#define PSTR(s) (__extension__({static prog_char __c[] PROGMEM = (s); &__c[0];})) 

/* Site addresses */
const String loginAddress = "";
const String updateAddress = "";

/* For debug purpose */
const boolean debug = false;

class Communication
{
  public:
	Communication();
	
	/* Set functions */
	void setWiFly(WiFly wifly);
	void setSite(char site[]);
	void setLoginTimeout(int millis);
	
	/* Get functions */
	boolean isLoginDone();
	
	boolean login(String parametri[][2],int size);
	boolean update(String parametri[][2],int size);
	void readFromServer();
  private:
	/* Site address */
	char *_site;
	
	/* Login done */
	boolean loginDone;
	
	/* Login timeout in milliseconds */
	int loginTimeout;
	
	WiFly _wifly;
	
	void sendPostRequest(String address, String parameters[][2], int size);
};

#endif
