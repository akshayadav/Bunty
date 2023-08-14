#include <SoftwareSerial.h>

const int LEDPin = 8;
const int buttonPin = 9;

SoftwareSerial Bluetooth(3, 2); // RX | TX 

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, OUTPUT);
//  digitalWrite(LEDPin, HIGH);
  Bluetooth.begin(38400);

}

void loop() {
   Bluetooth.write(1);
  if (Bluetooth.available()) {
    digitalWrite(LEDPin, HIGH);  
  }

  
  if (digitalRead(buttonPin) == HIGH) {
//    if (Bluetooth.available() > 0) {
//    }
    Bluetooth.write(1);
//    digitalWrite(LEDPin, HIGH);  
 
  }
  else {
//        digitalWrite(LEDPin, LOW);  
  }
  // put your main code here, to run repeatedly:

}
