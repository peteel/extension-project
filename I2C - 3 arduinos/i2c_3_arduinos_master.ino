#include <Wire.h>    // Incluindo a biblioteca para realizar a comunicação I2C

#define slaveAdress 1
#define slaveAdress 2
#define led 0
#define led2 2

// ==================================================================================================
// --- Definicando o void setup() ---
void setup() {
  Wire.begin();      // Inicia a comunicação I2C
}
// ==================================================================================================
// --- Definicando o void loop() ---
void loop() {
  Wire.beginTransmission(1);   // Estamos iniciando a comunicação com o escravo no endereço 0x08
  
  Wire.write(1);         // Estamos enviando para o escravo o estado do LED que queremos
  Wire.endTransmission();         // Encerrando a comunicação com o escravo
  
 
  delay(5);
  
  Wire.beginTransmission(2);   // Estamos iniciando a comunicação com o escravo no endereço 0x08
  
  Wire.write(1);         // Estamos enviando para o escravo o estado do LED que queremos
  Wire.endTransmission();         // Encerrando a comunicação com o escravo
 
  delay(5);
  Wire.requestFrom(1 , 1);
  if (Wire.available()) {
    char received = Wire.read();
    if (received == 1) {
         digitalWrite(led, HIGH);
    }
    if (received == 0) {
         digitalWrite(led, LOW);
    }}
  Wire.requestFrom(2 , 1);
  if (Wire.available()) {
    char received2 = Wire.read();
    if (received2 == 1) {
         digitalWrite(led2, HIGH);
    }
    if (received2 == 0) {
         digitalWrite(led2, LOW);
    }}
  }