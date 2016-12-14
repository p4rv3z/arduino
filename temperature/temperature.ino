/*10k thermistor*/
int thermistor_pin = A0;
void setup() {
  Serial.begin(9600);
  pinMode(thermistor_pin,INPUT);

}

void loop() {
  int value = analogRead(thermistor_pin);
  Serial.print(value);
  Serial.println("");
}
