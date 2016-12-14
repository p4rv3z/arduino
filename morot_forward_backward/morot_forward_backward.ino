/*
* http://communityofrobots.com/tutorial/kawal/how-drive-dc-motor-using-l293d-arduino
*/
int motorpin1 = 3;                  //define digital output pin no.

int motorpin2 = 4;                  //define digital output pin no.

void setup () {

  pinMode(motorpin1,OUTPUT);        //set pin 3 as output

  pinMode(motorpin2,OUTPUT);        // set pin 4 as output

}

void loop () {

  digitalWrite(motorpin1,LOW);

  digitalWrite(motorpin2,HIGH);
  delay(5000);
  digitalWrite(motorpin1,HIGH);

  digitalWrite(motorpin2,LOW);
  delay(5000);

}
