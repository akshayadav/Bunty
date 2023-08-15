#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(3, 2); // RX || TX --> Green || Yellow

const int start_button = 7;
const int stop_button = 8;
const int led = 9;

bool flag = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Bluetooth.begin(38400);  
  pinMode(led, OUTPUT);
  pinMode(start_button, INPUT_PULLUP);
  pinMode(stop_button, INPUT_PULLUP);
  
}

void loop() {

  
  int start_button_state = digitalRead(start_button); 
  int stop_button_state = digitalRead(stop_button);

  if (Bluetooth.available()) {
    if (start_button_state == HIGH) {
      Bluetooth.write('a');
      flag = true;
    } 
    else if (stop_button_state == HIGH) {
      Bluetooth.write('b');
      flag = false;
    }

    if (flag) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  } 
}
