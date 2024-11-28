## Task: Moving precisely 1m forward/back 

1. Based on the specifications of the [motor](https://www.dfrobot.com/product-1457.html) and the [wheel](https://www.dfrobot.com/product-1535.html), we can calculate the **distance per pulse of the encoder**.

2. We know that the diameter of the wheel is 80mm = 0.08m, and that the encoder resolution is 960. 

3. The distance traveled per revolution of the wheel is the circumference of the wheel = pi * wheel diameter = ~0.251m. 

4. Thus, the distance per encoder pulse is the distance per revolution / the encoder resolution = ~0.000261m/pulse = ~0.261mm/pulse.

5. To find the pulses in 1 meter, divide 1m/~0.000261m/pulse = ~3831 pulses per meter.

### Testing
In order to check our calculations, we plan on **testing how close the car gets to 1m** when working with the figure we found above and refining it as necessary.

To improve the precision of our car, we can multiply 3831 pulses/meter by the expected distance (1 meter) divided by the measured distance while testing.

### Failure to Complete Motion1

As of 11/27/24, we can't complete the Motion1 task. We believe that the problem is with the odometer outputs, because when running motion1.ino the car moves forward indefinitely. I wrote the following code to test the output of odom.getCount(), but nothing is printed to the serial monitor when we run it: 

```
#include <rcc.h>

Right_Odom odom;

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.print("encoder count: ");
    Serial.println(odom.getCount());
    delay(500);
}
```
Because of the lack of serial monitor output, I think the issue is hardware-related instead of a problem with the code in motion1.ino, and I plan to prioritize fixing this issue after the break. 
