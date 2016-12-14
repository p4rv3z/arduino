void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
 // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  int val = value(sensorValue);
  // print out the value you read:
  Serial.print(sensorValue);
   Serial.print(" :: ");
  Serial.println(val);
  delay(2000);        // delay in between reads for stability

}
int value(int x){
  if(x>500){//black
    return 0;
  }else{
    return 1;//white
  }
  
}

