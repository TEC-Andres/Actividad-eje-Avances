#ifndef DUO_H
#define DUO_H

/* Librerias */
#include <Arduino.h>

/* Paquetes */
extern byte* p_DUO_OS[];

/* Texturas */
extern byte c_DUO_OS_1[8];
extern byte c_DUO_OS_2[8];
extern byte c_DUO_OS_3[8];
extern byte c_DUO_OS_4[8];
extern byte c_DUO_OS_5[8];
extern byte c_DUO_OS_6[8];
extern byte c_DUO_OS_7[8];
extern byte c_DUO_OS_8[8];

/* Funciones */
class DUO_OS {
public:
  void LCD_START();
  void crearCaracter(byte* CARACTER[], uint8_t LIMITE);
  void animar(byte* ANIMACION[], int &currentFrame, uint8_t LIMITE, uint8_t MEMORIAVAL);
};

#endif
