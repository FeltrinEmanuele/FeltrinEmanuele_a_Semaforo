    void setup() {
  // put your setup code here, to run once:
  
  int rosso1 = 10;
  int giallo1 = 9;
  int verde1 = 8;
  
  pinMode (rosso1,OUTPUT);
  pinMode (giallo1,OUTPUT);
  pinMode (verde1,OUTPUT);


}
void loop() {
  // put your main code here, to run repeatedly:
  
  int rosso1 = 10;
  int giallo1 = 9;
  int verde1 = 8;
  
  digitalWrite (rosso1,HIGH);
  delay (2000);
   digitalWrite (rosso1,LOW);
  delay(0);
  
  digitalWrite (giallo1 ,HIGH);
  delay (0);
  digitalWrite (rosso1 ,HIGH);
  delay (2000);
  
  digitalWrite (giallo1 ,LOW);
  delay(0);
  digitalWrite (rosso1 , LOW);
  delay(0);
  digitalWrite (verde1 , HIGH);
  delay(4000);

for (int i=0; i<5; i++)
{
  digitalWrite (verde1 , HIGH);
  delay(300);
  digitalWrite (verde1, LOW);
  delay (400);
}

digitalWrite (giallo1, HIGH);
delay(2000);
digitalWrite (giallo1,LOW);
delay(0);
}
