//pin definitions
int ENA = 9;
int ENB = 10;
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

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

void setMotorSpeed(int speed) {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
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

void stopMotors() {
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void setup() {
    initializeMotorController();
}

void loop() {
    setMotorSpeed(100);
    
    changeMotorDirection("forward");
    delay(1000);
    
    changeMotorDirection("backward");
    delay(1000);
    
    stopMotors();
    delay(1000);
}
