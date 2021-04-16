#include <LiquidCrystal.h>// Importando a biblioteca do Display
//----------------------------------------------

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Inicializando as portas de dados do display 


int valConv = 0; //Variavel usada para ler o valor que é convertido pela função analogRead
bool presenca = false; //Variavel usada para verificar se há presença
 
//Setup(Executado apenas uma vez)  
void setup(){
  
}

//Laço principal (Executado Infinitamente)
void loop(){

  // Verifica se há presença
  presenca = sensor_ldr(0, 700);

  //Condição para luminosidade
  if (presenca) {   
    lcd.begin(20, 4);
    lcd.setCursor(4,0);
    lcd.print("Sensor LDR");
    lcd.setCursor(1,1);
    lcd.print("Presenca: SIM");
  }
  else{
    lcd.begin(20, 4);
    lcd.setCursor(4,0);
    lcd.print("Sensor LDR");
    lcd.setCursor(1,1);
    lcd.print("Presenca: NAO");
  }
  
  delay(1000);//Espera 1 segundo para executar o laço novamente
   
}

bool sensor_ldr(int pin, float level){
  
  int value = 0; //Variable used to read the value that is converted by the analogRead function     
  bool result = false; //Variable used to check if there is presence (value < level) or if there is no presence (value >= level)
  
  value = analogRead(pin);// Read the sensor value on the pin  
  
  if(value < level){
    result = true;
  }

  return result; 
}
