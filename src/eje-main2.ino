/*
#       Sesión 30: Actividad eje
#       Andrés Rodríguez Cantú ─ Daniela Mendez Rivas
#
#       Copyright (C) Tecnologico de Monterrey
#
#       Archivo: eje-main.ino
#
#       Datos del programa (Sin contar la consola de debugging)
#       Almacenamiento: 15904 (49%) / 32,256 bytes
#       RAM (Globales): 1409 (68%) / 2,048 bytes
#
#       Creado:                   08/01/2024
#       Última Modificación:      22/04/2024
*/

/* Librerias de componentes */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <IRremote.h>

/* Librerias de Aplicaciones */
#include "OS.h"
#include "DUO.h"
#include "CONFIG.h"

OS_DUO OS;
DUO_APP DUO;
CONFIG_APP CONFIG;

/* Definiciones de componentes */
#define B_VOL A0
#define B_TMP 3
#define B_PHS A1
#define LED 9
#define B_BUZ 12
#define BOTON 13

#define BOTON_ARRIBA 3877175040
#define BOTON_ABAJO 2907897600
#define BOTON_IZQUIERDA 4144561920
#define BOTON_DERECHA 2774204160
#define BOTON_ASTERISCO 3910598400
#define BOTON_GATO 4061003520
#define BOTON_OK 3810328320
#define BOTON_1 3125149440
#define BOTON_2 3108437760
#define BOTON_3 3091726080
#define BOTON_4 3141861120
#define BOTON_5 3208707840
#define BOTON_6 3158572800
#define BOTON_7 4161273600
#define BOTON_8 3927310080
#define BOTON_9 4127850240
#define BOTON_0 3860463360

/* Setup de librerias */
Servo servo;
IRrecv controlR(2);
LiquidCrystal_I2C lcd(0x27, 20, 4);

/* Variable Globales */
bool recibe;
uint8_t backlight = 1;
uint8_t backlight2 = 1;
uint32_t codigo;
int POSx;
int POSy = 1;
int frame3 = 0;

/* Variables lecturas */
int B_VOL_R;
int BOTON_R;
float B_PHS_R;

/* Variables Externas */
extern int frame;
extern int page;
extern uint8_t resultado;
extern int R1;
extern int varA;
extern int varB;

/* Setup */
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(B_BUZ, OUTPUT);
  pinMode(BOTON, INPUT);
  pinMode(B_VOL, INPUT);
  lcd.init();
  lcd.backlight();
  servo.attach(11);
  controlR.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  /* Lectura del Hardware */
  B_VOL_R = analogRead(B_VOL);  // Lectura del potenciometro
  BOTON_R = digitalRead(BOTON);
  B_PHS_R = analogRead(B_PHS);  // [Tinkercad] Lectura del sensor de Temperatura
  int B_VOL_M = map(B_VOL_R, 0, 1023, 0, 2);

  /* Componentes porque si */
  digitalWrite(LED, B_VOL_M);

  /* Código Loop */
  OS.LCD_START();
  recibe = controlR.decode();

  if (frame == 100) {
    frame = 50;
  }

  if (frame == 200) {
    frame = 105;
  }

  if (BOTON_R == 1) {
    backlight++;
  }

  if (frame >= 102 && frame <= 200 && page == 3) {
    frame3++;
  }

  if (frame3 == 1) {
      varA = random(1, 10);
      varB = random(1, 10);
  }

  if (frame >= 300) {
    CONFIG.START();
  }

  if (frame == 400) {
    frame == 300;
  }

  if (backlight % 2 == 0) {
    lcd.noBacklight();
  } else if (backlight % 2 == 1) {
    lcd.backlight();
  }

  if (recibe == true) {  // Inicio del encabezado del IR
    codigo = controlR.decodedIRData.decodedRawData;
    if (codigo == BOTON_ARRIBA) {
      if (frame >= 27) {
        OS.crearCaracter(p_icons, 5, 7, 4);
        POSy += 1;
        tono();
      }
    }
    if (codigo == BOTON_ABAJO) {
      if (frame >= 27) {
        OS.crearCaracter(p_icons, 5, 7, 4);
        POSy -= 1;
        tono();
      }
    }

    if (codigo == BOTON_OK) {
      if (frame >= 27 && frame <= 100 && POSy == 1) {
        lcd.clear();
        frame = 101;
        tono();
      }
    }

    if (codigo == BOTON_OK) {
      if (frame >= 27 && frame <= 100 && POSy == 2) {
        frame = 300;
        tono();
      }
    }

    /* Duo-ino */

    if (frame >= 101 && frame <= 200) {
      DUO.START();
      if (codigo == BOTON_OK && page <= 2) {
        page++;
      }
      if (page == 1 && (frame >= 105 && frame <= 200)) {
        DUO.START();
      }
      if (page == 2 && (frame >= 105 && frame <= 200)) {
        DUO.SELECT();
      }
      if (page == 3 && (frame >= 105 && frame <= 200)) {
        DUO.SUMAS();
      } 
      if (page == 4 && (frame >= 105 && frame <= 200)) {
        DUO.PERDISTE();
      } 

      if (codigo == BOTON_ARRIBA && page == 3 && ((frame >= 105 && frame <= 200))) {
        resultado++;
      } else if (codigo == BOTON_ABAJO && page == 3 && ((frame >= 105 && frame <= 200))) {
        resultado--;
      }

      if (codigo == BOTON_0 && (resultado == R1)) {
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Bien hecho");
        delay(500);
        resultado = 0;
        DUO.SUMAS();
        varA = random(1,10);
        varB = random(1,10);
      } else if (codigo == BOTON_0 && (resultado != R1)) {
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Buen intento");
      }
      
      /*if (codigo == BOTON_OK && page == 1 && (frame >= 105 && frame <= 200)) {
        lcd.clear();
        page = 2;
        DUO.SELECT();
      }
      if (codigo == BOTON_OK && page == 2 && (frame >= 105 && frame <= 200)) {
        lcd.clear();
        page = 3;
        DUO.SUMAS();
      }*/
    }

    /* Menú principal */
    if (codigo == BOTON_GATO && frame >= 27) {
      lcd.clear();
      frame = 11;
    }
  }

  if (POSy == 3 && (frame >= 27 && frame <= 200)) {
    POSy = 1;
  }
  if (POSy == 0 && (frame >= 27 && frame <= 200)) {
    POSy = 2;
  }


  // Efecto de "Hover" en OS
  if (frame >= 27 && frame <= 100) {
    lcd.createChar(POSy + 4, p_hover_icons[(POSy)]);
  }

  if (frame3 == 9) {
    frame3 = 5;
  }

controlR.resume();
delay(120);
Serial.println(frame);

}

void tono() {
  digitalWrite(B_BUZ, HIGH);
  delay(50);
  digitalWrite(B_BUZ, LOW);
}
