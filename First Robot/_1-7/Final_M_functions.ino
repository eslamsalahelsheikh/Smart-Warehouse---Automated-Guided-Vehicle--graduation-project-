//Motor functions used to faciltate the motor driving
void RightFwd (int Speed){
  digitalWrite(LeftDir,LOW);
  analogWrite(LeftPWM,Speed);
}
void RightBwd (int Speed){
  digitalWrite(LeftDir,HIGH);
  analogWrite(LeftPWM,Speed);
}
void LeftFwd (int Speed){
  digitalWrite(RightDir,HIGH);
  analogWrite(RightPWM,Speed);
}
void LeftBwd (int Speed){
  digitalWrite(RightDir,LOW);
  analogWrite(RightPWM,Speed);
}
void LeftStop(){
  digitalWrite(LeftDir,LOW);
  digitalWrite(LeftPWM,LOW);
}
void RightStop(){
  digitalWrite(RightDir,LOW);
  digitalWrite(RightPWM,LOW);
}

void buzzer (){
   digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second
}

