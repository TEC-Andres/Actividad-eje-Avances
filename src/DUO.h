/*
#       Sesión 30: Actividad eje
#       Andrés Rodríguez Cantú ─ Daniela Mendez Rivas
#
#       Copyright (C) Tecnologico de Monterrey
#
#       Archivo: DUO.h
#
#       Datos del programa (Sin contar la consola de debugging)
#       Almacenamiento: 15904 (49%) / 32,256 bytes
#       RAM (Globales): 1409 (68%) / 2,048 bytes
#
#       Creado:                   21/04/2024
#       Última Modificación:      22/04/2024
*/

#ifndef DUO_H
#define DUO_H

/* Librerias */
#include <Arduino.h>

/* Paquetes */
extern byte* p_DUO[];

/* Texturas */
extern byte c_fuego_1[8];
extern byte c_boton_inicial_1[8];
extern byte c_boton_inicial_2[8];
extern byte c_boton_inicial_3[8];
extern byte c_suma_hover[8];

/* Funciones */
class DUO_APP {
public:
  void START();
  void SELECT();
  void SUMAS();
  void PERDISTE();
};

#endif
