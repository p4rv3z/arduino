#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
void setup() {
  lcd.begin(16,2);
  lcd.print("HELLO WORLD!");
  delay(3000);
}
String val = "ABCDEFGHIJKLMNOP";
String val2 = "QRSTUVWXYZ123456";
void loop() {
  lcd.clear();
  //lcd.setCursor(0,0);
  //lcd.print("Values:");
  //lcd.setCursor(0,1);//column,row
  //int val = analogRead(A0);
  lcd.print(val);
  lcd.setCursor(0,1);
  lcd.print(val2);
  delay(1000);
}
