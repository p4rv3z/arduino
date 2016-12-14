int led_pin = 9;//pin initial
/*pwm pins 3, 5, 6, 9, 10, and 11*/
void setup() {
  pinMode(led_pin,OUTPUT);//pin setup as output
}

void loop() {
  for(int i = 0; i<255;i+=5){// for loop for increasing fade
    analogWrite(led_pin,i);// increasing 5++
    delay(25);//wait 25 mili sec
  }
  for(int i = 255; i>=0;i-=5){// for loop for decreasing fade
    analogWrite(led_pin,i);// increasing 5--
    delay(25);//wait 25 mili sec
  }
}
