// Definindo os componentes, biblioteca e endereço do servo
#include "Wire.h" 
#define slaveAdress 10
#define slaveAdress 11
#define slaveAdress 12

//Definindo variáveis do estado dos LEDs de cada servo 
bool ledState = true;
bool ledState_2;
bool ledState_3;


void setup(){
  Wire.begin();
}

//Estabelece a comunicação com os slaves, recebe informação deles e determina o estado do led que será enviado
void loop () {
  i2c_communication (10, ledState);
  Wire.requestFrom(10, 1);
  if (Wire.available()) {
  	bool received = Wire.read();
  	if (received){
      	ledState = false;
      	ledState_2 = true;
      
  	}}
  if (ledState == false){
  	i2c_communication (11, ledState_2);
  }
  Wire.requestFrom(11, 1);
  if (Wire.available()) {
  	bool received_2 = Wire.read();
    if (received_2){
      ledState_2 = false;
      ledState_3=true;
    }}
  if (ledState_2 == false){
  	i2c_communication (12,ledState_3);
  }
  Wire.requestFrom(12,1);
  if (Wire.available()){
    bool received_3 = Wire.read();
    if (received_3){
      ledState = true;
      ledState_3 = false; 
    }}

  delay (100);
}


// Função que envia as informações ao slave
void i2c_communication(int address, bool data)
{
  Wire.beginTransmission(address); // Start Transmission with address 10
  Wire.write(data); // Send data
  Wire.endTransmission(); // End transmission
}