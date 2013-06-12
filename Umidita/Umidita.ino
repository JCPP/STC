/**
*La classe Umidita descrive il funzionamento del sensore della umidita.
*/

class Umidita{
  private:
    int umidita;
    int pin;
    
    /**
    *Normalizza la umidita letta dal sensore in modo da essere gestita in modo opportuno
    *@param umidita legge il dato misurato dal sensore
    */
    int normalizza(int umidita){
      //@TODO si deve normalizzare la umidita prima di settarla
    }
  

  public:
  
    /**
    *Il metodo costruttore inizializza il pin secondo il parametro
    *e la umidita chiamando la funzione readUmidita()
    *@param pin il piedino dove è inserito il sensore di umidita
    */
    Umidita(int pin){
    	this->pin = pin;
      readUmidita();
    }
    
    /**
    *Restituisce la umidita
    *@return restituisce la umidita
    */
    int getUmidita(){
      return umidita;
    }
    
    /**
    *Restituisce il pin
    *@return restituisce il pin
    */
    int getPin(){
      return pin;
    }
    
    /**
    *Legge la umidita e la normalizza, settando l'attributo umidita
    */
    void readUmidita(){
      umidita = normalizza(analogRead(pin));
    }
    
    /**
    *Setta il piedino su cui è posizionato il sensore di umidita
    */
    void setPin(int pin){
    	this->pin = pin;
    }
   
};
