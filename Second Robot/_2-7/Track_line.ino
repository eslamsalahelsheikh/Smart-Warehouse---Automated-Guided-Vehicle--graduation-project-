boolean track_line()
{
//Serial.println("bemshyyyyyyyy");
  delay(250);
   unsigned int position = qtra.readLine(sensorValues,QTR_EMITTERS_ON,1);
   Input = position;
  // Serial.print("Input");
   //Serial.println(Input);
   myPID.Compute();  
   if(abs(Output)<6)
  {
   RightFwd (60);
   LeftFwd (60);
       if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
      delay(200);

    }
  
   //Serial.println("ifff");
   //Serial.println(Output);
  printqtr();
  if(INTERSECTION_CONDITION){
    z=1;
   // Serial.println("intersection");
          knobLeft.write(0);
      newLeft = 0;
      newLeft = knobLeft.read();
//Serial.println("ya allah");
  }
  if(z==1){
      newLeft = knobLeft.read();

      if (newLeft <= -1000)
      {
        Serial.println("intersection");
          RightStop();
  LeftStop();
   delay(3000);
     
      i++;
       z=0;
            knobLeft.write(0);
        newLeft = 0;
      }
  }
  }
 else{
    OutR = 100 - Output;
    OutL = 99+ Output;
     RightFwd (OutR);
   LeftFwd (OutL);
   //Serial.println("elsee");
   //Serial.println(Output);
     if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
      delay(200);

    }
  
  printqtr();
  if(INTERSECTION_CONDITION){
    z=1;
      knobLeft.write(0);
      newLeft = 0;
      newLeft = knobLeft.read();
 //Serial.println("ya allah");
  }
  if(z==1){
      newLeft = knobLeft.read();

      if (newLeft <= -1000)
      {
        Serial.println("intersection");
          RightStop();
  LeftStop();
   delay(3000);
      i++;
       z=0;
       knobLeft.write(0);
            newLeft = 0;

      }
   }
}
  }

 boolean upload()
{
        if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
      delay(200);

    }

  //Serial.println("7aysheeeeeeeeeel");
  delay(250);
   unsigned int position = qtra.readLine(sensorValues,QTR_EMITTERS_ON,1);
   Input = position;
  // Serial.print("Input");
   //Serial.println(Input);
   myPID.Compute();  
   if(abs(Output)<6)
  {
        if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
      delay(200);

    }
   RightFwd (60);
   LeftFwd (60);
   
   //Serial.println("ifff");
   //Serial.println(Output);
  printqtr();
      if (INTERSECTION_CONDITION) {
      Serial.println("intersection");
      delay(500);
    }
int value = digitalRead(sensorPin);
if (value==0){
  lift();
}

  }
 else{
    OutR = 100 - Output;
    OutL = 99+ Output;
     RightFwd (OutR);
   LeftFwd (OutL);
       if (INTERSECTION_CONDITION) {
      Serial.println("intersection");
      delay(500);
    }
        if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
      delay(200);
    }
   //Serial.println("elsee");
   //Serial.println(Output);
  printqtr();
int value = digitalRead(sensorPin);
if (value==0){
  lift();
}

   
   }
}

