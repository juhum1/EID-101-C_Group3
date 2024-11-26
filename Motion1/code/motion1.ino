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
int encoderA = 7;
int encoderB = 8;

//speed-related variables
int normalspeed = 80;
int turnspeed = 100;
int gap = 40;

//distance-related variables for motion1
#define TICKS_FOR_1_METER 3831
#define STOP_DURATION 2000 //2s 

Left_Odom odom; 

void sensorOutput() {
  int left = digitalRead(IR_left);
  int middle = digitalRead(IR_middle);
  int right = digitalRead(IR_right);

  //ENA Wheel needs higher speed than ENB wheel to run at the same speed
  if (left == LOW && middle == LOW && right == LOW) {
    stopMotors();
  }
  if (left == LOW && middle == LOW && right == HIGH) {
    setMotorSpeed(normalspeed +gap, turnspeed);
  }
  if (left == LOW && middle == HIGH && right == LOW) {
    setMotorSpeed(normalspeed +gap, normalspeed);
  }
  if (left == HIGH && middle == LOW && right == LOW) {
    setMotorSpeed(turnspeed +gap, normalspeed);
  }
  if (left == LOW && middle == HIGH && right == HIGH) {
    setMotorSpeed(normalspeed +gap, turnspeed);
  }
  if (left == HIGH && middle == LOW && right == HIGH) {
    setMotorSpeed(normalspeed +gap, normalspeed);
  }
  if (left == HIGH && middle == HIGH && right == LOW) {
    setMotorSpeed(turnspeed +gap, normalspeed);
  }
  if (left == HIGH && middle == HIGH && right == HIGH) {
    setMotorSpeed(normalspeed +gap, normalspeed);  
  }
}

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

void drive_distance(int ticks, int direction) {
    unsigned long count_start = odom.getCount();
    unsigned long count_current;

    while (abs((count_current = odom.getCount()) - count_start) < ticks) {
        Serial.print("Current count: ");
        Serial.println(count_current);
        if (direction > 0) {
            motorDirection("forward");
            setMotorSpeed(normalspeed + gap, normalspeed);
        } else {
            motorDirection("backward");
            setMotorSpeed(normalspeed + gap, normalspeed);
        }
    }

    stopMotors();
}

void perform_task() {
    for (int i = 0; i < 3; i++) {
        Serial.println("forward");
        drive_distance(TICKS_FOR_1_METER, 1);

        Serial.println("stopping");
        delay(STOP_DURATION);

        Serial.println("backward");
        drive_distance(TICKS_FOR_1_METER, -1);

        Serial.println("stopping");
        delay(STOP_DURATION);
    }
}

void setup() {
    Serial.begin(9600);
    initializeMotorController();
    //motorDirection("forward");
    perform_task();
}

void loop() {
    //sensorOutput();
}
