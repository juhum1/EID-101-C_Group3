## Task: Moving precisely 1m forward/back 

1. Based on the specifications of the [motor](https://www.dfrobot.com/product-1457.html) and the [wheel](https://www.dfrobot.com/product-1535.html), we can calculate the **distance per pulse of the encoder**.

2. We know that the diameter of the wheel is 80mm = 0.08m, and that the encoder resolution is 960. 

3. The distance traveled per revolution of the wheel is the circumference of the wheel = pi * wheel diameter = ~0.251m. 

4. Thus, the distance per encoder pulse is the distance per revolution / the encoder resolution = ~0.000261m/pulse = ~0.261mm/pulse.

5. To find the pulses in 1 meter, divide 1m/~0.000261m/pulse = ~3831 pulses per meter. 
