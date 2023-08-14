#define button 8


int buttonState = 0;

void setup() {
  pinMode(button, INPUT);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {

  Serial.write('1');
  delay(1000);
   Serial.write('0');
   delay(1000);
// // Reading the button
// buttonState = digitalRead(button);
// if (buttonState == HIGH) {
//   Serial.write('1'); // Sends '1' to the master to turn on LED
// }
// else {
//   Serial.write('0');
// }  
}
