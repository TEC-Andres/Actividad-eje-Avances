/*
#       Sesión 30: Actividad eje
#       Andrés Rodríguez Cantú ─ Daniela Mendez Rivas
#
#       Copyright (C) Tecnologico de Monterrey
#
#       Archivo: CONFIG.cpp
#
#       Datos del programa (Sin contar la consola de debugging)
#       Almacenamiento: 15904 (49%) / 32,256 bytes
#       RAM (Globales): 1409 (68%) / 2,048 bytes
#
#       Creado:                   22/04/2024
#       Última Modificación:      22/04/2024
*/

#include "OS.h"
#include "CONFIG.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/* Cosas que tengo que poner si no, no sirve el código */
extern LiquidCrystal_I2C lcd;
extern int backlight;
extern int B_VOL_R;
extern int BOTON_R;
extern float B_PHS_R;

void CONFIG_APP::START() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("VOL: ");
  lcd.print(B_VOL_R);
  lcd.print(" BLG: ");
  lcd.print(backlight % 2);
  lcd.setCursor(0,1);
  lcd.print("PHS: ");
  lcd.print(B_PHS_R);
/*
int B_VOL_R = analogRead(B_VOL);  // Lectura del potenciometro
int BOTON_R = digitalRead(BOTON);
float B_PHS_R = analogRead(B_PHS);  // [Tinkercad] Lectura del sensor de Temperatura
*/

}
