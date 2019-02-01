    void setup() {
  // put your setup code here, to run once:
  
  int rosso1 = 10;
  int giallo1 = 9;
  int verde1 = 8;
  int rosso2 = 11;
  int giallo2 = 12;
  int verde2 = 13;
  int temporosso;
  int lampeggiverde;
  
  
  pinMode (rosso1,OUTPUT);
  pinMode (giallo1,OUTPUT);
  pinMode (verde1,OUTPUT);
  pinMode (rosso2,OUTPUT);
  pinMode (giallo2,OUTPUT);
  pinMode (verde2,OUTPUT);
  
  


}
void loop() {
  // put your main code here, to run repeatedly:

  //forse puoi toglierli
  int rosso1 = 10;
  int giallo1 = 9;
  int verde1 = 8;
  int rosso2 = 11;
  int giallo2 = 12;
  int verde2 = 13;
  int temporosso;
  int lampeggiverde;
  int tempolampeggiverde;
  
  
  //fase 1 [IL ROSSO STA ACCESO PER X TEMPO]
  digitalWrite (rosso1,HIGH);
  delay (temporosso); //variabile
  digitalWrite (rosso1,LOW);
  delay(0);

  //fase 2 [IL ROSSO E GIALLO STANNO ACCESI PER X TEMPO]
  digitalWrite (giallo1 ,HIGH);
  delay (0);
  digitalWrite (rosso1 ,HIGH);
  delay (2000); //variabile
  digitalWrite (giallo1 ,LOW);
  delay(0);
  digitalWrite (rosso1 , LOW);
  delay(0); 

  //fase 3 [IL VERDE SI ACCENDE E RESTA ACCESO CON UN DELAY CHE SI CALCOLA CON: ROSSO(della fase 1) - Lampeggio(della fase 4) * durata lampeggio(della fase 4)]
  digitalWrite (verde1 , HIGH);
  delay(temporosso-lampeggiverde*tempolampeggiverde*2); //variabile

//fase 4[LAMPEGGIA X VOLTE E PER X SECONDI]
for (int i=0; i<lampeggiverde; i++)
{
  digitalWrite (verde1 , HIGH);
  delay(tempolampeggiverde); //variabile
  digitalWrite (verde1, LOW);
  delay (tempolampeggiverde); //variabile
}

//fase 5[IL GIALLO RESTA ACCESO PER X SECONDI]
digitalWrite (giallo1, HIGH);
delay(2000);
digitalWrite (giallo1,LOW);
delay(0);
}
