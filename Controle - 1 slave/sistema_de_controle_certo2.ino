#include "Wire.h"
#define ledPin 0 // numero do pino onde o LED esta conectado
#define ldr A0
#define myAdress 10

float level = 700;
bool presence = false;
bool data; 

void setup () {
  pinMode(ledPin, OUTPUT);
  Wire.begin(myAdress);
  Wire.onReceive(i2c_communication_receiver);
  Wire.onRequest(requestEvent);
}

void loop()
{
  if (data) {digitalWrite(ledPin, HIGH);}
  else {digitalWrite(ledPin, LOW);}
  delay(100); // Wait for 100 millisecond(s)
  presence = sensor_ldr(ldr, level);
}

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


void i2c_communication_receiver(int num_bytes)
{
  if (Wire.available())
  {
    data = Wire.read();
  }
}

void requestEvent(){
  Wire.write(presence);
}
