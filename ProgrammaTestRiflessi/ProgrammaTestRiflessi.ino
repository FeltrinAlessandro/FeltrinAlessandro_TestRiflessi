int pulsante;
int ledBlu;
int bazzer;
int led_RGB_Rosso;
int led_RGB_Verde;
int tempoTestLed;
int tempoTestBuzzer;
int primoTempo;
int secondoTempo;
void setup() {
  // put your setup code here, to run once:
 
}
void loop() {
  // put your main code here, to run repeatedly
}

void PremiPulsante(int device)
{
  bool finito=false;
  digitalWrite(device,HIGH);
  while(!finito)
  {
    if(pulsante==HIGH)
    {
      finito=true;
    }
  }
  digitalWrite(device,LOW);
}

void LedTest()
{
  delay(random(1000,10000));
  primoTempo=millis();
  PremiPulsante(ledBlu);
  secondoTempo=millis();
  tempoTestLed=secondoTempo-primoTempo;
}
