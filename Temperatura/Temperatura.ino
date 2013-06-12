/**
*La classe Temperatura descrive il funzionamento del sensore della temperatura.
*/

class Temperatura{
  private:
    int temperatura;
    int pin;
    
    /**
    *Normalizza la temperatura letta dal sensore in modo da essere gestita in modo opportuno
    *@param temperatura legge il dato misurato dal sensore
    */
    int normalizza(int temperatura){
      //@TODO si deve normalizzare la temperatura prima di settarla
    }

  public:
  
    /**
    *Il metodo costruttore inizializza il pin secondo il parametro
    *e la temperatura chiamando la funzione readTemperatura()
    *@param pin il piedino dove è inserito il sensore di temperatura
    */
    Temperatura(int pin){
      this->pin = pin;
      readTemperatura();
    }
    
    /**
    *Restituisce la temperatura
    *@return restituisce la temperatura
    */
    int getTemperatura(){
      return temperatura;
    }
    
    /**
    *Restituisce il pin
    *@return restituisce il pin
    */
    int getPin(){
      return pin;
    }
    
    /**
    *Legge la temperatura e la normalizza, settando l'attributo temperatura
    */
    void readTemperatura(){
      temperatura = normalizza(analogRead(pin));
    }
    
    /**
    *Setta il piedino su cui è posizionato il sensore di temperatura
    */
    void setPin(int pin){
    	this->pin = pin;
    }
    
    
};
