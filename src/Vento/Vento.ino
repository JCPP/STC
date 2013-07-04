/*
  Vento.cpp - La classe Vento descrive il funzionamento del sensore della Vento..
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */

#include "Arduino.h"
#include "Vento.h"

/**
 * Normalizza la Vento letta dal sensore in modo da essere gestita in modo opportuno
 * @param Vento legge il dato misurato dal sensore
 */
int Vento::normalizza(int vento){
	// @TODO si deve normalizzare la Vento prima di settarla
}

/**
 * Il metodo costruttore inizializza il pin secondo il parametro
 * e la Vento chiamando la funzione readVento()
 * @param pin il piedino dove è inserito il sensore di Vento */
Vento::Vento(int pin){
	Vento::pin = pin;
	readVento();
}

/**
 * Restituisce la Vento * @return restituisce la Vento */
int Vento::getVento(){
	return vento;
}

/**
 * Restituisce il pin
 * @return restituisce il pin
 */
int Vento::getPin(){
	return pin;
}

/**
 * Legge la Vento e la normalizza, settando l'attributo Vento */
void Vento::readVento(){
	// @TODO implementare il metodo 
}

/**
 * Setta il piedino su cui è posizionato il sensore di Vento */
void Vento::setPin(int pin){
	pin = pin;
}
