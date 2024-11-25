//pin defintions
int ENA = 9;
int ENB = 10;
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 6;
int IR1 = A0;
//speed variable
int speed = 80;

void initializeMotorController() {
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    pinMode(IR1, INPUT); 
}
void changeMotorDirection(String direction) {
    if (direction == "forward") {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }
    else if (direction == "backward") {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
    else if (direction == "left") {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }
    else if (direction == "right") {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
}
 
void setMotorSpeed(int speed1, int speed2) {
    analogWrite(ENA, speed1);
    analogWrite(ENB, speed2);
}
 
void stopMotors() {
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
}
void setup() {
    initializeMotorController();   
}
void loop() {
    //ENA motor spins faster than ENB motor
    setMotorSpeed(speed, speed - 27);
    changeMotorDirection("forward");
    if (digitalRead(IR1) == HIGH)
    {
      stopMotors();
      while(true) {}
    }
}
