
// <<--Includes-->>>
#include <Servo.h>


// <<--Declarations-->>
Servo myservo;  // create servo object to control a servo
int servo_pos = 90;    // variable to store the servo position

// Ultra-sonic sensor 
const int trigPin = 6;
const int echoPin = 5;
long duration;
int distance;

int loop_counter = 0;
int servo_loop_counter = 0;

// Keep Serial_print controlled with following options:
// 0 --> VERBOSE | Print early, often and everything
// 1 --> IMP | Print only important stuff

//int servo_speed_fast = 15
bool is_servo_on = false; // Flag to decide if servo should move

//typedef struct {
//  int angle;
//  int distance;
//} Distance_At_Angle;
//
//Distance_At_Angle distance_at_angle[90];
const int distance_at_angle_count = 180;
int distance_at_angle[distance_at_angle_count] = {};

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  setup_servo();
  delay(20);
  start_servo();

  setup_distance_sensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //  Serial.println("loop running");
  //  Serial.println(loop_counter);
  //  loop_counter += 1;

  move_servo();

}
    


// ||------------------------>>>>>>>>>>____Servo____<<<<<<<<<<------------------------||
void move_servo() {
  
  if (is_servo_on == true) {
      Serial.println("servo_loop running");
      Serial.println(servo_loop_counter);
      
    for (servo_pos = 90; servo_pos <= 180; servo_pos += 2) { 
      myservo.write(servo_pos);    // go to this position          
      Serial.println(servo_pos);
      get_distance();
      distance_at_angle[servo_pos] = distance;
      delay(25);                      
    }
    for (servo_pos = 180; servo_pos >= 90; servo_pos -= 2) { 
      myservo.write(servo_pos);              
      Serial.println(servo_pos);
      get_distance();
      distance_at_angle[servo_pos] = distance;
      delay(25);                      
    }
    for (servo_pos = 90; servo_pos >= 0; servo_pos -= 2) { 
      myservo.write(servo_pos);             
      Serial.println(servo_pos);
      get_distance();
      distance_at_angle[servo_pos] = distance;
      delay(25);                       
    }
    for (servo_pos = 0; servo_pos <= 90; servo_pos += 2) { 
      myservo.write(servo_pos);   
      Serial.println(servo_pos);
      get_distance();       
      distance_at_angle[servo_pos] = distance;    
      delay(25);                       
    }
    stop_servo();
    delay(15);
    for(int i = 0; i < distance_at_angle_count; i++) {
      Serial.println(distance_at_angle[i]);
    }
    
 }
 servo_loop_counter += 1;
}

void setup_servo() {
  myservo.attach(10);
  reset_servo_forward(); 
}

void reset_servo_forward() {
  servo_pos = 90;
    myservo.write(servo_pos);
    delay(15);
}

void reset_servo_left() {
  servo_pos = 0;
    myservo.write(servo_pos);
    delay(15);
}

void reset_servo_right() {
  servo_pos = 180;
    myservo.write(servo_pos);
    delay(15);
}

void stop_servo() {
  reset_servo_forward();
  is_servo_on = false;  
}

void start_servo() {
  Serial.println("Start Servo called");
  is_servo_on = true;
  reset_servo_forward();
}

void toggle_servo() {
  if (is_servo_on) {
    stop_servo();
  }
  else {
    start_servo();  
  }
}

// ||------------------------<<<<<<<<<<____Servo____>>>>>>>>>>------------------------||

// ||------------------------>>>>>>>>>>____Ultra-Sonic-Distance-Measuring-Unit____<<<<<<<<<<------------------------||

void setup_distance_sensor() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
}

void get_distance() {
    // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  Serial.println(distance);
}

// ||------------------------<<<<<<<<<<____Ultra-Sonic-Distance-Measuring-Unit____>>>>>>>>>>------------------------||

void debug_print(String str, int priority = 0) {
  Serial.println(str);
}
