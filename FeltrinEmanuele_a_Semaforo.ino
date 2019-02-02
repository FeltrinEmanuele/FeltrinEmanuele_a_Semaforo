  void setup() {
  // put your setup code here, to run once:
  int rosso1 = 10;
  int giallo1 = 9;
  int verde1 = 8;
  int rosso2 = 11;
  int giallo2 = 12;
  int verde2 = 13;
  int temporosso;
  int lampeggiverde; //input
  int tempolampeggiverde; //input
  int tempoverde; 
  int tempogiallo; //input
  int temposemaforo; //input

  pinMode (rosso1,OUTPUT);
  pinMode (giallo1,OUTPUT);
  pinMode (verde1,OUTPUT);
  pinMode (rosso2,OUTPUT);
  pinMode (giallo2,OUTPUT);
  pinMode (verde2,OUTPUT);
  }
  
void loop()
{
  // put your main code here, to run repeatedly:
 
  //forse puoi toglierli
  int rosso1 = 10;
  int giallo1 = 9;
  int verde1 = 8;
  int rosso2 = 11;
  int giallo2 = 12;
  int verde2 = 13;
  int temporosso;//quanto tempo deve stare attivo il rosso
  int lampeggiverde;//numero di volte che lampeggierà il verde
  int tempolampeggiverde;//ms che starà acceso e spento il led
  int tempoverde;
  int tempogiallo;
  int temposemaforo;

  if (temposemaforo < tempogiallo)
  {"la variabile tempogiallo è troppo grande";}

  temporosso = temposemaforo - tempogiallo;
  tempoverde = temporosso-lampeggiverde*tempolampeggiverde*2;
  
 
  //fase 1 [IL ROSSO STA ACCESO PER X TEMPO]
  digitalWrite (rosso1,HIGH);
  delay (0);
  digitalWrite (verde2,HIGH);
  delay(tempoverde);
  digitalWrite (verde2, LOW);
  delay(0);
  for (int i=0; i<lampeggiverde; i++)
  {
  digitalWrite (verde2 , HIGH);
  delay(tempolampeggiverde); //variabile
  digitalWrite (verde2, LOW);
  delay (tempolampeggiverde); //variabile
  }
  delay (0);
  digitalWrite (rosso1,LOW);
  delay(0);
  

  //fase 2 [IL ROSSO E GIALLO STANNO ACCESI PER X TEMPO]
  digitalWrite (giallo1 ,HIGH);
  delay (0);
  digitalWrite (giallo2 ,HIGH);
  delay (0);
  digitalWrite (rosso1 ,HIGH);
  delay (tempogiallo); //variabile
  digitalWrite (giallo1 ,LOW);
  delay(0);
  digitalWrite (giallo2 ,LOW);
  delay (0);
  digitalWrite (rosso1 , LOW);
  delay(0); 

 
  //fase 3 [IL VERDE SI ACCENDE E RESTA ACCESO CON UN DELAY CHE SI CALCOLA CON: ROSSO(della fase 1) - Lampeggio(della fase 4) * durata lampeggio(della fase 4)]
  digitalWrite (rosso2, HIGH);
  delay (0);
  digitalWrite (verde1 , HIGH);
  delay(tempoverde);
  digitalWrite (verde1, LOW);
  delay(0);//variabile
  //fase 4[LAMPEGGIA X VOLTE E PER X SECONDI]
  for (int i=0; i<lampeggiverde; i++)
  {
  digitalWrite (verde1 , HIGH);
  delay(tempolampeggiverde); //variabile
  digitalWrite (verde1, LOW);
  delay (tempolampeggiverde); //variabile
  }
  delay (0);
  digitalWrite (rosso2,LOW);
  delay (0);

 
  //fase 5[IL GIALLO RESTA ACCESO PER X SECONDI]
  digitalWrite (giallo1, HIGH);
  delay (0);
  digitalWrite (rosso2,HIGH);
  delay (0);
  digitalWrite (giallo2,HIGH);
  delay(tempogiallo);//variabile
  digitalWrite (giallo1,LOW);
  delay(0);
  digitalWrite (giallo2,LOW);
  delay(0);
  digitalWrite (rosso2,LOW);
  delay(0);
}

void tempolampeggiverde()
{
  print("con quale velocità vuoi i lampeggi verdi (ms)?");
  while(Serial.available == 0) {};
  tempolampeggiverde =Serial.read().toInt();
}

void lampeggiverde()
{
  print("quanti lampeggi verdi?");
  while(Serial.available == 0) {};
  lampeggiverde =Serial.read().toInt();
}

void tempogiallo()
{
  print("per quanto tempo deve stare giallo il semaforo?");
  while(Serial.available == 0) {};
  tempogiallo =Serial.read().toInt();
}

void temposemaforo()
{
  print("con quale tempo vuoi che abbia finito un ciclo? ");
  while(Serial.available == 0) {};
  temposemaforo =Serial.read().toInt();
}
