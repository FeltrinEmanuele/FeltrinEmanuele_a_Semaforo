  int tempogiallo; //input
  int temposemaforo; //input
  int lampeggiverde; //input
  int tempolampeggiverde; //input
  int tempoverde; //lo calcolo in seguito
  int temporosso; // lo calcolo in seguito
  int rosso1;
  int giallo1;
  int verde1;
  int rosso2;
  int giallo2;
  int verde2;
    
  void setup() { 
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
  tempolampeggiverde = RichiediValori("quanto tempo deve stare acceso il verde durante un lampeggio? (ms)");
  lampeggiverde      = RichiediValori("quanti lampeggi verdi?");
  tempogiallo        = RichiediValori("per quanto tempo deve stare giallo il semaforo? (ms)");
  temposemaforo      = RichiediValori("con quale tempo vuoi che abbia finito un ciclo? (ms)");
  temporosso         = temposemaforo - tempogiallo;
  tempoverde         = temporosso-lampeggiverde*tempolampeggiverde*2; 
  }
    
  int RichiediValori(String domanda){
  Serial.println(domanda);
  while(Serial.available() == 0) {};
  String inp = Serial.readString(); 
  return (inp.toInt());}
 
  void loop()
  {
  fase1(rosso1,verde2);
  fase2(giallo1,giallo2,rosso1);
  fase1(rosso2,verde1);
  digitalWrite (rosso2,LOW);
  fase2(giallo1,giallo2,rosso2); 
  }

void fase1 ( int Colore1, int Colore2)
{
 digitalWrite (Colore1,HIGH);
  digitalWrite (Colore2,HIGH);
  delay(tempoverde);
  digitalWrite (Colore2,LOW);
  for (int i=0; i<lampeggiverde; i++)
  {
  digitalWrite (Colore2 , HIGH);
  delay(tempolampeggiverde); 
  digitalWrite (Colore2, LOW);
  delay (tempolampeggiverde); 
  }
}
void fase2 ( int Colore1, int Colore2, int Colore3 )
{
  digitalWrite (Colore1 ,HIGH);
  digitalWrite (Colore2 ,HIGH);
  digitalWrite (Colore3,HIGH);
  delay (tempogiallo); 
  digitalWrite (Colore1 ,LOW);
  digitalWrite (Colore2 ,LOW);
  digitalWrite (Colore3 , LOW);
}
