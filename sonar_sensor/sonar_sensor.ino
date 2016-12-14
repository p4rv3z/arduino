/*
 *#Sonar Sensor
 *@Author Parvez
 *@Date 19 July 2016
 */
int trigPin = 2;//Tring Pin of Sonar (Digital Pin)
int echoPin = 3;//Echo Pin of Sonar (Digital Pin)
void setup() {
  Serial.begin(9600); // begin serial communitication
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
}

void loop() {
  long flag = object();
  if(flag<20){
    
  }else{
    Serial.print (flag);
    Serial.print ( " CM!\n");// print out the distance in centimeters.
  }
  
}

//sonar distance
long object(){
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
