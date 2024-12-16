# EID-101 Group 3 - Julie Hum
## Design Journal

### <u> Entry #1</u> (Wednesday, October 23)
Divided tasks for midterm presentation, started Gaant chart, design matrix, drafted problem statement

Problem Statement: Create a robot that can complete the line following tasks and motion requirements

### <u> Entry #2</u> (Thursday, October 24)
Drafted car design ideas. Created IDEA #2 which involved a cardboard base (or found object) and four wheels (IDEA #1 - Luke, IDEA #3 - Katharine). We created a design matrix and updated our gaant chart.

### <u> Entry #3</u> (Wednesday, November 6)
Began firmware breadboard prototype with 6 LEDS (green for IN pins and red for EN pins).

### <u> Entry #4</u> (Thursday, November 7)
Burnt several LEDs in the process of creating the breadboard prototype. Problem occured because the way I had my circuit built had the voltage bypassing the resistor since my power, resistor, and LED were in the same node. Fixed by having the power and resistor in one node and then the other side of the resistor and the LED in another to properly have the voltage reduced.
Tested the firmware task code and robot was able to move forward, backward, change speed, and stop.

### <u> Entry #5</u> (Thursday, November 13)
Integrated an IR sensor into our  code. Had some difficulties with tuning the potentiometer and had to make adjustments to speed (slow down). 

### <u> Entry #6</u> (Thursday, November 21)
Worked on the line following sprint. Accounted for difference in speed of ENA wheel and ENB wheel by adding 40 to the speed of the ENA wheel (car kept turning right when it should have went forward - ENA is left, ENB is right). Had to move sensors closer to the floor to have them detect properly.

### <u> Entry #7</u> (Monday, November 25)
Created github repository with branches main, devel, and hotfix. Updated it with past work involving the LED firmware task, the IR sensor integration task, and the line detection sprint.

### <u> Entry #8</u> (Tuesday, November 26)
Completed LineFollowing2 task. <br>
Implemented an LED as our visual indicator of finishing the line maze by having the LED set to HIGH after 2 seconds of all 3 IR sensors detecting LOW. Updated state machine diagram.

### <u> Entry #9</u> (Wednesday, November 27)
 Completed Motion3 task for YourChoice1. <br>
 Used the code given in non-blocking.ino in the rcc library for the HC-SR04 ultrasonic distance sensor. At first, the car wouldn't stop but the problem was fixed after adjusting the placement of the sensor. As the car moved, the sensor fell to the left side of the car, causing it to detect objects like my laptop and a roll of tape. After it was moved to the center, it detected distance properly. The speed also had to be lowered to have the car stop closer to the 30 cm goal.

### <u> Entry #10</u> (Thursday, December 12)
Worked on Motion2 and tried to complete it using the MPU6050. However, problems with the motor were encountered (wasn't moving), so it was switched out for a new one. 

### <u> Entry #10</u> (Friday, December 12)
A new motor controller was implemented. MPU6050 was only recording angles of 0 — still unknown what the problem is.