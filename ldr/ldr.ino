int ldr_pin = A0;//analog pin initial
/*10k ohm*/
void setup() {
  Serial.begin(9600);//initial serials
  //pinMode(ldr_pin,INPUT);//setup ldr pin as input//no need
}

void loop() {
  int value = analogRead(ldr_pin); //read value from ldr
  Serial.print(value);//print value
  Serial.println("");
}
