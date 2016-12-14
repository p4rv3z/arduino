int motorPin = 9;//pwm
void setup(){
  
}
void loop(){
  analogWrite(motorPin,255);//motor on
  delay(5000);
  analogWrite(motorPin,0);//motor off
  delay(3000);
}

