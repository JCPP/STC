/**
* La classe Vento descrive il funzionamento del sensore del vento.
*/

class Vento{
  private:
    int vento;
    int pin;
    
    /**
    * Normalizza la vento letta dal sensore in modo da essere gestita in modo opportuno
    * @param vento legge il dato misurato dal sensore
    */
    int normalizza(int vento){
    	//@TODO si deve normalizzare il vento prima di settarla
    }
  

  public:
  
    /**
    * Il metodo costruttore inizializza il pin secondo il parametro
    * e la vento chiamando la funzione readVento()
    * @param pin il piedino dove è inserito il sensore di vento
    */
    Vento(int pin){
    	this->pin = pin;
    	readVento();
    }
    
    /**
    * Restituisce la vento
    * @return restituisce la vento
    */
    int getVento(){
    	return vento;
    }
    
    /**
    * Restituisce il pin
    * @return restituisce il pin
    */
    int getPin(){
    	return pin;
    }
    
    /**
    * Legge la vento e la normalizza, settando l'attributo vento
    */
    void readVento(){
    	vento = normalizza(analogRead(pin));
    }
    
    /**
    * Setta il piedino su cui è posizionato il sensore di vento
    */
    void setPin(int pin){
    	this->pin = pin;
    }
   
};
