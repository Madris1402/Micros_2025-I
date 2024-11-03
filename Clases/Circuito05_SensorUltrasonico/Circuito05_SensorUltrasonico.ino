#include <avr/wdt.h>

int LedV = 7;
int Switch = 2;

int valSw = -1;

void setup(){
  wdt_disable(); //Se deshabilita por defecto para evitar bucles u otros errores
  Serial.begin(9600);
  
  pinMode(LedV, OUTPUT);
  pinMode(Switch, INPUT);
  
  digitalWrite(LedV, HIGH);
  delay(500);
  digitalWrite(LedV, LOW);
  delay(500);
  digitalWrite(LedV, HIGH);
  delay(500);
  digitalWrite(LedV, LOW);
  delay(500);
  digitalWrite(LedV, HIGH);
  
  wdt_enable(WDTO_1S); //Activamos el Watchdog
}


void loop(){
  
  valSw = digitalRead(Switch);
  if(valSw == HIGH){
    
   Serial.println("Todo en Orden");
   wdt_reset(); 
  }else{
    
   Serial.println("Algo fallo, se debe reiniciar"); 
  }
  
}