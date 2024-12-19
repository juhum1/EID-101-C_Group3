## Line Following A: Group 3 (Julie Hum, Luke McClellan, Katharine Moncrieffe)

Our code uses IR sensors to follow a line. Based on the sensor readings, our car will stop/turn/light up the LED. 

In our loop(), the sensorOutput() function processes IR sensor readings to determine the robot's actions:

### Line Following:
Based on sensor states (HIGH/LOW), the robot adjusts motor speeds and directions to follow the line.

### Special Conditions:
All Sensors LOW:
If this persists for 7 seconds, the robot rotates 180° clockwise.
After 10 seconds, the LED lights up.

### Other States:
Adjusts speed and direction dynamically to stay on the line.
