# Actividad-eje-Avances

Este repositorio es para la actividad eje de Daniela Mendez Rivas y Andrés Rodríguez Cantú<br />El proyecto en sí trata de una computadora con una aplicación educativa, un juego y datos del computador. El circuito tiene como objetivo enseñar matematicas a infantes con un aparato electronico, para hacer esto, utilizamos los siguiente componentes para poder hacer posible la computadora.<br />

### Componentes

| Nombre   | Componente    | Cantidad |
| --- | ----------- | --------------- |
| U1 |	1 |	Arduino Uno R3 |
| U2 |	1	| PCF8574-based, 39 (0x27) LCD 16 x 2 (I2C) |
| Rpot1	| 1	| 250 kΩ Potentiometer |
| R2, R4, R6, R8, R9 |	5 |	1 kΩ Resistor |
| PIEZO1 |	1	| Piezo |
| U3	| 1	| Temperature Sensor [TMP36] |
| SERVO1	| 1 |	Positional Micro Servo |
| R1 |	1 |	Photoresistor |
| BAT1 |	1 |	9V Battery |
| D1 |	1	| Green LED |
| S1 |	1 |	Pushbutton |
| U4 |	1	| IR sensor |

El plano en sí no es tan complicado, solo son varias conexiónes aprovechando al máximo la cantidad de PINS que contiene un arduino.

### Plano (En Vista esquematica)
![prototipo (2)_page-0001](https://github.com/TEC-Andres/Actividad-eje-Avances/assets/141695629/9d84253d-5c20-4bf0-bea2-4fc0deb38c38)

### Plano (En Vista de Tinkercad)
![Captura de pantalla 2024-04-22 125333](https://github.com/TEC-Andres/Actividad-eje-Avances/assets/141695629/38ea93b1-2fd4-4b5c-b68b-dbe6d8f1eb9d)

## Funciones interesantes 
En el código, se encuentran algunos pedazos de código que son de ardua importancia para el funcionamiento del software, entre estas funciones esta la función `crearCaracter`, que toma cuatro argumentos como base. El primero es de tipo byte con un puntero haciendo conexión los paquetes de caracteres especiales, mientras que el resto de los argumentos son integros positivos de 8 bits (es decir numeros entre el 0 al 256)

### Función (En OS.cpp)
```cpp
void OS_DUO::crearCaracter(byte* CARACTER[], uint8_t INICIO, uint8_t LIMITE, uint8_t CORRECION) {
  for (int i = INICIO; i <= LIMITE; i++) {
    lcd.createChar(i, CARACTER[(i-CORRECION)]);
  }
}
```
La razón de esta función, es para replazar de manera sencilla de la memoria del LCD los caracteres especiales, esto debido a las limitantes del componente (el componente solo deja tener 8 caracteres especiales en memoria en cualquier momento deterimando, sin embargo, esto no nos impide que podamos reemplazar la memoria de uno de los caracteres especiales por otra memoria que esté guardada en el arduino.) 

---
Creado por Andrés Rodríguez Cantú & Daniela Mendez Rivas<br /> Todos los derechos reservados al Tecnológico de Monterrey
