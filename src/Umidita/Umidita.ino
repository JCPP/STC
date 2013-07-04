/*
  Umidita.cpp - La classe Umidita descrive il funzionamento del sensore della Umidita..
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */

#include "Arduino.h"
#include "Umidita.h"

/**
 * Normalizza la Umidita letta dal sensore in modo da essere gestita in modo opportuno
 * @param Umidita legge il dato misurato dal sensore
 */
int Umidita::normalizza(int umidita){
	// @TODO si deve normalizzare la Umidita prima di settarla
}

/**
 * Il metodo costruttore inizializza il pin secondo il parametro
 * e la Umidita chiamando la funzione readUmidita()
 * @param pin il piedino dove è inserito il sensore di Umidita */
Umidita::Umidita(int pin){
	Umidita::pin = pin;
	readUmidita();
}

/**
 * Restituisce la Umidita * @return restituisce la Umidita */
int Umidita::getUmidita(){
	return umidita;
}

/**
 * Restituisce il pin
 * @return restituisce il pin
 */
int Umidita::getPin(){
	return pin;
}

/**
 * Legge la Umidita e la normalizza, settando l'attributo Umidita */
void Umidita::readUmidita(){
	// @TODO implementare il metodo 
}

/**
 * Setta il piedino su cui è posizionato il sensore di Umidita */
void Umidita::setPin(int pin){
	pin = pin;
}
