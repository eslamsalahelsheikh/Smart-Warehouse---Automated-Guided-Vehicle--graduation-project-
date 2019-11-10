void Rfid(){

  if (i==0){
 if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {

if(mfrc522.uid.uidByte[0]==64 && mfrc522.uid.uidByte[1]==77 ){
      if(mfrc522.uid.uidByte[2]==19 && mfrc522.uid.uidByte[3]==51){
      
  RightStop();
  LeftStop();
 buzzer ();   
   delay(1000);
i=2;
 
}
}
}
  }
}
