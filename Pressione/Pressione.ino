/**
*La classe Pressione descrive il funzionamento del sensore della pressione.
*/

class Pressione{
  private:
    int pressione;
    int pin;
    
    /**
    *Normalizza la pressione letta dal sensore in modo da essere gestita in modo opportuno
    *@param pressione legge il dato misurato dal sensore
    */
    int normalizza(int pressione){
      //@TODO si deve normalizzare la pressione prima di settarla
    }
  

  public:
  
    /**
    *Il metodo costruttore inizializza il pin secondo il parametro
    *e la pressione chiamando la funzione readPressione()
    *@param pin il piedino dove è inserito il sensore di pressione
    */
    Pressione(int pin){
      this->pin = pin;
      readPressione();
    }
    
    /**
    *Restituisce la pressione
    *@return restituisce la pressione
    */
    int getPressione(){
      return pressione;
    }
    
    /**
    *Restituisce il pin
    *@return restituisce il pin
    */
    int getPin(){
      return pin;
    }
    
    /**
    *Legge la pressione e la normalizza, settando l'attributo pressione
    */
    void readPressione(){
      pressione = normalizza(analogRead(pin));
    }
    
    /**
    *Setta il piedino su cui è posizionato il sensore di pressione
    */
    void setPin(int pin){
    	this->pin = pin;
    }
   
};
