#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "APP0.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

int frame = 1;

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  title_screen();
  delay(160); // 6.25 FPS
}

void title_screen() {
  crearCaracter(DUO_OS, 8);
  lcd.setCursor(6,0);
  for(int i=1; i<=4; i++){
    lcd.write(i);
  }
  lcd.setCursor(6,1);
  for(int i=5; i<=8; i++){
    lcd.write(i);
  }
}

void crearCaracter(byte* CARACTER[], uint8_t LIMITE) {
  for (int i = 1; i <= LIMITE; i++) {
    lcd.createChar(i, CARACTER[i]);
  }
}

void animar(byte* ANIMACION[], int &currentFrame, uint8_t LIMITE, uint8_t MEMORIAVAL) {
  currentFrame++;
  if (currentFrame > LIMITE) {
    currentFrame = 1;
  }

  for (int i = 1; i <= LIMITE; i++) {
    lcd.createChar(MEMORIAVAL, ANIMACION[currentFrame]);
  }
}
