### Group 3 Cumulative Report (Julie Hum, Luke McConnell, Katharine Moncrieffe)

## Mechanical
For the mechanical design tasks, we started with a quickly assembled cardboard chassis onto which all of the components were screwed in place. This chassis had a few problems: it placed the Arduino’s USB port in an inconvenient place, it was too back-heavy and too small to accommodate all of the necessary sensors. It was also flimsy and aesthetically unappealing. We used these flaws we noticed while working with the initial chassis to come up with a more refined design which comprises an acrylic laser-cut chassis and a 3D-printed mount for the motors and sensors. We used OnShape and AutoCAD to create the necessary CAD files. Even after the laser cut chassis was completed, we ran into issues with sizing, as the body of the robot was just slightly too big, which required us to redo the laser cut with a modified design.

## Electrical 

## Motion


## Line Following
We finished line following task B as part of the 2 required design sprints. Although there were challenges with completing our initial line following sprint where we followed a straight line, they were mainly hardware-related, and were solved by moving the sensors closer to the line, since we noticed that the sensors were picking up the light reflected off our ball caster and other parts outside of the course itself. After our initial line following sprint, we began testing our code on course B, but our car was turning in the opposite direction of the line. We determined that this was an issue with our sensor logic, so after fixing that by revisiting our truth table, we were able to complete line following task B with minimal other changes or improvements.

We also had to implement an LED visual indicator for course completion. We were concerned that it wouldn't fit on the car, because we knew that the actual wiring wasn't a problem but there wasn't space for a full-sized breadboard on our chassis with the Arduino and all the wires coming off it. We eventually chose to use a mini breadboard for the LED, because that was small enough to fit on the chassis with everything else.

For line following task A, we  

## Programming
Programming 1. In designing and writing our library, our first challenge was determining which functions were relevant and deserved to be included. We decided to have fields corresponding to the number of sensors and the pins that each sensor was connected to, which would be helpful in the event that someone had multiple sensor arrays and wanted to make multiple instances of our library. We decided that there should be a constructor to populate the fields of each instance as well as functions to control turning the pinModes of the sensor pins to INPUT, updating the array, and printing values from it. 

After deciding on the functionalities to be covered by our library, our next step was to translate these ideas into code. 

One issue that came up was including Arduino.h in ReflectiveLightArray.cpp. Because our begin() function relied on pinMode() to set the pinModes of each sensor pin to INPUT, but the code for our library isn't a .ino file, we kept running into compilation errors when we tried to call pinMode(). After some research, we figured out that we had to include Arduino.h to be able to use functions relevant to the Arduino like pinMode(). 


## Management
Management 1. Sub-problems: selecting sensor setup and designing speed control

For each of our sub-problems, we met as a group to discuss what our options were and what would be the best choice given the constraints on the size of the car and the difficulty of implementation, among other criteria. Initially it was difficult to think of enough options for each subproblem, which was problematic for the sensor selection subproblem in particular because using too many sensors can cause problems for the design of our sensor array and might make our car larger than the specified dimensions, but eventually we were able to find other options through research and comparing our car to online examples. 

This is reflected in our design journals from November 20 and November 25, which state, "We met as a group to discuss the sensor configuration and selection of sensors, and we decided on using 5 IR sensors as well as the ultrasonic and lidar sensors." and "We discussed how to tackle speed control as a group, and decided on using one encoder based on our design matrix for this subproblem."

2. Our proposed Gaant Chart was much simpler than what happened in reality, because we didn't expect how much work would get done in the design sprints and how many tasks "went together" - for example, designing and CADing the sensor array was much easier after the chassis was completed because those two parts are intended to go together. In the end, our actual work timeline diverged significantly from our proposed one. 

3. Our BOM was similar to the one we showed in our Midterm Presentation because we chose not to use our budget on outside parts, but we chose not to use the micro servos. 
