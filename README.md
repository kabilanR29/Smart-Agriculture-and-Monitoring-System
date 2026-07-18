# Title:- Smart Agriculture Monitoring and Control System

## Project Overview :

The Smart Agriculture Monitoring and Control System is an embedded-based solution designed to assist farmers in monitoring field real conditions and receiving real-time updates through GSM Module communication. The system integrates multiple sensors(Soil Moisture Sensor and IR sensor) with an LPC21xx microcontroller to automate agricultural monitoring and improve crop management in real time basis.

## Features :

> Soil moisture level monitoring through soil moisture sensor for irrigation management.
> IR sensor-based field sensing activity and detection.
> GSM communication for sending alerts to framer and receiving commands from farmer.
> LCD display for real-time status monitoring.
> Real time intimation system for intimate critical field conditions.
> Remote interaction between farmer and device through SMS.

## Hardware Components :

* LPC21xx Microcontroller
* GSM Module (SIM800)
* Soil Moisture Sensor
* IR Sensor
* 16x2 LCD Display
* Power Supply Unit
* DC Motor
* L293D IC for connecting the DC Motor with microcontroller. 

## Working Principle

1. The soil moisture sensor continuously reads the moisture level of the soil.
2. The IR sensor detects movement or specific events in the field.
3. Sensor data is processed by the LPC21xx microcontroller.
4. Important information and alerts are displayed on the LCD screen.
5. The GSM module sends SMS notifications to the farmer whenever predefined conditions occur.
6. Farmers can send SMS commands to the device, and the received messages are displayed on the LCD, enabling remote communication ,monitoring and act according to the commands of farmer.

## Applications

* Smart Irrigation Systems
* Precision Agriculture
* Real time Crop Monitoring
* Remote Farm Management
* Agricultural Automation

## Benefits

-> Reduces water wastage.
-> Enables remote monitoring of farm conditions.
-> Improves crop productivity.
-> Minimizes manual field inspection.
-> Provides timely alerts and decision support for farmers.

## Technologies Used

* Embedded C
* LPC21xx ARM7 Microcontroller
* UART Communication
* GSM Technology
* Sensor Interfacing
* LCD Interfacing
* keil software
