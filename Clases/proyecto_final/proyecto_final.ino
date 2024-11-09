#include <stdio.h>

long randNumber;
int contador = 0;
int botones[] = {913, 429, 267, 179, 110};
int btn_tol = 20;
int analogValue = 0;
int pinJ1 = A3;
int pinJ2 = A5;
int cuentaLeds = 5;
int ledsJ1[5] = {2, 3, 4, 5, 6};
int ledsJ2[5] = {8, 9, 10, 11, 12};
int ledsMax = 3;
int puntajeJ1 = 0;
int puntajeJ2 = 0;
int velocidad = 1500;
int velocidad_min = 250;
int puntajeMax = 15;
unsigned long tiempoLedsEn = 700; 
unsigned long ultimoCambioLED = 0;
unsigned long tiempoEncendidoJ1[5] = {0, 0, 0, 0, 0}; // Array para almacenar el tiempo de encendido de cada LED de J1
unsigned long tiempoEncendidoJ2[5] = {0, 0, 0, 0, 0}; // Array para almacenar el tiempo de encendido de cada LED de J2

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average   


void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A4));

  for (int i = 0; i < cuentaLeds; i++) {
    pinMode(ledsJ1[i], OUTPUT);
    pinMode(ledsJ2[i], OUTPUT);
  }
}

void loop() {
  unsigned long tiempoActual = millis();

  total = total - readings[index];
  readings[index] = analogRead(pinJ1);
  total = total + readings[index];
  index = index + 1;
  if (index >= numReadings) 
    index = 0;
  average = total / numReadings;

  // Aumentar btn_tol para una detección menos sensible
  int btn_tol_ajustado = 50;

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
      int ledsEncendidosJ1 = 0;
      int ledsEncendidosJ2 = 0;

      // Contamos los LEDs encendidos en cada conjunto
      for (int i = 0; i < cuentaLeds; i++) {
        if (digitalRead(ledsJ1[i]) == HIGH) ledsEncendidosJ1++;
        if (digitalRead(ledsJ2[i]) == HIGH) ledsEncendidosJ2++;
      }

      // Encendemos un LED al azar solo si hay menos de dos encendidos
      if (ledsEncendidosJ1 < ledsMax) {
        int pin_light = random(0, cuentaLeds);
        digitalWrite(ledsJ1[pin_light], HIGH);
        tiempoEncendidoJ1[pin_light] = tiempoActual; // Registrar el tiempo de encendido
      }

      if (ledsEncendidosJ2 < ledsMax) {
        int pin_light = random(0, cuentaLeds);
        digitalWrite(ledsJ2[pin_light], HIGH);
        tiempoEncendidoJ2[pin_light] = tiempoActual; // Registrar el tiempo de encendido
      }
      
      ultimoCambioLED = tiempoActual;

      // Apagado automático de LEDs después de 1 segundo si no se presionan
      for (int i = 0; i < cuentaLeds; i++) {
        if (digitalRead(ledsJ1[i]) == HIGH && tiempoActual - tiempoEncendidoJ1[i] >= tiempoLedsEn) {
          digitalWrite(ledsJ1[i], LOW);
        }
        if (digitalRead(ledsJ2[i]) == HIGH && tiempoActual - tiempoEncendidoJ2[i] >= tiempoLedsEn) {
          digitalWrite(ledsJ2[i], LOW);
        }
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
    } else if (puntajeJ2 >= puntajeMax) {
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