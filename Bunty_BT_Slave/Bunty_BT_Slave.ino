#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(3, 2); // RX || TX --> Green || Yellow

const int led = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Bluetooth.begin(38400);  

  pinMode(led, OUTPUT);  
  
}

void loop() {
  if (Bluetooth.available() > 0) {
//    String char_inp = Bluetooth.readString(); 
    Serial.println(Bluetooth.read());
//
//    if(Serial.read() == 'a') {
      digitalWrite(led, HIGH);
    } 
    else {
      digitalWrite(led, LOW);
    }
//  }
    
//    Serial.write(char(Bluetooth.read()));
//     if (Bluetooth.read() == 'A') {
//       digitalWrite(led, LOW);
//     }
//     else {
//      digitalWrite(led, HIGH);      
//      }
//  } else {
//      digitalWrite(led, LOW);
//  }

    
//    Serial.write(Bluetooth.read());
//    if (digitalRead(button) == HIGH) {
//      digitalWrite(led, HIGH);
//    }
//    else {
//      digitalWrite(led, LOW);  
//    }
//    
//  }
//  if (Serial.available()) {
//    Bluetooth.write(Serial.read());
//  }
}
