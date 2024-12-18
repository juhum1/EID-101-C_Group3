#include <rcc.h>
#include <Wire.h>

//pin definitions
#define ENA 3
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define ENB 8

//speed-related variables
#define normalspeed 60

//angle-related variables
float desired_angle = 0;
float current_angle = 0;

//time-related variables
unsigned long cur = 0;
unsigned long prev = 0;
unsigned long time_passed = 0;

MPU6050 imu;
 
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
 
void rotate(float desired_angle, String direction) 
{
    imu.update();  
  
    int direction_num;
    
    //clockwise
    if (direction == "CW") {
        motorDirection("right");
        setMotorSpeed(normalspeed, normalspeed);
        direction_num = 1;
        
        Serial.println("CW");
    }
    
    //counterclockwise
    if (direction == "CCW") {  
        motorDirection("left");
        setMotorSpeed(normalspeed, normalspeed);
        direction_num = -1;
        
        Serial.println("CCW");
    }
    
    prev = millis();
  
    while (abs(current_angle) < abs(desired_angle)) {
        //if current angle is less than the desired angle, keep rotating
        imu.update();
        
        cur = millis();
        time_passed = (cur - prev) / 1000.0; //find time passed in seconds
        prev = cur;
        
        current_angle += imu.getAngVelZ() * time_passed * direction_num; //calculate current angle
        
        Serial.print("Angle: ");
        Serial.println(current_angle);
    }
    //if current angle reaches desired angle, stop rotating
    stopMotors();
}

void setup() {
    initializeMotorController();
    
    //initialize MPU6050
    Wire.begin();
    imu.begin();
    imu.calibrate();
    
    Serial.begin(9600);
}

void loop() 
{
    rotate(90.0, "CCW");
    delay(2000);
    rotate(90.0, "CW");
    delay(2000); 
}
