/*
#       Sesión 30: Actividad eje
#       Andrés Rodríguez Cantú ─ Daniela Mendez Rivas
#
#       Copyright (C) Tecnologico de Monterrey
#
#       Archivo: OS.h
#
#       Datos del programa (Sin contar la consola de debugging)
#       Almacenamiento: 7658 (23%) / 32,256 bytes
#       RAM (Globales): 734 (35%) / 2,048 bytes
#
#       Creado:                   04/04/2024
#       Última Modificación:      15/04/2024
*/

#ifndef OS_H
#define OS_H

/* Librerias */
#include <Arduino.h>

/* Paquetes */
extern byte* p_DUO_OS[];
extern byte* p_OS_BARRA[];
extern byte* p_icons[];

/* Texturas */
extern byte c_DUO_OS_1[8];
extern byte c_DUO_OS_2[8];
extern byte c_DUO_OS_3[8];
extern byte c_DUO_OS_4[8];
extern byte c_DUO_OS_5[8];
extern byte c_DUO_OS_6[8];
extern byte c_DUO_OS_7[8];
extern byte c_DUO_OS_8[8];
extern byte c_OS_BARRA_1[8];
extern byte c_OS_BARRA_2[8];
extern byte c_OS_BARRA_3[8];
extern byte c_OS_BARRA_4[8];
extern byte c_DUO_ICO[8];
extern byte c_COOKIE_ICO[8];
extern byte c_CONFIG_ICO[8];

/* Funciones */
class OS_DUO {
public:
  void LCD_START();
  void crearCaracter(byte* CARACTER[], uint8_t INICIO, uint8_t LIMITE, uint8_t CORRECION);
  void animar(byte* ANIMACION[], int &currentFrame, uint8_t LIMITE, uint8_t MEMORIAVAL);
};

#endif
