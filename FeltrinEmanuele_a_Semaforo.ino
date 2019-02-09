  int tempogiallo; //input
  int temposemaforo; //input
  int lampeggiverde; //input
  int tempolampeggiverde; //input
  int tempoverde; 
  int temporosso;
  int rosso1;
  int giallo1;
  int verde1;
  int rosso2;
  int giallo2;
  int verde2;
  
  void setup() {
    
  // put your setup code here, to run once:
  rosso1 = 10;
  giallo1 = 9;
  verde1 = 8;
  rosso2 = 11;
  giallo2 = 12;
  verde2 = 13;
 
  pinMode (rosso1,OUTPUT);
  pinMode (giallo1,OUTPUT);
  pinMode (verde1,OUTPUT);
  pinMode (rosso2,OUTPUT);
  pinMode (giallo2,OUTPUT);
  pinMode (verde2,OUTPUT);

  Serial.begin(9600);

  ILtempolampeggiverde();
  ILlampeggiverde();
  ILtempogiallo();
  ILtemposemaforo();
  
  
  }
  
void loop()
{
  // put your main code here, to run repeatedly:

 

  if (temposemaforo < tempogiallo)
  {"la variabile tempogiallo è troppo grande";}

  int temporosso = temposemaforo - tempogiallo;
  int tempoverde = temporosso-lampeggiverde*tempolampeggiverde*2; 
  
 
  //fase 1 [IL ROSSO STA ACCESO PER X TEMPO]
  digitalWrite (rosso1,HIGH);
  digitalWrite (verde2,HIGH);
  delay(tempoverde);
  for (int i=0; i<lampeggiverde; i++)
  {
  digitalWrite (verde2 , HIGH);
  delay(tempolampeggiverde); //variabile
  digitalWrite (verde2, LOW);
  delay (tempolampeggiverde); //variabile
  }

  //fase 2 [IL ROSSO E GIALLO STANNO ACCESI PER X TEMPO]
  digitalWrite (giallo1 ,HIGH);
  digitalWrite (giallo2 ,HIGH);
  delay (tempogiallo); //variabile
  digitalWrite (giallo1 ,LOW);
  digitalWrite (giallo2 ,LOW);
  digitalWrite (rosso1 , LOW);


  //fase 3 [IL VERDE SI ACCENDE E RESTA ACCESO CON UN DELAY CHE SI CALCOLA CON: ROSSO(della fase 1) - Lampeggio(della fase 4) * durata lampeggio(della fase 4)]
  digitalWrite (rosso2, HIGH);
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
  digitalWrite (rosso2,HIGH);
  digitalWrite (giallo2,HIGH);
  delay(tempogiallo);//variabile
  digitalWrite (giallo1,LOW);
  digitalWrite (giallo2,LOW);
  digitalWrite (rosso2,LOW);
  delay(0);
}

void ILtempolampeggiverde()
{
  Serial.println("con quale velocità vuoi i lampeggi verdi (ms)?");
  while(Serial.available() == 0) {};
  String inp = Serial.readString(); 
  tempolampeggiverde = inp.toInt();
}

void ILlampeggiverde()
{
  Serial.println("quanti lampeggi verdi?");
  while(Serial.available() == 0) {};
  String inp =Serial.readString();
  lampeggiverde = inp.toInt();
}

void ILtempogiallo()
{
  Serial.println("per quanto tempo deve stare giallo il semaforo?");
  while(Serial.available() == 0) {};
  String inp =Serial.readString();
  tempogiallo =  inp.toInt();
}

void ILtemposemaforo()
{
  Serial.println("con quale tempo vuoi che abbia finito un ciclo? ");
  while  (Serial.available() == 0) {};
  String inp = Serial.readString();
  temposemaforo = inp.toInt();
}
 



