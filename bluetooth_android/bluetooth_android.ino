String value="";
String temp = "*1005#";
void setup() {
  Serial.begin(9600);
}

void loop() {
if(Serial.available()){
  String val = "";
  while(Serial.available()){
    char command = Serial.read();
    val+=command;
  }  
  value=val;
  val="";
  delay(10);//its necessary for get all data
 }
 else{
 value="";
 }
 if(value!=""){
  Serial.println(value);
 }
 if(value=="T"){
  Serial.print(temp);
  value="";
 }
}
