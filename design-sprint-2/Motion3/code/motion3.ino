#include <rcc.h>

//pin definitions
int ENA = 9;
int ENB = 10;
int IN1 = 3;
int IN2 = 4;
int IN3 = 5;
int IN4 = 6;
int IR_left = 2;
int IR_middle = 5;
int IR_right = 11;

//speed-related variables
int normalspeed = 50;
int gap = 25;

#define DESIRED_DISTANCE_CM 30

HC_SR04_async ultrasonic;

unsigned long duration_us;

void initializeMotorController() {
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    pinMode(IR_left, INPUT);
    pinMode(IR_middle, INPUT); 
    pinMode(IR_right, INPUT);
}

void motorDirection(String direction) {
    if (direction == "forward") {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }
    if (direction == "backward") {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
    if (direction == "left") {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }
    if (direction == "right") {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
}

void setMotorSpeed(int speedA, int speedB) {
    analogWrite(ENA, speedA);
    analogWrite(ENB, speedB);
}

void stopMotors() {
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
}

void setup() {
    initializeMotorController();
    motorDirection("forward");
    setMotorSpeed(normalspeed + gap ,normalspeed);
    
    ultrasonic.begin();
    ultrasonic.pulse();

    Serial.begin(9600);
}

void loop() {
    if (ultrasonic.isDone()) {
        duration_us = ultrasonic.getDuration();
        ultrasonic.pulse();
    }
    
    //check if desired distance is reached, if so, stop
    if ((duration2centimeters(duration_us) > DESIRED_DISTANCE_CM) || !duration_us) {
        setMotorSpeed(normalspeed + gap, normalspeed);
    } else {
        setMotorSpeed(0, 0);
    }

    Serial.print("distance cm: ");
    Serial.println(duration2centimeters(duration_us));
}

