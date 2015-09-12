void up_down(Servo myservo){

  int currentpos=myservo.read();

  if (currentpos==90){
  for(pos=90;pos<=180;pos+=5) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  } 
  if(currentpos==180) {
  for(pos = 180; pos>=90; pos-=5) // goes from 180 degrees to 0 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  }  
}
