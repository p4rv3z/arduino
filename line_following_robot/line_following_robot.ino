#include <AFMotor.h>
//right side
AF_DCMotor motor1(1,MOTOR12_64KHZ);//1khz,8khz,64khz
AF_DCMotor motor3(3,MOTOR12_64KHZ);
//left side
AF_DCMotor motor2(2,MOTOR12_64KHZ);
AF_DCMotor motor4(4,MOTOR12_64KHZ);
int ir_arrays_pin[] = {A8,A9,A10,A11,A12};
int x = sizeof(ir_arrays_pin)/sizeof(int);
int ir_values[5];
int ir_led = 53;
boolean flag = true;
String changeModeCondition ="";
int maxSpeed = 255;

void setup() {
  Serial.begin(9600);
  pinMode(ir_led,OUTPUT);
  speedSetup(maxSpeed);
  delay(500);
}

void loop() {
  if(flag){ //Serial.print("true"); 
    //Right A4||A3||A2||A1||A0 Left  
    for(int i = 0; i<x;i++){
     ir_values[i]=value(analogRead(ir_arrays_pin[i]));
     //Serial.print(ir_values[i]);
    }
    irLed(ir_values);// LED
    ////IR CONTROLLING 
      if(ir_values[0]==1&&ir_values[1]==1&&ir_values[2]==0&&ir_values[3]==1&&ir_values[4]==1){//11011 <<Forward>>
        changeMode("forward");
        _forward();
        Serial.println("Forward");
        changeModeCondition="forward";
      }else if(ir_values[0]==1&&ir_values[1]==1&&ir_values[2]==1&&(ir_values[3]==0||ir_values[4]==0)){//1110||0  <<Right>>
        changeMode("right");
        _right();
        Serial.println("Right");
        changeModeCondition="right";
      }else if((ir_values[0]==0||ir_values[1]==0) && ir_values[2]==1&&ir_values[3]==1&&ir_values[4]==1){//0||0111 <<Left>>
        changeMode("left");
        _left();
        Serial.println("Left");
        changeModeCondition="left";
      }else if(ir_values[0]==1 && ir_values[1]==1 && ir_values[2]==1&&ir_values[3]==1&&ir_values[4]==1){//11111 <<Back>>
//        changeMode("forward1");
//        _forward();
//        Serial.println("Forward");
//        changeModeCondition="forward1";
      }else{
        //todo
      }
    
  }else{ //Serial.print("false");
    
  }
}

//convert the values of ir and return analog signal 0 or 1 
int value(int x){
  if(x<100){//white
    return 1;
  }else{
    return 0;//black
  }
}
//if robot is in right path then led will on other wise it will off
void irLed(int i[]){
  if(i[0]==1&&i[1]==1&&i[2]==1&&i[3]==1&&i[4]==1){
    ledOn();
  }else if(i[0]==0&&i[1]==0&&i[2]==0&&i[3]==0&&i[4]==0){
    ledOn();
  }
  else{
   ledOff();
  }
}
//path led on
void ledOn(){
  digitalWrite(ir_led,HIGH);
}
//path led off
void ledOff(){
   digitalWrite(ir_led,LOW);
}
//change mode
void changeMode(String x){
  if(changeModeCondition!=x){
    //relase all
    relaseAll();
    Serial.println("Mode change relase all");
  }
}
//relase all motor
void relaseAll(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
//speedSetup
void speedSetup(int s){
  motor1.setSpeed(s);
  motor3.setSpeed(s);
  motor2.setSpeed(s);
  motor4.setSpeed(s);
}
//forward 
void _forward(){
  //forward
  motor1.run(FORWARD);
  motor3.run(FORWARD);
  //forward
  motor2.run(FORWARD);
  motor4.run(FORWARD);
}
//
void _right(){
  //forward
  motor1.run(BACKWARD);
  motor3.run(BACKWARD);
  //forward
  motor2.run(FORWARD);
  motor4.run(FORWARD);
}
//
void _left(){
  //forward
  motor1.run(FORWARD);
  motor3.run(FORWARD);
  //forward
  motor2.run(BACKWARD);
  motor4.run(BACKWARD);
}
void _back(){
  //forward
  motor1.run(BACKWARD);
  motor3.run(BACKWARD);
  //forward
  motor2.run(BACKWARD);
  motor4.run(BACKWARD);

}
