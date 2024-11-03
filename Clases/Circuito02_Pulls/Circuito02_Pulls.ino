const int pinLeds = 8;

void setup(){ // Estructura para iniciar el Arduino
  
  pinMode(pinLeds, OUTPUT); //Pide dos argumentos, Pin y Modo de funcionamiento
}


void loop(){ //Es un bucle que se repite indefinidamente
  
  digitalWrite(pinLeds, HIGH);
  delay(1000); //Funciona con Milisegundos
  digitalWrite(pinLeds, LOW);
  delay(1000);
  
}