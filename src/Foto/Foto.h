/*
  Foto.h - Library for read temperature from a DHT11.
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */
#ifndef Foto_h
#define Foto_h

#include "Arduino.h"


class Foto{
private:
	int foto;
	int pin;
	int normalizza(int foto);

public:


	Foto(int pin);
	int getFoto();
	int getPin();
	void readFoto();
	void setPin(int pin);
};

#endif
