int pulsante;
int ledBlu;
int bazzer;
int led_RGB_Rosso;
int led_RGB_Verde;
int tempoTestLed;
int tempoTestBuzzer;
void setup() {

}
void loop() {

}

void PremiPulsante()
{
  bool finito=false;
  while(!finito)
  {
    if(pulsante==HIGH)
    {
      finito=true;
    }
  }
}

int Test(int device,String messaggio)
{
  int primoTempo;
  int secondoTempo;
  int tempoTest;
  delay(random(1000,10000));
  digitalWrite(device,HIGH);
  primoTempo=millis();
  PremiPulsante();
  digitalWrite(device,LOW);
  secondoTempo=millis();
  tempoTest=secondoTempo-primoTempo;
  Serial.println(messaggio + String (tempoTest));
  return tempoTest;
}

void AnalizzatoreRisultati()
{
  if(tempoTestLed<250 && tempoTestBuzzer<250)
  {  
    digitalWrite(led_RGB_Verde,HIGH);
  }
  else
  {
    digitalWrite(led_RGB_Rosso,HIGH);
  }
  delay(5000);
  digitalWrite(led_RGB_Verde,LOW);
  digitalWrite(led_RGB_Rosso,LOW);
}
