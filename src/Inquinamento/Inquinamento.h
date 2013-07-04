/*
  Inquinamento.h - Library for read temperature from a DHT11.
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */
#ifndef Inquinamento_h
#define Inquinamento_h

#include "Arduino.h"


class Inquinamento{
private:
	int inquinamento;
	int pin;
	int normalizza(int inquinamento);

public:


	Inquinamento(int pin);
	int getInquinamento();
	int getPin();
	void readInquinamento();
	void setPin(int pin);
};

#endif
