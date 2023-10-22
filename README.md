What is Arduino?
-	It is an open-source electronic prototyping platform enabling users to create interactive electronic objects, such as humidifier or thermometer
-	Hardware: Microcontroller (Small controller like a computer)
-	Software: Arduino IDE
-	Most common version of Arduino is Arduino UNO.
-	Arduino Programs are called SKETCH.

How does it work?
-	It reads INPUT
-	You can check the staus of INPUT by seeing the LED light
-	TURN ON the light of a SENSOR
-	TURN INTO the OUTPUT
-	TURN ON LED light

You can connect it to whatever you want to detect the humidity, such as the room temperature, plant watering system, etc.

How does BLINK work?
Examples < Basics < Blink
Sets PIN D13 as an OUTPUT and blinks the test LED on Arduino Board

PIN TYPES: There are 3 ARDUINO PIN TYPES, Digital pins, Analog pins, and Power pins

Digital Pins send and receive the digital data.
Digital Arduino PINS can be either LOW or HIGH.
digitalWrite (LOW) = TURN OFF THE LED BY MAKING THE VOLTAGE LOW (NO VOLTAGE)
digitalWrite (HIGH) = TURN ON THE LED BY MAKING THE VOLTAGE HIGH (CONSTANT VOLTAGE)

Switching the LED light is a common instance of Digital Output

POWER PINS: 3.3V, 5V, GND
3.3V powers sensors that need the voltage about 3.3

GND stands for Ground. A common or shared return route of electrical current to the power source that enables the completion of the circuit
Arduino board relies on 3.3V and 5V
 


2. What do I want to get out of ARDUINO?

-	Analysis over time on how much electricity I can save by using the humidifier.
“By not raising the temperature (which just dries out air more), you can lower your energy bill, especially if you use a humidifier.” – Ad from the Humidifier ENERGY STAR
 

-	What applications do we have using the Humidity Data from ARDUINO
•	Mid-October ~ Mid-December Electricity Price Check, in comparison to last year
•	Set Temperature for the entire month: 75F (NO manual change)
•	Same Temperature in Different Humidity Level
•	If the humidity is kept in 40% with ARDUINO, is it less likely to turn on the heater?

 

Possible Outcomes using the data

•	Dehumidification Efficiency: Compare the energy consumption of HVAC systems in scenarios where humidity levels are different, but temperatures are constant. This can help determine the impact of humidity on the system's energy efficiency.

•	Load Profile Analysis: Understand how the demand for heating or cooling varies with humidity levels. This can inform decisions about system sizing and capacity.

•	Setpoint Optimization: Adjust the setpoints for heating and cooling systems based on humidity levels to minimize energy consumption while maintaining comfort.

•	Comparative Studies: Conduct experiments to measure the energy consumption of appliances or systems under different humidity conditions. This can lead to insights for design improvements or operational changes.
