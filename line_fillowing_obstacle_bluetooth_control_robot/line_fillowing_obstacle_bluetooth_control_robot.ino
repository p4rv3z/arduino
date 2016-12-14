#include <AFMotor.h>
#define HC06 Serial3
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
int trigPin = 22;//Tring Pin of Sonar (Digital Pin)
int echoPin = 23;//Echo Pin of Sonar (Digital Pin)
char flag='#';
String changeModeCondition ="";
int s = 0;
void setup() {
  Serial.begin(9600);
  HC06.begin(9600);
  pinMode(ir_led,OUTPUT);
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  speedSetup(s);//default speed
}

void loop() {
  int distance = objDistance();
  if(HC06.available()){
    char data = HC06.read();
    if(data=='*'){
      flag = '*';
    }else if(data=='#'){
      flag = '#';
    }else if(data=='+'){
     if(s<250){
      s+=3;     
     }
     Serial.print("Speed: ");
     Serial.println(s);
     speedSetup(s);
    }else if(data=='-'){
      if(s>5){
      s-=3;
     }
     Serial.print("Speed: ");
     Serial.println(s);
     speedSetup(s);
    }
    if(distance<20&&flag=='#'){
      //obstacle find  object
    ledOff();
    //todo relase motor
    relaseAll();
  }else if(distance>20&&flag=='#'){
    //bluetooth activated
    if(data=='1'){
      Serial.println("bluetooth forward");
       _forward();
    }else if(data=='2'){
      Serial.println("bluetooth back");
      _back();
    }else if(data=='3'){
      Serial.println("bluetooth right");
      _right();
    }else if(data=='4'){
      Serial.println("bluetooth left");
      _left();
    }else{
      //release all motor
      Serial.println("bluetooth release motor");
      relaseAll();
    }
  }
  }else if(!HC06.available()&&flag=='#'){
    Serial.println("!HC06.available()&&flag=='#'");
    relaseAll();
  }else{
    
  }
  //line
  if(distance<20&&flag=='*'){
      //obstacle find  object
    ledOff();
    //todo relase motor
    relaseAll();
  }else if(distance>20&&flag=='*'){ 
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
      }else if(ir_values[0]==1&&ir_values[1]==1&&ir_values[2]==0&&(ir_values[3]==0||ir_values[4]==0)){//1110||0  <<Right>>
        changeMode("right1");
        _right();
        Serial.println("Right");
        changeModeCondition="right1";
      }else if((ir_values[0]==0||ir_values[1]==0) && ir_values[2]==1&&ir_values[3]==1&&ir_values[4]==1){//0||0111 <<Left>>
        changeMode("left");
        _left();
        Serial.println("Left");
        changeModeCondition="left";
      }else if((ir_values[0]==0||ir_values[1]==0) && ir_values[2]==0&&ir_values[3]==1&&ir_values[4]==1){//0||0111 <<Left>>
        changeMode("left1");
        _left();
        Serial.println("Left");
        changeModeCondition="left1";
      }else if(ir_values[0]==1 && ir_values[1]==1 && ir_values[2]==1&&ir_values[3]==1&&ir_values[4]==1){//11111 <<do nothing>>
//        changeMode("forward1");
//        _forward();
//        Serial.println("Forward");
//        changeModeCondition="forward1";
  }else{
    //todo
  }
//delay(5);
}
}


//change mode
void changeMode(String x){
  if(changeModeCondition!=x){
    //relase all
    relaseAll();
    Serial.println("Mode change relase all");
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
    ledOff();
  }else if(i[0]==0&&i[1]==0&&i[2]==0&&i[3]==0&&i[4]==0){
    ledOff();
  }
  else{
   ledOn();
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
//sonar distance
int objDistance(){
long duration, distance; // start the scan
  //digitalWrite(trigPin, LOW);  
  delayMicroseconds(10); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //pulseIn(echoPin,LOW);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
//  Serial.print ( distance);
//  Serial.print ( " CM!\n");// print out the distance in centimeters.
  return distance;
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
