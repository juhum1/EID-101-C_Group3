## Group 3 Reflective Light Sensor Array Library Documentation

### Functions

Our library has 5 functions relating to the sensor array, which are begin(), update(), getSensorValue(), getSensorValues(), and printValues(). 

**begin()** initializes the pins connected to each sensor for input.

**update()** reads each of the pins with analogRead() and updates the array of sensor values accordingly.

**getSensorValue()** returns the value of a specific sensor specified by an index. 

**getSensorValues()** returns the values of all sensors in the array. 

**printValues()** prints the array of sensor values to the serial monitor. 

### Usage
To use our library, begin by making an instance of the ReflectiveLightArray class.

This should be done by supplying an **array of sensor pins** (pins on the Arduino that each sensor is connected to) and the **number of sensors in use**. In our example sketch, our array was {A0, A1, A2, 12, 11}, and the number of sensors was 5. 

Next, use **begin()** to set the pinMode of the pins in the array to INPUT. Afterwards, we can simply use **update()** in a loop to continuously update the status of each sensor, and we can use **printValues()** to show the updated values in the serial monitor. 

In our example sketch, we used delay(500) in our loop to space out the outputs being printed to the serial monitor, but this isn't always a necessary step. 
