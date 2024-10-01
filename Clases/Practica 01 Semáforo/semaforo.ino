const int PinV1 = 13;
const int PinA1 = 12;
const int PinR1 = 11;
const int PinV2 = 10;
const int PinA2 = 9;
const int PinR2 = 8;

void setup()
{
  pinMode(PinV1, OUTPUT);
  pinMode(PinA1, OUTPUT);
  pinMode(PinR1, OUTPUT);
  pinMode(PinV2, OUTPUT);
  pinMode(PinA2, OUTPUT);
  pinMode(PinR2, OUTPUT);
}

void loop()
{
  digitalWrite(PinV1, HIGH);
  digitalWrite(PinR2, HIGH);
  delay(3000);
  digitalWrite(PinV1, LOW);
  digitalWrite(PinA1, HIGH);
  delay(1000);
  digitalWrite(PinA1, LOW);
  delay(500);
  digitalWrite(PinA1, HIGH);
  delay(500);
  digitalWrite(PinA1, LOW);
  delay(500);
  digitalWrite(PinA1, HIGH);
  delay(500);
  digitalWrite(PinA1, HIGH);
  digitalWrite(PinA1, LOW);
  digitalWrite(PinR1, HIGH);
  digitalWrite(PinR2, LOW);
  digitalWrite(PinV2, HIGH);
  delay(3000);
  digitalWrite(PinV2, LOW);
  digitalWrite(PinA2, HIGH);
  delay(1000);
  digitalWrite(PinA2, LOW);
  delay(500);
  digitalWrite(PinA2, HIGH);
  delay(500);
  digitalWrite(PinA2, LOW);
  delay(500);
  digitalWrite(PinA2, HIGH);
  delay(500);
  digitalWrite(PinA2, LOW);
  digitalWrite(PinR1, LOW);

}