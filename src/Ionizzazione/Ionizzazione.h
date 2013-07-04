/*
  Ionizzazione.h - Library for read temperature from a DHT11.
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */
#ifndef Ionizzazione_h
#define Ionizzazione_h

#include "Arduino.h"


class Ionizzazione{
private:
	int ionizzazione;
	int pin;
	int normalizza(int ionizzazione);

public:


	Ionizzazione(int pin);
	int getIonizzazione();
	int getPin();
	void readIonizzazione();
	void setPin(int pin);
};

#endif
