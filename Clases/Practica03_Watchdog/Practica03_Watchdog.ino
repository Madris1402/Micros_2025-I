#include <avr/wdt.h>

int LedV = 7;
int LedA = 6;
int LedB = 5;
int Switch = 2;

int valSw = -1;

void setup(){
  wdt_disable(); //Se deshabilita por defecto para evitar bucles u otros errores
  Serial.begin(9600);
  
  pinMode(LedV, OUTPUT);
  pinMode(LedA, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(Switch, INPUT);
  
  digitalWrite(LedV, HIGH);
  delay(300);
  digitalWrite(LedV, LOW);
  delay(300);
  digitalWrite(LedV, HIGH);
  delay(300);
  digitalWrite(LedV, LOW);
  delay(300);
  digitalWrite(LedV, HIGH);
  
  wdt_enable(WDTO_1S); //Activamos el Watchdog
}


void loop(){
  
  valSw = digitalRead(Switch);
  
  if(valSw == HIGH){
   Serial.println("Todo en Orden");
    digitalWrite(LedA, HIGH);
    digitalWrite(LedB, LOW);
    
   wdt_reset(); 
  }else{
    
   Serial.println("Algo fallo");
    digitalWrite(LedB, HIGH);
    digitalWrite(LedA, LOW);
  }
  
}