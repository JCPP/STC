/**
*La classe Inquinamento descrive il funzionamento del sensore della inquinamento.
*/

class Inquinamento{
  private:
    int inquinamento;
    int pin;
    
    /**
    *Normalizza la inquinamento letta dal sensore in modo da essere gestita in modo opportuno
    *@param inquinamento legge il dato misurato dal sensore
    */
    int normalizza(int inquinamento){
      //@TODO si deve normalizzare l'inquinamento prima di settarla
    }
  

  public:
  
    /**
    *Il metodo costruttore inizializza il pin secondo il parametro
    *e la inquinamento chiamando la funzione readInquinamento()
    *@param pin il piedino dove è inserito il sensore di inquinamento
    */
    Inquinamento(int pin){
      this->pin = pin;
      readInquinamento();
    }
    
    /**
    *Restituisce la inquinamento
    *@return restituisce la inquinamento
    */
    int getInquinamento(){
      return inquinamento;
    }
    
    /**
    *Restituisce il pin
    *@return restituisce il pin
    */
    int getPin(){
      return pin;
    }
    
    /**
    *Legge la inquinamento e la normalizza, settando l'attributo inquinamento
    */
    void readInquinamento(){
      inquinamento = normalizza(analogRead(pin));
    }
    
    /**
    *Setta il piedino su cui è posizionato il sensore di inquinamento
    */
    void setPin(int pin){
      this->pin = pin;
    }
   
};
