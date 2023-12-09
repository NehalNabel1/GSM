#include "GSM_Interface.h"

String message="Hello";

void setup() {
 
  Serial.begin(9600);
  GSM_Init();
  SendMessage(message);
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
