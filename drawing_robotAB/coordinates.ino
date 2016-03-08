void coordinates(){
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
}



