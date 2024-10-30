#include <stdio.h>

long randNumber;
int contador = 0;
int botones[] = {913, 429, 267, 179, 110};
int btn_tol = 20;
int analogValue = 0;
int pinJ1 = A0;
int pinJ2 = A2;
int cuentaLeds = 5;
int ledsJ1[5] = {2, 3, 4, 5, 6};
int ledsJ2[5] = {8, 9, 10, 11, 12};
int puntajeJ1 = 0;
int puntajeJ2 = 0;
int velocidad = 4000;
int velocidad_min = 1000;
int puntajeMax = 50;
unsigned long tiempoLedsEn = 1000; 
unsigned long ultimoCambioLED = 0;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A4));

  for (int i = 0; i < cuentaLeds; i++) {
    pinMode(ledsJ1[i], OUTPUT);
    pinMode(ledsJ2[i], OUTPUT);
  }
}

void loop() {
  if (puntajeJ1 < puntajeMax && puntajeJ2 < puntajeMax) {
    contador++;
    bool acciones = false;
    if (contador > velocidad) {
      contador = 0;
      acciones = true;
      velocidad = velocidad - round(velocidad / 50);
      if (velocidad < velocidad_min) {
        velocidad = velocidad_min;
      }
    }

    if (acciones) {
      int pin_light = random(0, 5);
      digitalWrite(ledsJ1[pin_light], HIGH);
      digitalWrite(ledsJ2[pin_light], HIGH);
      ultimoCambioLED = millis();

      bool todosLedsEn = true;
      for (int i = 0; i < cuentaLeds; i++) {
        if (digitalRead(ledsJ1[i]) == LOW || digitalRead(ledsJ2[i]) == LOW) {
          todosLedsEn = false;
          break;
        }
      }

      if (todosLedsEn) {
        for (int i = 0; i < cuentaLeds; i++) {
          digitalWrite(ledsJ1[i], LOW);
          digitalWrite(ledsJ2[i], LOW);
        }
        delay(200);
      }
    }

    analogValue = analogRead(pinJ1);
    for (int i = 0; i < cuentaLeds; i++) {
      if (analogValue < botones[i] + btn_tol && analogValue > botones[i] - btn_tol) {
        if (digitalRead(ledsJ1[i]) == HIGH) {
          digitalWrite(ledsJ1[i], LOW);
          puntajeJ1++;
          Serial.print("puntaje J1: ");
          Serial.println(puntajeJ1);
        }
      }
    }

    analogValue = analogRead(pinJ2);
    for (int i = 0; i < cuentaLeds; i++) {
      if (analogValue < botones[i] + btn_tol && analogValue > botones[i] - btn_tol) {
        if (digitalRead(ledsJ2[i]) == HIGH) {
          digitalWrite(ledsJ2[i], LOW);
          puntajeJ2++;
          Serial.print("puntaje J2: ");
          Serial.println(puntajeJ2);
        }
      }
    }
  } else {
    // Jugador 1 Gana
    if (puntajeJ1 >= puntajeMax) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < cuentaLeds; j++) {
          digitalWrite(ledsJ1[j], HIGH);
          digitalWrite(ledsJ2[j], LOW);
        }
        delay(500);
        for (int j = 0; j < cuentaLeds; j++) {
          digitalWrite(ledsJ1[j], LOW);
        }
        delay(500);
      }
    } else if (puntajeJ2 >= puntajeMax) { //Jugador 2 Gana
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < cuentaLeds; j++) {
          digitalWrite(ledsJ2[j], HIGH);
          digitalWrite(ledsJ1[j], LOW);
        }
        delay(500);
        for (int j = 0; j < cuentaLeds; j++) {
          digitalWrite(ledsJ2[j], LOW);
        }
        delay(500);
      }
    }
  }
}