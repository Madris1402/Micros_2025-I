int pinTrigger = 3;
int pinEcho = 2;

float tiempoTotal = -1;
float distancia = -1;

int ledV = 5;
int ledA = 6;
int ledN = 7;
int ledR = 8;


void setup(){
  
  Serial.begin(9600);
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledN, OUTPUT);
  pinMode(ledR, OUTPUT);
}

void loop(){
  
  leds();
  
  //ACTIVAR EL SENSOR
  digitalWrite(pinTrigger, LOW);
  delay(5);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);
  
  //LECTURA DEL SENSOR
  tiempoTotal = pulseIn(pinEcho, HIGH); //Pide dos argumentos, el pin y el tipo de puslo a medir
  
  Serial.print("Tiempo Total ");
  Serial.println(tiempoTotal);
  
  //CALCULAR DISTANCIA
  distancia = tiempoTotal/58;
  
  Serial.print("Distancia ");
  Serial.println(distancia);
  Serial.print("----------- \n");
  delay(1000);
  
  
}

void leds(){
  
  if (distancia<=85){
    
      digitalWrite(ledV, LOW);
      digitalWrite(ledA, LOW);
      digitalWrite(ledN, LOW);
      digitalWrite(ledR, HIGH);
  } else if(distancia<=169){
    
      digitalWrite(ledV, LOW);
      digitalWrite(ledA, LOW);
      digitalWrite(ledN, HIGH);
      digitalWrite(ledR, LOW);
  } else if (distancia <=253){
      
      digitalWrite(ledV, LOW);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledN, LOW);
      digitalWrite(ledR, LOW);
  } else if (distancia <=336.7){
      
      digitalWrite(ledV, HIGH);
      digitalWrite(ledA, LOW);
      digitalWrite(ledN, LOW);
      digitalWrite(ledR, LOW);
  } else if (distancia > 336.7 | distancia <= 0){
    
      digitalWrite(ledV, HIGH);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledN, HIGH);
      digitalWrite(ledR, HIGH);
  }
  
}