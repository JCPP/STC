/**
*La classe Ionizzazione descrive il funzionamento del sensore della ionizzazione.
*/

class Ionizzazione{
  private:
    int ionizzazione;
    int pin;
    
    /**
    * Normalizza la ionizzazione letta dal sensore in modo da essere gestita in modo opportuno
    * @param ionizzazione legge il dato misurato dal sensore
    */
    int normalizza(int ionizzazione){
    	//@TODO si deve normalizzare la ionizzazione prima di settarla
    }
  

  public:
  
    /**
    * Il metodo costruttore inizializza il pin secondo il parametro
    * e la ionizzazione chiamando la funzione readIonizzazione()
    * @param pin il piedino dove è inserito il sensore di ionizzazione
    */
    Ionizzazione(int pin){
    	this->pin = pin;
    	readIonizzazione();
    }
    
    /**
    * Restituisce la ionizzazione
    * @return restituisce la ionizzazione
    */
    int getIonizzazione(){
    	return ionizzazione;
    }
    
    /**
    * Restituisce il pin
    * @return restituisce il pin
    */
    int getPin(){
    	return pin;
    }
    
    /**
    * Legge la ionizzazione e la normalizza, settando l'attributo ionizzazione
    */
    void readIonizzazione(){
    	ionizzazione = normalizza(analogRead(pin));
    }
    
    /**
    * Setta il piedino su cui Ã¨ posizionato il sensore di ionizzazione
    */
    void setPin(int pin){
    	this->pin = pin;
    }
   
};
