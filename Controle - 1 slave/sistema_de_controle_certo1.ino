#include "Wire.h" 
#define ledPin 12 
#define slaveAdress 10

bool ledState = true;

void setup(){
  Wire.begin();
  pinMode(ledPin, OUTPUT);
}

void loop () {
  i2c_communication (10, ledState);
  Wire.requestFrom(10, 1);
  if (Wire.available()) {
  	bool received = Wire.read();
  	if (received){
    	digitalWrite (ledPin, HIGH);
      	ledState = false;
  	}
  	else{
    	digitalWrite(ledPin, LOW);
    }}
  delay (100);
}



void i2c_communication(int address, bool data)
{
  Wire.beginTransmission(address); // Start Transmission with address 10
  Wire.write(data); // Send data
  Wire.endTransmission(); // End transmission
}