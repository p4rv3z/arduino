/*pwm */
int buzzerPin = 9;//buzzer pin initialize 
void setup() {
  pinMode(buzzerPin,OUTPUT);

}

void loop() {
  tone(buzzerPin,65000);//tone on ,frequency 0 to 65000 on mega or 20000 uno
  delay(5000);//wait 5 sec
  noTone(buzzerPin);//tone off
  delay(3000);//wait 3 sec
}
