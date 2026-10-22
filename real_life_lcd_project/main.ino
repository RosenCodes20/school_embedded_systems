
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

unsigned long startTime;

void setup() {
  lcd.begin(16, 2);
  startTime = millis();

  lcd.setCursor(0, 0);
  lcd.print("PROGRAMIRAM OT:");
}

void loop() {
  unsigned long sekundi = (millis() - startTime) / 1000;

  int chas = (sekundi / 3600) % 24;
  int minuti = (sekundi / 60) % 60;
  int sek = sekundi % 60;

  lcd.setCursor(0, 1);

  if (chas < 10) lcd.print("0");
  lcd.print(chas);
  lcd.print(":");

  if (minuti < 10) lcd.print("0");
  lcd.print(minuti);
  lcd.print(":");

  if (sek < 10) lcd.print("0");
  lcd.print(sek);

  lcd.print("          ");

  delay(200);
}
