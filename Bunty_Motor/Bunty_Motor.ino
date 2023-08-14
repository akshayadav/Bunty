#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield shield = Adafruit_MotorShield();
Adafruit_DCMotor *motor1 = shield.getMotor(1);
Adafruit_DCMotor *motor2 = shield.getMotor(2);
Adafruit_DCMotor *motor3 = shield.getMotor(3);
Adafruit_DCMotor *motor4 = shield.getMotor(4);

int fast_speed = 250; // Not 255 coz C'mon
int regular_speed = 125; 
int slow_speed = 25;

int current_speed;

bool temp_run_once = true;
int temp_run_count = 0;

void setup() {
  // put your setup code here, to run once:
  current_speed = regular_speed;//fast_speed;
  shield.begin();
  motor1->setSpeed(current_speed);
  motor2->setSpeed(current_speed);
  motor3->setSpeed(current_speed);
  motor4->setSpeed(current_speed);

}

void loop() {

// test_run_begin

//  if (temp_run_once) {
//    motor1->run(FORWARD);
//    delay(1000);
//    all_stop();
//  }
//
//  if (temp_run_once) {
//    motor2->run(FORWARD);
//    delay(1000);
//    all_stop();
//  }
//
//  if (temp_run_once) {
//    motor3->run(FORWARD);
//    delay(1000);
//    all_stop();
//  }
//
//  if (temp_run_once) {
//    motor4->run(FORWARD);
//    delay(1000);
//    all_stop();
//  }
//
//  temp_run_once = false;

// test_run_end

  if (temp_run_count < 5) {
    all_forward();
    delay(5000);
    all_stop();
    delay(100);
    
    all_backward();
    delay(5000);
    all_stop();
    delay(100);
      
    turn_left();
    delay(1000);
    all_stop();
    delay(100);
  
    all_forward();
    delay(5000);
    all_stop();
    delay(100);
    
    all_backward();
    delay(5000);
    all_stop();
    delay(100);
      
    turn_right();
    delay(1000);
    all_stop();
    delay(100);
   }
  
  temp_run_count += 1;
}

void set_current_speed(int new_speed) {
  current_speed = new_speed;  
  motor1->setSpeed(current_speed);
  motor2->setSpeed(current_speed);
  motor3->setSpeed(current_speed);
  motor4->setSpeed(current_speed);
}

void all_forward() {
  motor1->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
}

void all_backward() {
  motor1->run(BACKWARD);
  motor2->run(BACKWARD);
  motor3->run(BACKWARD);
  motor4->run(BACKWARD);
}

void turn_left() {
  motor1->run(FORWARD);
  motor4->run(FORWARD);
  motor2->run(BACKWARD);
  motor3->run(BACKWARD);
}

void turn_right() {
  motor1->run(BACKWARD);
  motor4->run(BACKWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
}

void all_stop() {
  motor1->run(RELEASE);
  motor2->run(RELEASE);
  motor3->run(RELEASE);
  motor4->run(RELEASE);
}
