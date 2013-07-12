/*
  GPS.h - Library for read temperature from a DHT11.
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */
#ifndef GPS_h
#define GPS_h

#include "Arduino.h"
#include <gps.h>
#include <GSM.h>

class GPS{
	private:
		GPSGSM gps;
		GSM gsm;
		int pin;
		int normalizza(int gps);

	public:
		GPS(int pin);
		int getGPS();
		int getPin();
		void readGPS();
		void setPin(int pin);
};

#endif