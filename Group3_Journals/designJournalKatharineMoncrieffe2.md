# EID-101 Group 3 – Katharine Moncrieffe 

## Design Journal 

 
**Entry #1 (Wednesday, October 23)**

Divided tasks for midterm presentation, started Gantt chart, design matrix, drafted problem statement 

Problem Statement: Create a robot that can complete the line following tasks and motion requirements.  

**Entry #2 (Oct 24)**

Brainstorming design ideas for car; finished Gaant chart and design matrix.  
 
**Entry #3 (Oct 31)**

Edited problem statement and made midterm presentation.  

**Entry #4 (Nov 5)**

Began electrical assignment (5V regulator, schematic, truth table).  

**Entry #5 (Nov 6)** 

Worked with Julie on breadboarded prototype and also did the electrical assignment for our first design sprint.  

**Entry #6 (Nov 13)** 

Worked on implementing wall sensing. Had issues with the sensitivity of the sensor and the potentiometer leading to the car running into the wall instead of stopping 100mm away. We plan on meeting again this week to figure out the right settings; we don’t think the code is the problem.  

**Entry #7 (Nov 20)**

Finished the initial sensor integration assignment and edited our work for the IR sensor sprint. We met as a group to discuss the sensor configuration and selection of sensors, and we decided on using 5 IR sensors as well as the ultrasonic and lidar sensors. Noticed that the motors run at different speeds, so the car doesn’t always follow the line; we plan on fixing this in class tomorrow.  

**Entry #8 (Nov 21)**
Took time in and after class to finish the IR sensor sprint. We figured out that the main issue wasn’t in the code or the motors but instead in the sensor placement, and we plan on adjusting our design accordingly for the next assignment and for the CAD/sketch.

**Entry #9 (Nov 25)**
Started Motion1 task and began organizing repo. I finished the writeup for Motion1 but want to add pictures/geometry later to better illustrate the calculations. 

**Entry #10 (Nov 26)**
Finished Motion1 code, but need to test to see how close the car gets to 1m and recalculate so we can adjust the tick count accordingly.
We also implemented the LED visual indicator for course completion and took a video for LineFollowing2 in class.

**Entry #11 (Nov 27)**
Tried debugging motion1.ino and rewiring encoders, but as of right now it still doesn't work (just moves in a straight line instead of stopping after 1m). I think the issue is hardware related (issue with output from odom.getCount()) and plan to revisit this problem after the break.

**Entry #12 (Dec 5)**
We integrated the 3d printed and laser cut parts into the car and rewired it. We also made plans for how to divide the remaining tasks before the final project is due. 

**Entry #14 (Dec 10)**
Finished management task 1 (subproblem definitions and decision matrices) and committed it.

**Entry #15 (Dec 13)**
Finished writing and testing the sensor array library and wrote the relevant documentation. Updated the directory structure in our repo to include a Group3_Programming subdirectory with the library task.

**Entry #16 (Dec 18)**
Added state function descriptions to cumulative report and reorganized directory structure to fit requirements. 
