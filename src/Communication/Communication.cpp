#include "Arduino.h"
#include "Communication.h"
#include <WiFlyHQ.h>
#include <SoftwareSerial.h>

Communication::Communication()
{
	setSite("");
	loginDone = false;
	loginTimeout = 5000;
}



/* SET functions */

/* Set the login timeout*/
void Communication::setLoginTimeout(int millis){
	loginTimeout = millis;
}

/* Set the site */
void Communication::setSite(char *site){
	_site = site;
}

/* Set the wifly object */
void Communication::setWiFly(WiFly wifly){
	_wifly = wifly;
}



/* GET functions */

/* The login is done? */
boolean Communication::isLoginDone(){
	return loginDone;
}



/* Other functions */

/* Login into STC */
boolean Communication::login(String parametri[][2], int size){
    if (_wifly.open(_site, 80)) {
		if(debug)
		{
			Serial.print(F("Connected to "));
			Serial.println(_site);
		}
        sendPostRequest(loginAddress, parametri, size);
    } else {
		if(debug)
		{
			Serial.println(F("Failed to connect"));
		}
        return false;
    }
	//int lettura = _wifly.read();
	if(_wifly.match(F("login=true"), loginTimeout)){
		loginDone = true;
		return true;
	}
	return false;
}

/* Read from the server */
void Communication::readFromServer(){
    if (_wifly.available() > 0) {
		char ch = _wifly.read();
		Serial.write(ch);
		if (ch == '\n') {
			/* add a carriage return */ 
			Serial.write('\r');
		}
    }
}

boolean Communication::update(String parametri[][2], int size){
  if (_wifly.open(_site, 80)) {
		if(debug)
		{
			Serial.print(F("Connected to "));
			Serial.println(_site);
		}
        sendPostRequest(updateAddress, parametri, size);
    } else {
		if(debug)
		{
			Serial.println(F("Failed to connect"));
		}
        return false;
    }
    return true;
}
/**
  Send a post request
  @address the address
  @parameters the parameters to send
*/
void Communication::sendPostRequest(String address, String parameters[][2], int size){
  if(debug)
  {
	Serial.println("Sizeof Parameters: " + String(size));
  }
  String parametri = "";
  for(int i = 0; i < size; i++){
    parametri += parameters[i][0] + "=" + parameters[i][1];
	if(debug)
	{
		Serial.println(parameters[i][0] + "=" + parameters[i][1]);
	}
    if(i < size - 1){
      parametri += "&";
    }
  }
  
  Serial.println(parametri);
  
  /* Send the request */
  _wifly.println("POST "+ address +" HTTP/1.1");
  _wifly.print(F("Host: "));
  _wifly.println(_site);
  _wifly.println(F("User-Agent: Arduino/1.0"));
  _wifly.println(F("Connection: close"));
  _wifly.print("Content-Length: ");
  _wifly.println(parametri.length());
  _wifly.println(F("Content-Type: application/x-www-form-urlencoded"));

  _wifly.println();
        
  _wifly.print(parametri);
  _wifly.println();
}
