/*
  Temperatura.cpp - La classe Temperatura descrive il funzionamento del sensore della temperatura..
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */

#include "Arduino.h"
#include "Temperatura.h"
#include <dht.h>

/**
 * Normalizza la temperatura letta dal sensore in modo da essere gestita in modo opportuno
 * @param temperatura legge il dato misurato dal sensore
 */
int Temperatura::normalizza(int temperatura){
	// @TODO si deve normalizzare la temperatura prima di settarla
}

/**
 * Il metodo costruttore inizializza il pin secondo il parametro
 * e la temperatura chiamando la funzione readTemperatura()
 * @param pin il piedino dove è inserito il sensore di temperatura
 */
Temperatura::Temperatura(int pin){
	Temperatura::pin = pin;
	readTemperatura();
}

/**
 * Restituisce la temperatura
 * @return restituisce la temperatura
 */
int Temperatura::getTemperatura(){
	return temperatura;
}

/**
 * Restituisce il pin
 * @return restituisce il pin
 */
int Temperatura::getPin(){
	return pin;
}

/**
 * Legge la temperatura e la normalizza, settando l'attributo temperatura
 */
void Temperatura::readTemperatura(){
	DHT.read11(pin);
	temperatura = DHT.temperature;

	//temperatura = normalizza(analogRead(pin));
}

/**
 * Setta il piedino su cui è posizionato il sensore di temperatura
 */
void Temperatura::setPin(int pin){
	pin = pin;
}
