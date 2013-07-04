/*
  Umidita.h - Library for read temperature from a DHT11.
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */
#ifndef Umidita_h
#define Umidita_h

#include "Arduino.h"


class Umidita{
private:
	int umidita;
	int pin;
	int normalizza(int umidita);

public:


	Umidita(int pin);
	int getUmidita();
	int getPin();
	void readUmidita();
	void setPin(int pin);
};

#endif
