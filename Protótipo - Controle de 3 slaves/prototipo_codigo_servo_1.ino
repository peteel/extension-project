// Definindo os componentes, biblioteca e endereço do servo
#include "Wire.h"
#define ledPin 0 // numero do pino onde o LED esta conectado
#define ldr A0
#define myAdress 10

//Definindo variáveis globais
float level = 700;
bool presence = false;
bool data; 

//Esabelecendo a comunicação i2c a partir das funções definidas posteriormente
void setup () {
  pinMode(ledPin, OUTPUT);
  Wire.begin(myAdress);
  Wire.onReceive(i2c_communication_receiver);
  Wire.onRequest(requestEvent);
}

//Chama a função do LDR e liga o LED de acordo com o estado recebido
void loop()
{
  if (data) {digitalWrite(ledPin, HIGH);}
  else {digitalWrite(ledPin, LOW);}
  presence = sensor_ldr(ldr, level);
  delay(100); // Wait for 100 millisecond(s)
}

//Função que retorna que é enviado ao master de acordo com a entrada do LDR
bool sensor_ldr(int pin, float level)
{  
  int value = 0; //Variable used to read the value that is converted by the analogRead function     
  bool result = false; //Variable used to check if there is presence (value < level) or if there is no presence (value >= level)
  value = analogRead(pin);// Read the sensor value on the pin  
  if(value > level){
    result = true;
  }
  return result; 
}

//Função que lê a informação recebida do master
void i2c_communication_receiver(int num_bytes)
{
  if (Wire.available())
  {
    data = Wire.read();
  }
}

//Função que envia a informação ao master 
void requestEvent(){
  Wire.write(presence);
}
