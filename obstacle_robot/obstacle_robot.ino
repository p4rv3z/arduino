#include <AFMotor.h>

#define trigPin 22 // define the pins of your sensor
#define echoPin 23 
AF_DCMotor motor1(1,MOTOR12_8KHZ);//1khz,8khz,64khz
AF_DCMotor motor2(2,MOTOR12_8KHZ);
AF_DCMotor motor3(3,MOTOR12_8KHZ);
AF_DCMotor motor4(4,MOTOR12_8KHZ);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // begin serial communitication  
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(object()>20){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  }else{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }
}

int object(){
long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  Serial.print ( distance);
  Serial.print ( " CM!");// print out the distance in centimeters.
  return distance;
}


