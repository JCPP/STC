/*
  Foto.cpp - La classe Foto descrive il funzionamento del sensore della Foto..
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */

#include "Arduino.h"
#include "Foto.h"

/**
 * Normalizza la Foto letta dal sensore in modo da essere gestita in modo opportuno
 * @param Foto legge il dato misurato dal sensore
 */
int Foto::normalizza(int foto){
	// @TODO si deve normalizzare la Foto prima di settarla
}

/**
 * Il metodo costruttore inizializza il pin secondo il parametro
 * e la Foto chiamando la funzione readFoto()
 * @param pin il piedino dove è inserito il sensore di Foto */
Foto::Foto(int pin){
	Foto::pin = pin;
	readFoto();
}

/**
 * Restituisce la Foto * @return restituisce la Foto */
int Foto::getFoto(){
	return foto;
}

/**
 * Restituisce il pin
 * @return restituisce il pin
 */
int Foto::getPin(){
	return pin;
}

/**
 * Legge la Foto e la normalizza, settando l'attributo Foto */
void Foto::readFoto(){
	// @TODO implementare il metodo 
}

/**
 * Setta il piedino su cui è posizionato il sensore di Foto */
void Foto::setPin(int pin){
	pin = pin;
}
