void movepoint(float now[],float interval,AccelStepper motorx,AccelStepper motory,float x,float y){
  float resolution=200*20/25.4; //step/mm
  
  int grid=110/interval;
  if (x>grid) x=grid; //point will not be bigger then grid
  if (y>grid) y=grid;
  
  float newx=x-now[0];
  float newy=y-now[1];
  
  //Serial.println(newx);
  //Serial.println(newy);
  
  newx=newx*interval*resolution; //steps
  newy=newy*interval*resolution; //steps
  
  motorx.move(newx); //steps
  motory.move(newy);
  long spd=300; //steps/sec
  long xspd=spd;
  long yspd=spd;
  long check=millis();

    if (newx==0 && newy==0){
      xspd=0;
      yspd=0;
    }else if (newx==0 && newy!=0){
      xspd=0;
    }else if (newy==0 && newx!=0){
      yspd=0;
    }else if (abs(newx)>abs(newy) && newx!=0 && newy!=0){
      yspd=abs(spd*newy/newx);
    }else if (abs(newx)<abs(newy) && newx!=0 && newy!=0){
      xspd=abs(spd*newx/newy); //step/sec
    }
    //if (newx<0) xspd=-xspd;
    //if (newy<0) yspd=-yspd;

  while (motorx.distanceToGo()!=0 || motory.distanceToGo()!=0){
    
    motorx.setSpeed(xspd);
    motory.setSpeed(yspd);
    motorx.runSpeedToPosition();
    motory.runSpeedToPosition();
    
    if (millis()-check>=1000){
      //Serial.print("X pos=");
      //Serial.println(motorx.currentPosition());
      //Serial.print("Y pos=");
      //Serial.println(motory.currentPosition());
      //delay(500);
      check=millis();
    }
  }
  now[0]=x;
  now[1]=y;
}

