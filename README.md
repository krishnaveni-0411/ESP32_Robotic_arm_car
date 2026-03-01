🚗 ESP32-Powered Robotic Car with Robotic Arm
Remote Assistance & Automation in Hazardous Environments

An ESP32-based wireless robotic system designed for remote operation in hazardous or inaccessible environments. The system integrates a two-wheeled robotic car with a multi-joint robotic arm, both controlled through a web interface hosted directly on ESP32 microcontrollers.

No external apps. No router required. Just open a browser and control.

📌 Overview

This project provides a portable and flexible robotic solution for applications such as:

🔍 Search and Rescue Operations

🛰️ Surveillance

☣️ Hazardous Material Handling

🏭 Remote Industrial Inspection

The system uses two ESP32 microcontrollers:

ESP32 #1 → Controls the robotic car

ESP32 #2 → Controls the robotic arm

⚡ The entire system can also be implemented using a single ESP32 depending on GPIO availability and memory usage.

🧠 System Architecture

User Device (Phone/Laptop Browser)
⬇
ESP32 Hosted Web Server
⬇
Motor Drivers & Servo Controllers
⬇
Robotic Car + Robotic Arm

The ESP32 hosts a local web server either:

As a Wi-Fi Hotspot (Access Point Mode), or

Connected to an existing Wi-Fi network

Users control movement through a browser-based interface built using HTML, CSS, and JavaScript.

🛠️ Technologies Used

ESP32 Microcontrollers (2 Units)

Embedded C (Arduino IDE)

HTML, CSS, JavaScript (Web Interface)

L298N Motor Driver

DC Motors

Servo Motors

Wi-Fi Communication

Battery Pack Power System

🔌 Hardware Setup
1️⃣ Robotic Car

Two DC motors connected to L298N Motor Driver

Motor driver connected to ESP32 #1

2️⃣ Robotic Arm

Servo motors for each joint

Connected to ESP32 #2

3️⃣ Power Supply

Regulated 5V power supply for ESP32

Separate motor power source recommended

Common ground between modules

⚠️ Important:
Never supply more than 3.3V–5V to the ESP32.
Over-voltage can permanently damage the microcontroller.
Use proper voltage regulators and level shifters where necessary.

💻 Software Setup
Step 1: Upload Code

Open Arduino IDE

Select correct ESP32 board

Choose correct COM port

Upload respective code to each ESP32

Step 2: Start Web Server

ESP32 creates Wi-Fi hotspot OR connects to Wi-Fi

Open browser and enter ESP32 IP address

Control panel loads automatically

🎮 Features

✅ Full Wireless Control via Browser

✅ No Mobile App Required

✅ Real-Time Motor & Servo Control

✅ Smooth PWM-Based Movement

✅ Modular Design

✅ Portable & Independent Operation

✅ Minimal Latency Communication

📂 Output

Real-time movement control of robotic car

Precise arm articulation

Clean and responsive web interface

Operates without external routers or applications

Suitable for confined or hazardous environments
