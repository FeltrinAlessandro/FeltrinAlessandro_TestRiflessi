int pulsante;
int ledBlu;
int buzzer;
int led_RGB_Rosso;
int led_RGB_Verde;
int tempoTestLed;
int tempoTestBuzzer;
void setup() {
  pulsante=3;
  ledBlu=4;
  buzzer=5;
  led_RGB_Rosso=8;
  led_RGB_Verde=9;
  pinMode(pulsante,INPUT);
  pinMode(ledBlu,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led_RGB_Rosso,OUTPUT);
  pinMode(led_RGB_Verde,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  PremiPulsante();
  tempoTestLed=Test(ledBlu,"Il risultato del test visivo è:");
  tempoTestBuzzer=Test(ledBlu,"Il risultato del test uditivo è:");
  AnalizzatoreRisultati();
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
