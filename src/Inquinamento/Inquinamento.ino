/*
  Inquinamento.cpp - La classe Inquinamento descrive il funzionamento del sensore della Inquinamento..
  Created by Matteo Calò, Davide Pastore and Alessandro Pendinelli on June 25, 2013.
  Released into the public domain.
 */

#include "Arduino.h"
#include "Inquinamento.h"

/**
 * Normalizza la Inquinamento letta dal sensore in modo da essere gestita in modo opportuno
 * @param Inquinamento legge il dato misurato dal sensore
 */
int Inquinamento::normalizza(int inquinamento){
	// @TODO si deve normalizzare la Inquinamento prima di settarla
}

/**
 * Il metodo costruttore inizializza il pin secondo il parametro
 * e la Inquinamento chiamando la funzione readInquinamento()
 * @param pin il piedino dove è inserito il sensore di Inquinamento */
Inquinamento::Inquinamento(int pin){
	Inquinamento::pin = pin;
	readInquinamento();
}

/**
 * Restituisce la Inquinamento * @return restituisce la Inquinamento */
int Inquinamento::getInquinamento(){
	return inquinamento;
}

/**
 * Restituisce il pin
 * @return restituisce il pin
 */
int Inquinamento::getPin(){
	return pin;
}

/**
 * Legge la Inquinamento e la normalizza, settando l'attributo Inquinamento */
void Inquinamento::readInquinamento(){
	// @TODO implementare il metodo 
}

/**
 * Setta il piedino su cui è posizionato il sensore di Inquinamento */
void Inquinamento::setPin(int pin){
	pin = pin;
}
