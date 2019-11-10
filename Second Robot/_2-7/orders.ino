  void receiveData(int bytecount){
 
  number = Wire.read();

  index++;

  
//  Serial.println("teeeeeeeeeeeeeeeeeeeeeeeeeeeeeet");
//  Serial.println(index);

}


void sendData(){
  int x=100;
Wire.write(x);
delay(500);
}
