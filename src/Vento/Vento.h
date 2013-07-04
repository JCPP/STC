/*
  Vento.h - Library for read temperature from a DHT11.
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */
#ifndef Vento_h
#define Vento_h

#include "Arduino.h"


class Vento{
private:
	int vento;
	int pin;
	int normalizza(int vento);

public:


	Vento(int pin);
	int getVento();
	int getPin();
	void readVento();
	void setPin(int pin);
};

#endif
