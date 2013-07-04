/*
  Pressione.h - Library for read temperature from a DHT11.
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */
#ifndef Pressione_h
#define Pressione_h

#include "Arduino.h"


class Pressione{
private:
	int pressione;
	int pin;
	int normalizza(int pressione);

public:


	Pressione(int pin);
	int getPressione();
	int getPin();
	void readPressione();
	void setPin(int pin);
};

#endif
