/*
  GPS.cpp - La classe GPS descrive il funzionamento del sensore della GPS..
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */

#include "Arduino.h"
#include "GPS.h"

/**
 * Normalizza la GPS letta dal sensore in modo da essere gestita in modo opportuno
 * @param GPS legge il dato misurato dal sensore
 */
int GPS::normalizza(int gps){
	// @TODO si deve normalizzare la GPS prima di settarla
}

/**
 * Il metodo costruttore inizializza il pin secondo il parametro
 * e la GPS chiamando la funzione readGPS()
 * @param pin il piedino dove è inserito il sensore di GPS */
GPS::GPS(int pin){
	GPS::pin = pin;
	readGPS();
}

/**
 * Restituisce la GPS * @return restituisce la GPS */
int GPS::getGPS(){
	return gps;
}

/**
 * Restituisce il pin
 * @return restituisce il pin
 */
int GPS::getPin(){
	return pin;
}

/**
 * Legge la GPS e la normalizza, settando l'attributo GPS */
void GPS::readGPS(){
	// @TODO implementare il metodo 
}

/**
 * Setta il piedino su cui è posizionato il sensore di GPS */
void GPS::setPin(int pin){
	pin = pin;
}
