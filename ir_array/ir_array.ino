int ir_arrays_pin[] = {A8,A9,A10,A11,A12};
int x = sizeof(ir_arrays_pin)/sizeof(int);
int ir_values[5];
void setup() {
  Serial.begin(9600);
  delay(5);
}

void loop() {
  for(int i = 0; i<x;i++){
   ir_values[i]=analogRead(ir_arrays_pin[i]);
    prnt(i,ir_values[i]);
  }
  Serial.println();
//delay(1000);
}

//convert the values of ir and return analog signal 0 or 1 
int value(int x){
  if(x<100){//white
    return 1;
  }else{
    return 0;//black
  }
}
//test print
void prnt(int i,int x){
  Serial.print("A");
  Serial.print(i);
  Serial.print(": ");
  Serial.print(value(x));
  Serial.print("cm ");
}

