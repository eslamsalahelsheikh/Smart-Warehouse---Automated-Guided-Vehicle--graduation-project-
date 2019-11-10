
void up(){
  servoup.write(100); //t7t 80 120 fo2                // sets the servo position according to the scaled value 
  delay(15); 
 servoback.write(150);// t7t 80 fo2 95 
}

void down(){
   servoup.write(165); //t7t 80 120 fo2                // sets the servo position according to the scaled value 
  delay(15); 
 servoback.write(175);// t7t 80 fo2 95 
}


void lift (){
   buzzer ();   
      LeftStop();
    RightStop();
    delay(2000);
up();
 delay(1000);
  buzzer ();   
 RotRight_180();
  i++;
RightStop();
LeftStop();
delay(2000);
}

void download(){
   LeftStop();
    RightStop();
    delay(2000);
    down();
    delay(2000);
}

