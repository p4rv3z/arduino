int ledPin = 8;//pin initial
void setup() {
  pinMode(ledPin,OUTPUT); //pin setup and led pin output
}

void loop() {
  digitalWrite(ledPin,HIGH);// led on
  delay(1000);              // wait 1 sec
  digitalWrite(ledPin,LOW); // led off 
  delay(1000);              // wait 1 sec
}
