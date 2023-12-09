#include "GSM_Interface.h"

void GSM_Init(){
  mySerial.begin(9600);
  Serial.println("Initializing..."); 
  delay(1000);
}


void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}



void SendMessage(String Message){
     
  mySerial.println("AT");
  updateSerial();
  mySerial.println("AT+CMGF=1"); 
  updateSerial();
  mySerial.println("AT+CMGS=\"+201150745622\""); // enter your phone number here (prefix country code)
  updateSerial();
  mySerial.print(Message); // enter your message here
  updateSerial();
  mySerial.write(26);
}
