#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(3, 2); // RX || TX --> Green || Yellow

const int led = 9;
const int button = 8;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Bluetooth.begin(38400);  

  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  
}

void loop() {
  int button_state = digitalRead(button); 
//  if (button_state == HIGH) {
//    Serial.println('a');
//    if (Serial.available()) {
//      Bluetooth.write(Serial.read());
//      Serial.println("Message sent");
//    }   
//  }

  
  
  if (Bluetooth.available()) {
    if (button_state == HIGH) {
      Bluetooth.write('a');
      digitalWrite(led, HIGH);
    } else {
      Bluetooth.write('b');
      digitalWrite(led, LOW);
    }
  } 
}
