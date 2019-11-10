boolean track_line()
{
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
      delay(200);

    }
  o = i;
  //Serial.println("bemshyyyyyyyy");
  delay(250);
  unsigned int position = qtrrc.readLine(sensorValues, QTR_EMITTERS_ON, 1);
  Input = position;
  // Serial.print("Input");
  //Serial.println(Input);
  myPID.Compute();
  if (abs(Output) < 6)
  {
    RightFwd (30);
    LeftFwd (30);
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
      delay(200);

    }
    //Serial.println("ifff");
    //Serial.println(Output);
    printqtr();
    if (INTERSECTION_CONDITION) {
      z = 1;
      knobLeft.write(0);
      newLeft = 0;
      newLeft = knobLeft.read();

    }
    if (z == 1) {
      //  delay(200);
      newLeft = knobLeft.read();

      if (newLeft >= 700)
      {
        Serial.println("intersection");

        //  int  val = digitalRead(sensorPin2);
        //    if (val == 1) {
        //  Serial.println("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");

        RightStop();
        LeftStop();
        delay(1000);

        i++;
        z = 0;
        knobLeft.write(0);
        newLeft = 0;
      }

    }
  }
  else {
    OutR = 50 - Output;
    OutL = 49 + Output;
    RightFwd (OutR);
    LeftFwd (OutL);

    //Serial.println("elsee");
    //Serial.println(Output);
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
      delay(200);

    }
    printqtr();
    if (INTERSECTION_CONDITION) {
      z = 1;
      knobLeft.write(0);
      newLeft = 0;
      newLeft = knobLeft.read();
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
      delay(200);

    }
    }
    if (z == 1) {

      newLeft = knobLeft.read();

      if (newLeft >= 700)
      {
        Serial.println("intersection");

        // int   val = digitalRead(sensorPin2);
        //    if (val == 1) {
        //Serial.println("2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222");

        RightStop();
        LeftStop();
        delay(1000);
        i++;
        z = 0;
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
  unsigned int position = qtrrc.readLine(sensorValues, QTR_EMITTERS_ON, 1);
  Input = position;
  // Serial.print("Input");
  //Serial.println(Input);
  myPID.Compute();
  if (abs(Output) < 6)
  {
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
      delay(200);

    }
    RightFwd (30);
    LeftFwd (30);
    //Serial.println("ifff");
    //Serial.println(Output);
    printqtr();
    if (INTERSECTION_CONDITION) {
      Serial.println("intersection");
      delay(500);
    }
    int value = digitalRead(sensorPin);
    if (value == 0) {
      lift();
    }

  }
  else {
    OutR = 50 - Output;
    OutL = 49 + Output;
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
    if (value == 0) {
      lift();
    }


  }
}

