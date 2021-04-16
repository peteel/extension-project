
#define led 4
float distancia;
int sinal=3;


void leitura();



void setup(){
  Serial.begin(9600);
  pinMode(distancia, INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  leitura();
  distancia=distancia/2;
  distancia = distancia*0.034029;
  Serial.println(distancia);
  if (distancia<=220){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  delay(100);    
}

void leitura(){
  pinMode(sinal, OUTPUT);
  digitalWrite(sinal, HIGH);
  delayMicroseconds(5);
  digitalWrite(sinal, LOW);
  pinMode(sinal, INPUT);
  distancia = pulseIn(sinal, HIGH);

}
