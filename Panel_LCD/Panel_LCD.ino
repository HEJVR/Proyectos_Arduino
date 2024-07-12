#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa el objeto LCD utilizando los pines GPIO definidos y las dimensiones (16 columnas x 2 filas)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int i;
int t = 200;
int t1 = 1000;
int t2 = 2000;
int t3 = 3000;
int t4 = 4000;
int t5 = 5000;


void setup() {
  // Inicializa el LCD
  lcd.init();

  lcd.backlight();    // Enciende la retroiluminación
  //lcd.noBacklight();  // Apaga la retroiluminación
}

void loop() {

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("hola");
  delay(3000);

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("soy hector villegas");
  delay(t2);

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("mucho gusto");
  delay(t2);

  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("soy diseñador, programador y desarrollador web en proceso");
  delay(t1);

  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("y tu?");
  delay(t1);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("cuentame?");
  delay(t1);

  for (i = 0; i < 20; i++) {
    lcd.scrollDisplayLeft();
    delay(t);
  }

  delay(t2);
}
