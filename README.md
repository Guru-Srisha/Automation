# **Smart Home Automation with ESP32 & Blynk**  

## **Overview**  
This project is an ESP32-based smart home automation system that enables remote control of appliances via relays using Blynk Cloud. It also features an automatic gas leakage detection system that triggers alerts and safely shuts off the gas regulator to prevent hazards.  

## **Features**  
- **Remote Appliance Control** – Turn devices ON/OFF via Blynk app.  
- **Gas Leakage Detection** – Detects gas leaks using an MQ-series sensor.  
- **Automatic Safety Mechanism** – Shuts off the gas regulator when a leak is detected.  
- **Real-time Alerts** – Sends notifications through Blynk for immediate action.  
- **Manual Override** – Allows users to manually control the gas shut-off system.  
- **WiFi Connectivity** – Connects to Blynk Cloud for seamless remote operation.  

## **Hardware Requirements**  
- **ESP32** – Microcontroller for automation & cloud connectivity.  
- **Relay Module** – Controls appliances.  
- **Gas Sensor MQ-135** – Detects gas leaks.  
- **Servo Motor** – Shuts off the gas regulator.  
- **Buzzer** – Provides alert signals. 

## **Software & Libraries**  
- **Arduino IDE** – For programming the ESP32.  
- **Blynk Library** – To connect with Blynk Cloud.  
- **ESP32 WiFi Library** – For internet communication.  
- **Servo Library** – To control the gas shut-off mechanism.  
