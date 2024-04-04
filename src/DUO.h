/*
#       Sesión 30: Actividad eje
#       Andrés Rodríguez Cantú ─ Daniela Mendez Rivas
#
#       Copyright (C) Tecnologico de Monterrey
#
#       Archivo: DUO.h
#
#       Datos del programa (Sin contar la consola de debugging)
#       Almacenamiento: 7198 (22%) / 32,256 bytes
#       RAM (Globales): 612 (29%) / 2,048 bytes
#
#       Creado:                   04/04/2024
#       Última Modificación:      04/04/2024
*/

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
