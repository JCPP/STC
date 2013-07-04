/*
  Temperatura.h - Library for read temperature from a DHT11.
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
*/
#ifndef Temperatura_h
#define Temperatura_h

#include "Arduino.h"
#include <dht.h>


class Temperatura{
  private:
    int temperatura;
    int pin;
    dht DHT;
    int normalizza(int temperatura);

  public:

  
    Temperatura(int pin);
    int getTemperatura();
    int getPin();
    void readTemperatura();
    void setPin(int pin);
};

#endif
