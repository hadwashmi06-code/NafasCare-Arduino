NafasCare – Arduino Alert Simulation

Overview

This prototype was developed using Tinkercad Circuits to demonstrate how the proposed NafasCare monitoring system could provide different alert levels.

NafasCare is a concept for monitoring uterine electrical activity (EHG) after childbirth. This Arduino prototype focuses on demonstrating the alert mechanism, not detecting postpartum hemorrhage.

Components

* Arduino Uno
* 16×2 LCD display
* Green, yellow, and red LEDs
* Buzzer
* Potentiometer to simulate changing sensor input

How It Works

The Arduino reads an adjustable analog input and converts it into a demonstration value from 0 to 100.

Based on this value, the system displays one of three states:

Simulated Value	Status	Response
0–39	NORMAL	Green LED
40–69	WARNING	Yellow LED
70–100	ALERT	Red LED and buzzer

The LCD displays the current status. The buzzer sounds only during the ALERT state.

What This Prototype Demonstrates

* A working three-level alert logic in a simulated Arduino circuit.
* Visual and audible responses to changing simulated input values.
* A possible alert mechanism for future integration with the proposed NafasCare system.

Testing

The simulation can be tested by adjusting the potentiometer in Tinkercad and observing the LCD, LEDs, and buzzer as the input crosses the demonstration thresholds.

Important Limitations

* The circuit is simulated in Tinkercad, not built as a physical device.
* It does not receive actual EHG recordings or patient data.
* The alert thresholds are for demonstration only and are not clinically validated.
* This prototype does not detect or predict postpartum hemorrhage.

Source Code

The Arduino sketch is available in this repository as NafasCare_Arduino.ino.
