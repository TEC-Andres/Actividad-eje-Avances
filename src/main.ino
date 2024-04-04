/*
#       Sesión 30: Actividad eje
#       Andrés Rodríguez Cantú ─ Daniela Mendez Rivas
#
#       Copyright (C) Tecnologico de Monterrey
#
#       Archivo: main.ino
#
#       Datos del programa (Sin contar la consola de debugging)
#       Almacenamiento: 6,754 (20%) / 32,256 bytes
#       RAM (Globales): 508 (24%) / 2,048 bytes
#
#       Creado:                   08/01/2024
#       Última Modificación:      25/03/2024
*/ 

/* Librerias de componentes */
#include <Wire.h>
#include <OneWire.h>              // [Wokwi]
#include <DallasTemperature.h>    // [Wokwi]
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

/* Librerias de Aplicaciones */
#include "DUO.h"
DUO_OS Duo;

/* Definiciones de componentes */
#define B_VOL A0
#define B_TMP A1
#define B_PHS A2
#define B_IZQ 2
#define B_ARR 3
#define B_ABJ 4
#define B_DER 5
#define B_SEL 6
#define B_SHF 7
#define B_BUZ 8

/* Setup de librerias */
Servo servo;
OneWire oneWire(B_TMP);
DallasTemperature TMP(&oneWire);

/* Declare the LiquidCrystal_I2C object */
LiquidCrystal_I2C lcd(0x27, 16, 2);

/* Variables Globales */
int frame = 1; 
int POSx;
int POSy;
float gradosC;
double voltage;
double resistencia;

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(B_BUZ, INPUT);
  TMP.begin();
  servo.attach(9);
  Serial.begin(9600);
}

void loop()
{
  /* Setup de Librerias */
  TMP.requestTemperatures();

  /* Lectura del Hardware */
  int B_IZQ_R = digitalRead(B_IZQ);         // Lectura del botón Izquierdo
  int B_ARR_R = digitalRead(B_ARR);         // Lectura del botón Arriba
  int B_ABJ_R = digitalRead(B_ABJ);         // Lectura del botón Abajo
  int B_DER_R = digitalRead(B_DER);         // Lectura del botón Derecho
  int B_SEL_R = digitalRead(B_SEL);         // Lectura del botón Seleccionar
  int B_SHF_R = digitalRead(B_SHF);         // Lectura del botón Shift
  int B_VOL_R = analogRead(B_VOL);          // Lectura del potenciometro Volumen
  float A_PHS_R = analogRead(B_PHS);        // Lectura del sensor de Fotoresistencia
  //float B_TMP_R = analogRead(B_TMP);      // [Tinkercad] Lectura del sensor de Temperatura

  /* Variables Locales */
  voltage = A_PHS_R / 1024. * 5;
  resistencia = 2000 * voltage / (1 - voltage / 5);
  double B_PHS_R = pow(50 * 1e3 * pow(10, 0.7) / resistencia, (1 / 0.7));
  gradosC = TMP.getTempCByIndex(0);         // [Wokwi] Lectura del sensor de Temperatura
  
  /* Código Loop */
  //tone(B_BUZ, 1500, 15);
  Duo.LCD_START();
  delay(160);
  /* Debugging */
  //Serial.println("IZQ: " + String(B_IZQ_R) + "\nARR: " + String(B_ARR_R) + "\nABJ: " + String(B_ABJ_R) + "\nDER: " + String(B_DER_R) + "\nSEL: " + String(B_SEL_R) + "\nSHF: " + String(B_SHF_R) + "\nVOL: " + String(B_VOL_R) + "\nTMP: " + String(gradosC) + "C\nPHS: " + String(B_PHS_R) + "\n");
}

