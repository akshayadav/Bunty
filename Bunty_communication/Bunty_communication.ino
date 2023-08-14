#include <SoftwareSerial.h>

// Responder addr: +ADDR:98d3:b1:fe5502

SoftwareSerial Bluetooth(3, 2); // RX | TX 
int flag = 0; 
int LED = 8; 
void setup() 
{   
 Serial.begin(9600); 

 Bluetooth.begin(38400); 
 pinMode(LED, OUTPUT); 
// digitalWrite(LED, HIGH); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
 if (Bluetooth.available()) {
  flag = Bluetooth.read(); 
  }
   
   
 if (flag == 1) 
 { 
   digitalWrite(LED, HIGH); 
   Serial.println("LED On"); 
 } 
 else if (flag == 0) 
 { 
   digitalWrite(LED, LOW); 
   Serial.println("LED Off"); 
 } 
}
