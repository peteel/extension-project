// Servo's code - I2C Communication

#include <Wire.h>


#define led 2
#define address_i2c 10


bool data = false; // Global variable - We can use this variable in receive and in loop


void setup()
{
  pinMode(led, OUTPUT);
  Wire.begin(address_i2c);
  Wire.onReceive(i2c_communication_receiver);
}

void loop()
{
  if (data) {digitalWrite(led, HIGH);}
  else {digitalWrite(led, LOW);}
  delay(100); // Wait for 100 millisecond(s)
}

void i2c_communication_receiver(int num_bytes)
{
  if (Wire.available())
  {
    data = Wire.read();
  }
}
