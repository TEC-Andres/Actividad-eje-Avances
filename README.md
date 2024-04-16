# Actividad-eje-Avances

Este repositorio es para la actividad eje de Daniela Mendez Rivas y Andrés Rodríguez Cantú<br />El proyecto en sí trata de una computadora con una aplicación educativa, un juego y datos del computador. El circuito tiene como objetivo enseñar matematicas a infantes con un aparato electronico, para hacer esto, utilizamos los siguiente componentes para poder hacer posible la computadora.<br />

### Componentes

| Componente    | Cantidad |
| -------- | ------- |
| Arduino UNO  | 1    |
| Tablero de circuito |  1  |
| Botones    | 6    |
| Potenciometro de 250 kΩ     | 1    |
| Resistencias de 1 kΩ  | 8    |
| Piezo    | 1    |
| Sensor de Temperatura    | 1    |
| Servomotor    | 1    |
| Fotoresistor    | 1    |
| LED Rojo    | 1    |
| Bateria de 9V    | 1    |

El plano en sí no es tan complicado, solo son varias conexiónes aprovechando al máximo la cantidad de PINS que contiene un arduino.

### Plano (En Vista esquematica)
![prototipo](https://github.com/TEC-Andres/Actividad-eje-Avances/assets/141695629/4b8c30dd-e2f3-4f12-8f12-56bdad3dddd0)

### Plano (En Vista de Tinkercad)
![image](https://github.com/TEC-Andres/Actividad-eje-Avances/assets/141695629/07c5c235-6fa0-4cd6-b226-2e32c41057fa)

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
La razón de esta función, es para replazar de manera sencilla de la memoria del LCD los caracteres especiales, esto debido a las limitantes del componente (el componente solo deja tener 8 caracteres especiales en memoria en cualquier momento deterimando, sin embargo, esto no significa que no podamos reemplazar la memoria de uno de los caracteres especiales por otra.) 

---
Creado por Andrés Rodríguez Cantú & Daniela Mendez Rivas<br /> Todos los derechos reservados al Tecnológico de Monterrey
