#include <Arduino.h>
#include <Servo.h>


Servo servo1; //deg =  0
Servo servo2; //deg=  120
int output1 = 0;
int output2 = 0;
int max_rot = 45;
int offset1 = 0;
int offset2 = 0;

void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  // add 2 digital out pins
  Serial.begin(9600);
  servo1.attach(69);
  servo2.attach(69);

  servo1.write(0);
  servo2.write(0);

  
}
double radtodeg(int rad){
  return (rad/57.2958);
}

double sincalc(int X,int Y){
  double H = sqrt(pow(2.0,X)+pow(2.0,Y));
  
  return (X/H);
}

double coscalc(int X,int Y){
  double H = sqrt((X*X)+(Y*Y));
  return (Y/H);
}
void servo_move(double angle){

}

void loop() {
  int Xinput = analogRead(A0);
  int Yinput = analogRead(A1);
  // double sinrad = sincalc(Xinput,Yinput);
  double cosrad = coscalc(Xinput,Yinput);
  double deg = radtodeg(cosrad);
  
  double deg1 = deg;
  if (deg1 <= 90){
    output1 = deg1/2;
  }
  if  (deg1 >=270){
    output1 =( abs(deg1-360)/2);
  }
  if ((90< deg1) and (deg1 <= 180)){
    output1 = ((-1)*abs(deg1-180)/2);
  }
  else{
    output1 = ((-1)*(deg1-180/2));
  }
  double deg2 = deg + 120;
  if (deg2 <= 90){
    output2 = deg2/2;
  }
  if  (deg2>=270){
    output2 =( abs(deg2-360)/2);
  }
  if ((90< deg2) and (deg2 <= 180)){
    output2 = ((-1)*abs(deg2-180)/2);
  }
  else{
    output2 = ((-1)*(deg2-180/2));
  }
  // servo1.write(output1 + offset1);
  // servo2.write(output2 + offset2);
  Serial.println(pow(2.0,Yinput));

  delay(200);

}

