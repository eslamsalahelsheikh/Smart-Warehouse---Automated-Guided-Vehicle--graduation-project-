void RotLeft_90() {
  int k = 1;
  knobLeft.write(0);
  newLeft = 0;
  while (k == 1) {
    LeftBwd(52);
    RightFwd(50);
    newLeft = knobLeft.read();
    if (newLeft >= 900)
    {
      RightStop();
      LeftStop();
      delay(1000);
      k = 2;
      //i++;
    }
  }
}
void RotRight_90() {
  int k = 1;
  knobLeft.write(0);
  newLeft = 0;
  while (k == 1) {
    LeftFwd(52);
    RightBwd(50);
    newLeft = knobLeft.read();
    if (newLeft <= -820)
    {
      RightStop();
      LeftStop();
      delay(1000);
      k = 2;
      //i++;
      //Serial.print ("b2lfffffffffffffff");

    }
  }
}
void RotRight_180() {
  int k = 1;
  knobLeft.write(0);
  newLeft = 0;
  while (k == 1) {
    LeftFwd(52);
    RightBwd(50);
    newLeft = knobLeft.read();
    if (newLeft <= -1700)
    {
      RightStop();
      LeftStop();
      delay(1000);
      k = 2;
      //i++;
    }
  }
}
void RotLeft_180() {
  int k = 1;
  knobLeft.write(0);
  newLeft = 0;
  while (k == 1) {
    LeftBwd(52);
    RightFwd(50);
    newLeft = knobLeft.read();
    if (newLeft >= 1750)
    {
      RightStop();
      LeftStop();
      delay(1000);
      k = 2;
      // i++;
    }
  }
}



void back() {
  int k = 1;
  int val;
  while (k == 1) {
    buzzer ();
    LeftBwd(52);
    RightBwd(50);
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      Serial.println("555");
            delay(200);

    }
    val = digitalRead(sensorPin2);
    while (val == 1) {
      if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        Serial.println("555");
              delay(200);

      }
      buzzer ();
      LeftBwd(52);
      RightBwd(50);
      val = digitalRead(sensorPin2);
      while (val == 0) {
        buzzer ();
        RightStop();
        LeftStop();
        delay(1000);
        val = 2;
        k = 2;
        //Serial.println(val);
      }
    }

  }


}

