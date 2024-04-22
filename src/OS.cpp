/*
#       Sesión 30: Actividad eje
#       Andrés Rodríguez Cantú ─ Daniela Mendez Rivas
#
#       Copyright (C) Tecnologico de Monterrey
#
#       Archivo: OS.cpp
#
#       Datos del programa (Sin contar la consola de debugging)
#       Almacenamiento: 15904 (49%) / 32,256 bytes
#       RAM (Globales): 1409 (68%) / 2,048 bytes
#
#       Creado:                   04/04/2024
#       Última Modificación:      21/04/2024
*/

#include "OS.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/* Cosas que tengo que poner si no, no sirve el código */
extern LiquidCrystal_I2C lcd;

/* Paquetes */
byte* p_DUO_OS[] = { nullptr, c_DUO_OS_1, c_DUO_OS_2, c_DUO_OS_3, c_DUO_OS_4, c_DUO_OS_5, c_DUO_OS_6, c_DUO_OS_7, c_DUO_OS_8 };
byte* p_icons[] = { nullptr, c_DUO_ICO, c_CONFIG_ICO };
byte* p_hover_icons[] = { nullptr, c_HOVER_DUO_ICO, c_HOVER_CONFIG_ICO };

/* Texturas */
byte c_DUO_OS_1[8] = { B00000, B00000, B00011, B00111, B01000, B01001, B11001, B11001 };
byte c_DUO_OS_2[8] = { B00111, B11111, B11111, B11111, B11100, B01100, B10100, B10100 };
byte c_DUO_OS_3[8] = { B11100, B11111, B11111, B11111, B10110, B10100, B10100, B10100 };
byte c_DUO_OS_4[8] = { B00000, B00000, B11000, B11100, B00110, B11010, B11011, B11011 };
byte c_DUO_OS_5[8] = { B11001, B11001, B01001, B01000, B00111, B00011, B00001, B00000 };
byte c_DUO_OS_6[8] = { B10100, B10100, B01100, B11110, B11111, B11111, B11111, B00111 };
byte c_DUO_OS_7[8] = { B10100, B10100, B10100, B01110, B11111, B11111, B11111, B11110 };
byte c_DUO_OS_8[8] = { B11011, B11011, B11010, B00110, B11100, B11000, B00000, B00000 };
byte c_DUO_ICO[8] = { B00100, B00100, B01100, B01110, B11011, B10111, B10001, B01110 };
byte c_CONFIG_ICO[8] = { B00000, B01110, B10111, B11010, B01111, B11101, B01110, B00000 };
byte c_HOVER_DUO_ICO[8] = { B11011, B11011, B10011, B10001, B00100, B01000, B01110, B10001 };
byte c_HOVER_CONFIG_ICO[8] = { B11111, B10001, B01000, B00101, B10000, B00010, B10001, B11111 };

/* Variables */
int frame = 0;

/* Funciones para la creación de caracteres */
void OS_DUO::crearCaracter(byte* CARACTER[], uint8_t INICIO, uint8_t LIMITE, uint8_t CORRECION) {
  for (int i = INICIO; i <= LIMITE; i++) {
    lcd.createChar(i, CARACTER[(i - CORRECION)]);
  }
}

void OS_DUO::animar(byte* ANIMACION[], int& currentFrame, uint8_t LIMITE, uint8_t MEMORIAVAL) {
  currentFrame++;
  if (currentFrame > LIMITE) {
    currentFrame = 1;
  }

  for (int i = 1; i <= LIMITE; i++) {
    lcd.createChar(MEMORIAVAL, ANIMACION[currentFrame]);
  }
}

/* Funciones para el Menu */
void OS_DUO::LCD_START() {
  static int POSx = 0;  // Frame inicial
  static int POSy = 1;  // Frame inicial

  frame++;

  if (frame >= 0 && frame <= 10) {
    crearCaracter(p_DUO_OS, 1, 8, 0);
    lcd.setCursor(6, 0);
    for (int i = 1; i <= 4; i++) {
      lcd.write(i);
    }
    lcd.setCursor(6, 1);
    for (int i = 5; i <= 8; i++) {
      lcd.write(i);
    }
  }

  if (frame == 11) {
    lcd.clear();
  }

  if (frame >= 15 && frame <= 25) {
    lcd.setCursor(4, 0);
    lcd.print("Loading...");
  }

  if (frame == 26) {
    lcd.clear();
    crearCaracter(p_icons, 5, 7, 4);
  }

  if (frame >= 27 && frame <= 100) {
    POSx = 0;
    lcd.setCursor(1, 0);
    lcd.write(5);
    lcd.print(" Duo-ino [Math]");
    lcd.setCursor(1, 1);
    lcd.write(6);
    lcd.print(" Configuracion");
  }
}
