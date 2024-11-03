int down = 7;
int up = 6;
int lecturaDown;
int lecturaUp;

void setup(){
 
 Serial.begin(9600); //Sincronizar Arduino con PC a 9600 Baulios
 pinMode(down, INPUT);
 pinMode(up, INPUT);
  
}

void loop (){
//Almacenar las lecturas en una variable

  lecturaDown = digitalRead(down);
  lecturaUp = digitalRead(up);
  
  Serial.print("Down: ");
   	Serial.println(lecturaDown);
  Serial.print("Up: ");
   	Serial.println(lecturaUp);
  
}