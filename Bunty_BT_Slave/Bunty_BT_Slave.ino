#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(3, 2); // RX || TX --> Green || Yellow

const int led = 9;
bool button_toggle = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Bluetooth.begin(38400);  

  pinMode(led, OUTPUT);  
  
}

void loop() {
  if (Bluetooth.available()) {

    if(Bluetooth.read() == 'a') {
        button_toggle = true;
    }
    else {
      button_toggle = false;  
    }

  if (button_toggle) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);   
    }
  }
}
