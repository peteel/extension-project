// Master's code - I2C Communication

#include <Wire.h>


#define ldr A0
#define servo1_address 10

float level = 700;
bool presence = false;


void setup()
{
  Wire.begin();
}


void loop()
{
  presence = sensor_ldr(ldr, level);
  i2c_communication(servo1_address, presence);
}


bool sensor_ldr(int pin, float level)
{  
  int value = 0; //Variable used to read the value that is converted by the analogRead function     
  bool result = false; //Variable used to check if there is presence (value < level) or if there is no presence (value >= level)
  
  value = analogRead(pin);// Read the sensor value on the pin  
  
  if(value < level){
    result = true;
  }

  return result; 
}


void i2c_communication(int address, bool data)
{
  Wire.beginTransmission(address); // Start Transmission with address 10
  Wire.write(data); // Send data
  Wire.endTransmission(); // End transmission
}