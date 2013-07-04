/*
  Pressione.cpp - La classe Pressione descrive il funzionamento del sensore della Pressione..
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */

#include "Arduino.h"
#include "Pressione.h"

/**
 * Normalizza la Pressione letta dal sensore in modo da essere gestita in modo opportuno
 * @param Pressione legge il dato misurato dal sensore
 */
int Pressione::normalizza(int pressione){
	// @TODO si deve normalizzare la Pressione prima di settarla
}

/**
 * Il metodo costruttore inizializza il pin secondo il parametro
 * e la Pressione chiamando la funzione readPressione()
 * @param pin il piedino dove è inserito il sensore di Pressione */
Pressione::Pressione(int pin){
	Pressione::pin = pin;
	readPressione();
}

/**
 * Restituisce la Pressione * @return restituisce la Pressione */
int Pressione::getPressione(){
	return pressione;
}

/**
 * Restituisce il pin
 * @return restituisce il pin
 */
int Pressione::getPin(){
	return pin;
}

/**
 * Legge la Pressione e la normalizza, settando l'attributo Pressione */
void Pressione::readPressione(){
	// @TODO implementare il metodo 
}

/**
 * Setta il piedino su cui è posizionato il sensore di Pressione */
void Pressione::setPin(int pin){
	pin = pin;
}
