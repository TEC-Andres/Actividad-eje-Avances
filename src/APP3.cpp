#include "APP3.h"

/* Animaciones */
byte* a_fuego[] = {nullptr, c_fuego_1, c_fuego_2, c_fuego_3, c_fuego_4, c_fuego_5};

/* Caracteres especiales */
byte c_fuego_1[8] = { B00010, B00010, B00110, B00110, B10111, B11101, B10011, B01110 };
byte c_fuego_2[8] = { B01000, B01010, B00010, B00110, B10111, B11101, B10011, B01110 };
byte c_fuego_3[8] = { B00100, B00100, B01100, B01110, B11011, B10111, B10001, B01110 };
byte c_fuego_4[8] = { B00010, B01010, B01000, B01100, B11101, B10111, B11001, B01110 };
byte c_fuego_5[8] = { B01000, B01000, B01100, B01100, B11101, B10111, B11001, B01110 };

byte c_boton_inicial_1[8] = { B00000, B00000, B00111, B01000, B01101, B01001, B00111, B00000 };
byte c_boton_inicial_2[8] = { B00000, B00000, B11111, B10101, B10101, B10001, B11111, B00000 };
byte c_boton_inicial_3[8] = { B00000, B00000, B11100, B00110, B01010, B00010, B11100, B00000 };
