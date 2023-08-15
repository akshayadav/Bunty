#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(3, 2); // RX || TX --> Green || Yellow

const int led = 9;
const int button = 8;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Bluetooth.begin(38400);  

  pinMode(led, OUTPUT);
  pinMode(button, OUTPUT);

  Serial.write("Setting Bluetooth");
  Bluetooth.write("AT");
  
}

void loop() {
  if (Bluetooth.available()) {
    Serial.write(Bluetooth.read());
    digitalWrite(led, HIGH);
    
  }
  if (Serial.available()) {
    Bluetooth.write(Serial.read());
  }
}
