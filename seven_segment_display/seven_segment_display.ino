/*
 * http://circuitdigest.com/article/7-segment-display
 * http://circuitdigest.com/microcontroller-projects/digital-dice-using-arduino 
*/

int a = 2;//-
int b = 3;//|
int c = 4;//|
int d = 5;//-
int e = 6;//|
int f = 7;//|
int g = 8;//=
int h = 9;//.
void setup(){
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(h,OUTPUT);
}
void loop(){
  digitalWrite(b,HIGH);
}

