## Motion 2 - Group 3 (Julie Hum, Luke McClellan, Katharine Moncrieffe)

### Overview
Our code allows our car to:

1. Rotate clockwise (CW) or counterclockwise (CCW) by a specified angle.
2. Adjust motor speeds and directions dynamically.
3. Utilize an MPU6050 IMU to determine the current angular velocity and calculate the robot's angle.

### Logic
### 1. Initializing the Motor Controller
The `initializeMotorController()` function configures the motor driver pins as outputs and ensures all motors are initially off.

### 2. Setting Motor Directions
The `motorDirection(direction)` function defines motor configurations for:
- **Forward** and **Backward**: Both motors rotate in the same direction.
- **Left** and **Right**: Motors rotate in opposite directions for turning.

### 3. Adjusting Motor Speeds
The `setMotorSpeed(speedA, speedB)` function uses PWM to set the speed of motor A and motor B.

#### 4. Stopping Motors
The `stopMotors()` function stops the motors by setting `ENA` and `ENB` to LOW.

### 5. Rotating the Robot
#### The `rotate(desired_angle, direction)` function implements the rotation logic:

1. **Direction Selection**:
   - If `direction == "CW"`, the motors are configured to turn right.
   - If `direction == "CCW"`, the motors are configured to turn left.

2. **IMU Data Integration**:
   - The IMU's angular velocity (`getAngVelZ()`) is used to calculate the current angle.
   - Angular velocity is multiplied by the time passed (`time_passed`) to get the incremental rotation:
        **Angle increment = angular velocity * time passed**
    
   - The result is scaled by `direction_num` to handle positive (CW) or negative (CCW) rotation. CW rotation adds to the angle, while CCW subtracts from it.


3. **Loop Logic**:
   - The robot continuously rotates until the `current_angle` matches the `desired_angle`.
   - During each loop iteration:
     - Time passed since the last update is calculated.
     - The incremental rotation is added to `current_angle`.

4. **Motor Stop Condition**:
   - When the `current_angle` reaches or exceeds the `desired_angle`, the motors are stopped using `stopMotors()`.

### Angular Velocity to Angle Conversion
The angular velocity is provided by the IMU in degrees per second (omega). By integrating this value over time, the angle (theta) is calculated:

** delta theta = omega * delta t**
Here:
- delta theta: Incremental angle change.
- omega: Angular velocity (degrees/second).
- delta t: Time passed (seconds).

The cumulative angle is updated as:

** current angle = delta theta * direction_num**
