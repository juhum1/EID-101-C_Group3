### Group 3 Cumulative Report (Julie Hum, Luke McConnell, Katharine Moncrieffe)

## Mechanical
In completing the mechanical design tasks, we encountered problems with ensuring that the designed parts were able to effectively be integrated into the rest of our car while keeping us within the dimensional constraints of the car overall. For example, we had to take into consideration the number of sensors and how they should be spaced when designing our sensor matrix. 

## Electrical 

## Motion

## Line Following
We finished line following task B as part of the 2 required design sprints. Although there were challenges with completing our intitial line following sprint where we followed a straight line, they were mainly hardware related, and were solved by moving the sensors to be closer to the line, because we noticed that the sensors were picking up the light reflected off our ball caster and other parts outside of the course itself. After our initial line following sprint, we began testing our code on course B, but our car was turning in the opposite direction of the line. We determined that this was an issue with our sensor logic,and after fixing that by revisiting our truth table, we were able to complete line following task B with minimal other changes or improvements. 

We also had to implement an LED visual indicator for course completion. We were concerned that it wouldn't fit on the car, because we knew that the actual wiring wasn't a problem but there wasn't space for a full-sized breadboard on our chassis with the Arduino and all the wires coming off it. We eventually chose to use a mini breadboard for the LED, because that was small enough to fit on the chassis with everything else.

For line following task A, we 

## Programming



## Management
Sub-problems: selecting sensor setup and designing speed control

For each of our sub-problems, we met as a group to discuss what our options were and what would be the best choice given the constraints on the size of the car and the difficulty of implementation, among other criteria. Initially it was difficult to think of enough options for each subproblem, which was problematic for the sensor selection subproblem in particular because using too many sensors can cause problems for the design of our sensor array and might make our car larger than the specified dimensions, but eventually we were able to find other options through research and comparing our car to online examples. 

This is reflected in our design journals from November 20 and November 25, which state, "We met as a group to discuss the sensor configuration and selection of sensors, and we decided on using 5 IR sensors as well as the ultrasonic and lidar sensors." and "We discussed how to tackle speed control as a group, and decided on using one encoder based on our design matrix for this subproblem."

Our proposed Gaant Chart was much simpler than what happened in reality, because we didn't expect how much work would get done in the design sprints and how many tasks "went together" - for example, designing and CADing the sensor array was much easier after the chassis was completed because those two parts are intended to go together. In the end, our actual work timeline diverged significantly from our proposed one. 

Our BOM was similar to the one we showed in our Midterm Presentation because we chose not to use our budget on outside parts, but we chose not to use the micro servos. 
