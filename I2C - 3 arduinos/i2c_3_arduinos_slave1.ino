#include <Wire.h>    // Variável que aramazena o estado no LED que o mestre irá enviar
bool estado;
int  pino_LED = 13;
#define myAdress 1
// ==================================================================================================
// --- Definindo void setup() ---
void setup() {
  Wire.begin(1);                 // Iniciando a comunicação com o mestre através do endereço 0x08
  Wire.onReceive(Dado_Recebido);    // Quando o escravo receber algo no barramento, ele chama a função 'Dado_Recebido' 
  pinMode(pino_LED,OUTPUT);         // Colocando o LED como saida 
  Wire.onReceive(Dado_Recebido);
  Wire.onRequest(requestEvent);
}
// ==================================================================================================
// --- Definindo void setup() ---
void loop() {
    delay(10000);
}
 
// ==================================================================================================
// --- Definindo as funções criadas ---
void Dado_Recebido(int leitura) {
  
   estado = Wire.read();    // Lê os dados eviados
 
  if (estado == 1){
    digitalWrite(pino_LED,HIGH);
  }
  
  else{
    digitalWrite(pino_LED,LOW);
  }
}
void requestEvent(){
  // envia o estado que o led deve assumir
  Wire.write(1);
}