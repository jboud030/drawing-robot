#include <AccelStepper.h>
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo
 
int pos = 45;    // variable to store the servo position
float now[2]={0,0}; //x and y
char input;
int steps=200;
int grid=20;
long stsec=3000.0; //steps/sec
float interval=110/grid; //mm
AccelStepper Y(AccelStepper::FULL4WIRE,6,5,4,3);
AccelStepper X(AccelStepper::FULL4WIRE,11,10,9,8);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(13);  // attaches the servo on pin 13 to the servo object
  myservo.write(pos);
  while (!Serial);
  Serial.println("Enter '1' to begin");
  X.setMaxSpeed(stsec);
  Y.setMaxSpeed(stsec);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (input!='1'){
    input=Serial.read();
  }
  movepoint(now,interval,X,Y,3,0);
  up_down(myservo); //down
  movepoint(now,interval,X,Y,6,4);
  movepoint(now,interval,X,Y,5,5);
  movepoint(now,interval,X,Y,4,5);
  movepoint(now,interval,X,Y,3,4);
  movepoint(now,interval,X,Y,2,5);
  movepoint(now,interval,X,Y,1,5);
  movepoint(now,interval,X,Y,0,4);
  movepoint(now,interval,X,Y,3,0);
  up_down(myservo); //up
  movepoint(now,interval,X,Y,0,0);
  while (true);
  
}
