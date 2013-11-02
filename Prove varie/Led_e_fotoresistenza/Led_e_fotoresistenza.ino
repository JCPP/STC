/**
*Questo programma, consente di accendere un led quando la luminosità scende sotto una certa soglia.
*/
int led = 13;
int fotoresistenza = 0;

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  
}

void loop(){
  Serial.println(analogRead(fotoresistenza));
  if(analogRead(fotoresistenza) < 150){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
}
