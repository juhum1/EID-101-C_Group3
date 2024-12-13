# Motion3 Write Up
Task: Have the robot move towards a wall, but stop when the contact point of the wheels with the ground is 300mm from the wall. When the robot stops take a measurement, or have an indicator on the ground showing where 300mm would be.

## Set Up
1. Utilized the code in the rcc library (not the Servo-related parts)
`rcc/examples/sensor/hc-sr04/non-blocking/non-blocking.ino`
2. Matched the trig and echo pins of the HC_SR04 sensor (TRIG - A3, ECHO - 13)

## Testing
1. Ran into the problem of the car not being able to stop. Used the serial monitor to debug — distance was being detected correctly by the HC_SR04 sensor, but it still wouldn't stop.
2. Noticed that the placement of the sensor was not centered and also floating around while the car was in motion. After moving the sensor to the center of the car and placing it in front of the ball caster, the sensor was carried along with the ball caster well and the car could stop at around 30 cm.
3. Car was going past 30 cm, so the speed had to be tuned down. Continuously changed the speed to get the car to move slow enough to stop at around 30 cm. Ended up with a speed of 50 and a gap of 25.