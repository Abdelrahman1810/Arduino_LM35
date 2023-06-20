#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define LM35 A0
int value = 0, T = 0;
float volt = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(LM35, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Temp = ");
}

void loop() {
  // Equation 
  // V out = T * 10mV / C
  // V out from 0 --> 5v
  // V out scale 0 --> 1023

  value = analogRead(LM35);
  delay(500);
  volt = (5.0/1023.0) * value; 
  T = volt * 100;

  lcd.setCursor(10,0);
  lcd.print(T);
  lcd.print(" C");
}


