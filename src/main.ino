#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "texturas.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte* charArrays[] = {nullptr, c_fuego_1, c_fuego_2, c_fuego_3, c_fuego_4, c_fuego_5};

int frame = 1;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  title_screen();
  button_initial();

  Serial.println("Frame " + String(frame));
  delay(160); // 6.25 FPS
}

void title_screen() {
  lcd.setCursor(2, 0);
  lcd.write(1);
  lcd.print(" Duol-ino ");
  lcd.write(1);
  animation_type_1(charArrays, frame);
}

void button_initial() {
  button_texture();
  lcd.setCursor(7, 1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
}

void button_texture() {
  lcd.createChar(2, c_boton_inicial_1);
  lcd.createChar(3, c_boton_inicial_2);
  lcd.createChar(4, c_boton_inicial_3);
}

void increase_frame(int limit) {
  frame++;
  if (frame > limit) {
    frame = 1;
  }
}

void animation_type_1(byte* ANIMACION[], int currentFrame) {
  // Use the currentFrame value to determine which animation to display
  lcd.createChar(1, ANIMACION[currentFrame]);
}
