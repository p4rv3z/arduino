int led_pins[] = {8,9,10,11,12};// led pins initial
void setup() {
  for(int i = 0; i<5;i++){ // for loop for initital all pins
    pinMode(led_pins[i],OUTPUT);//pin setup as output
  }
}

void loop() {
  for(int i = 0; i<5;i++){// for loop for on all light 
    digitalWrite(led_pins[i],HIGH);//light on
    delay(500); //wait 0.5 sec
  }
  
  delay(500);// just wait for reverse
  
  for(int i = 4; i>=0;i--){// for loop for off all light 
    digitalWrite(led_pins[i],LOW);//light off
    delay(500); //wait 0.5 sec
  }

}
