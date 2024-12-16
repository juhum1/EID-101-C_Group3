### Subproblem 1: Selecting Sensor Setup
Our goal is to find the optimal combination of sensors for accurate navigation and obstacle detection within our budget for the project. 

We based our decision on 4 main criteria: 
<br>
**1. Accuracy**: How well does the sensor provide precise data for navigation? 
<br>
**2. Range**: Effective distance that the sensor can measure
<br>
**3. Compatibility**: Ease of integration with the rest of our car; here we considered things like the constraints on the dimensions of the car and the design of our chassis and sensor mount. 
<br>
**4. Cost**: For sensors that are not provided, we have to ensure that the price is within the $20 budget for additional parts. 

Our four options were: 
1. Using VL53L0X Lidar only
2. Combining VL53L0X with HC-SR04 Ultrasonic
3. Using IR sensors alongside Lidar
4. Using Lidar, Ultrasonic, and IR sensors

For the decision matrix, we took High to be 9 points, Medium as 5 points, and Low as 1 point.
The weights we assigned to each of our criteria were: 
- Accuracy: 0.5
- Range: 0.3
- Compatibility: 0.1
- Cost: 0.1

| Criteria       | VL53L0X Only | VL53L0X + HC-SR04 | VL53L0X + IR Sensors | Lidar, IR, Ultrasonic |
|----------------|--------------|--------------------|---------------------|-----------------------|
| Accuracy       | Medium         | Medium               | Medium              | High                  |
| Range          | Medium       | High               | Medium              | High                  |
| Compatibility  | High         | Medium             | Medium              | Medium                |
| Cost           | Low ($0)     | Low (<$10)         | Low (<$15)          | Low (<$15)            |
| **Total Score**| 28           | 28                 | 24                  | 32                  |

Based on our decision matrix, we decided to use the VL53L0X Lidar with the HC-SR04 and IR sensors

### Subproblem 2: Designing Speed Control with Encoders
Our goal is to develop a method to maintain balanced motor speeds using an encoder. 

We took 4 criteria for consideration in our decision matrix: 
<br>
**1. Accuracy**: Precision in maintaining balanced speeds.
<br>
**2. Complexity**: Difficulty of implementation and computation.
<br>
**3. Responsiveness**: Speed of response to changes in motor performance. 
<br>
**4. Cost**: Whether or not implementation requires additional components to be bought with our $20 budget. 

Our four options were: 
1. Estimate Left Motor Speed Using Fixed Parameters 
2. Add Optical Encoders to the Left Motor
3. Implement IMU-Based Speed Estimation Using MPU6050
4. Combine IMU and Predefined Parameters

Again, we took High to be 9 points, Medium as 5 points, and Low as 1 point. The weights we assigned to each of our criteria were: 
- Accuracy: 0.5
- Complexity: 0.2
- Responsiveness: 0.2
- Cost: 0.1

| Criteria       | Weight | Fixed Parameters | Add Left Encoder | IMU-Based Estimation | Combined Approach |
|----------------|--------|------------------|------------------|-----------------------|-------------------|
| Accuracy       | 0.5    | Low           | High         | Medium            | High           |
| Complexity     | 0.2    | High          | Medium        | Medium            | Low            |
| Responsiveness | 0.2    | Medium        | High          | Medium            | High           |
| Cost           | 0.1    | High          | Low           | High              | Medium         |
| **Total Score**|        | **4.2**          | **7.4**          | **5.4**              | **7.0**           |
