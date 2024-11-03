int pinMotor = 3;

int pinPot = A5;
int valorSalidaMotor = -1;
int valPot = -1;


void setup(){
  
 Serial.begin(9600);
 pinMode(pinMotor, OUTPUT);
}


void loop(){
  
 valPot =analogRead(pinPot);
  Serial.print("Potenciometro: ");
  Serial.println(valPot);
  
  //analogWrite(pinMotor, valPot); // Usar el potenciomentro a 10 bits con desbordamiento
  Serial.print("------");
  
  valorSalidaMotor = map(valPot, 0, 1023, 0, 255); // Usando la función map para convertir la salida a 8 bits y evitar el desbordamiento
  Serial.print("Motor: ");
  Serial.println(valorSalidaMotor);
  
  analogWrite(pinMotor, valorSalidaMotor);
  
}