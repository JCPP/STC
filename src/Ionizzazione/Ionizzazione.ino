/*
  Ionizzazione.cpp - La classe Ionizzazione descrive il funzionamento del sensore della Ionizzazione..
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */

#include "Arduino.h"
#include "Ionizzazione.h"

/**
 * Normalizza la Ionizzazione letta dal sensore in modo da essere gestita in modo opportuno
 * @param Ionizzazione legge il dato misurato dal sensore
 */
int Ionizzazione::normalizza(int ionizzazione){
	// @TODO si deve normalizzare la Ionizzazione prima di settarla
}

/**
 * Il metodo costruttore inizializza il pin secondo il parametro
 * e la Ionizzazione chiamando la funzione readIonizzazione()
 * @param pin il piedino dove è inserito il sensore di Ionizzazione */
Ionizzazione::Ionizzazione(int pin){
	Ionizzazione::pin = pin;
	readIonizzazione();
}

/**
 * Restituisce la Ionizzazione * @return restituisce la Ionizzazione */
int Ionizzazione::getIonizzazione(){
	return ionizzazione;
}

/**
 * Restituisce il pin
 * @return restituisce il pin
 */
int Ionizzazione::getPin(){
	return pin;
}

/**
 * Legge la Ionizzazione e la normalizza, settando l'attributo Ionizzazione */
void Ionizzazione::readIonizzazione(){
	// @TODO implementare il metodo 
}

/**
 * Setta il piedino su cui è posizionato il sensore di Ionizzazione */
void Ionizzazione::setPin(int pin){
	pin = pin;
}
