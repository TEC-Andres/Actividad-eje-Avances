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
#       Creado:                   21/04/2024
#       Última Modificación:      22/04/2024
*/

#include "DUO.h"
#include "OS.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/* Definiciones */
#define BOTON_0 3860463360
#define BOTON_OK 3810328320

/* Cosas que tengo que poner si no, no sirve el código */
extern OS_DUO OS;
extern LiquidCrystal_I2C lcd;
extern long codigo; 

/* Paquetes */
byte* p_DUO[] = { nullptr, c_fuego_1, c_boton_inicial_1, c_boton_inicial_2, c_boton_inicial_3, c_suma_hover};

/* Texturas */
byte c_fuego_1[8] = { B00010, B00010, B00110, B00110, B10111, B11101, B10011, B01110 };
byte c_boton_inicial_1[8] = { B00000, B00000, B00111, B01000, B01101, B01001, B00111, B00000 };
byte c_boton_inicial_2[8] = { B00000, B00000, B11111, B10101, B10101, B10001, B11111, B00000 };
byte c_boton_inicial_3[8] = { B00000, B00000, B11100, B00110, B01010, B00010, B11100, B00000 };
byte c_suma_hover[8] = { B11111, B11011, B11011, B00000, B11011, B11011, B11111, B11111 };

/* Variables */
int page = 0;
int R1;
uint8_t resultado;
extern int frame3;
int varA;
int varB;

/* Funciones para el Menu */
void DUO_APP::START() {
  OS.crearCaracter(p_DUO, 1, 8, 0);

  lcd.clear();
  lcd.setCursor(2,0);
  lcd.write(1);
  lcd.print(" Duol-ino ");
  lcd.write(1);

  lcd.setCursor(7,1);
  for(int i=2; i<=4; i++) {
    lcd.write(i);
  }
}

void DUO_APP::SELECT() {
  static int POSx = 0;  // Frame inicial
  static int POSy = 1;  // Frame inicial
  if (POSy = 1 && page == 2) {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.write(5);
    lcd.print(" Sumas");
    lcd.setCursor(1,1);
    lcd.print("- Proximamente");
  }
}

/*void DUO_APP::SUMAS() {
  int varA = random(1, 10);
  int varB = random(1, 10);
  int resultado; // Define resultado to store player's input

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print(varA);
  lcd.print("+");
  lcd.print(varB);
  lcd.setCursor(1,1);
  lcd.print(resultado);
  
  // Assuming you have a way to capture player's input and store it in resultado variable
  // If resultado matches the correct sum, restart the game
  if (codigo == BOTON_OK && resultado == (varA + varB)) {
    SUMAS();
  } 
  // If resultado does not match the correct sum, change the page to 4
  else if (codigo == BOTON_OK && resultado != (varA + varB)) {
    page = 4;
  }
}*/
void DUO_APP::SUMAS(){

  R1 = varA + varB;

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print(varA);
  lcd.print("+");
  lcd.print(varB);
  lcd.setCursor(1,1);
  lcd.print(resultado +1);
}


void DUO_APP::PERDISTE() {
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Buen intento");
  delay(2000);
  page = 1;
}
