/*thermistor lm35*/
int thermistorPin =A0;
void setup() {
  Serial.begin(9600);
 // pinMode(thermistorPin,INPUT);

}

void loop() {
  int value =analogRead(thermistorPin);
  Serial.print(value);
  Serial.println("");
}
