# Robotic_arm_car
ESP32-Powered Robotic Car and Arm for Remote Assistance and Automation in Hazardous Environments
We at KL University have developed an automated system that combines a two-wheeled robotic car with a robotic arm, 
both operated wirelessly through a web server hosted on ESP32 microcontrollers. 
This system is designed to assist in hazardous or remote environments where direct human intervention is risky or impractical.
By using ESP32 modules, we can host a control interface on a local web server, 
enabling users to control both the robotic car and the arm from any browser-enabled device — without the need for any external router or app.

💡 Introduction
This project focuses on building a flexible and portable solution for remote robotic operations, 
ideal for scenarios such as search and rescue, surveillance, or handling hazardous materials.
The setup uses two separate ESP32 microcontrollers:
One dedicated to controlling the robotic car.
Another dedicated to controlling the robotic arm.
However, it's also possible to implement the entire system using a single ESP32, 
depending on memory and GPIO pin availability.

🧰 Technologies Used
This project is built using:
ESP32 Microcontroller (2 units)
Embedded C (Arduino IDE)
Web Technologies (HTML, CSS, JavaScript for the interface)
L298N Motor Driver for DC motors
Servo Motors for robotic arm movement
Wi-Fi for hosting the control web server
Battery Pack (for mobility and powering motors)

⚙️ Setup Instructions
Hardware Connections:
Assemble the robotic car with two DC motors connected to the L298N motor driver.
Connect servo motors for each joint in the robotic arm.
Connect the car setup to ESP32 #1, and the arm to ESP32 #2.
Power both ESP32s using regulated 5V power supply.

Software Upload:
Open Arduino IDE and upload the respective code files to each ESP32.
Ensure correct board and port are selected.
Use the provided HTML interface embedded in the ESP32 code to access controls.

Running the Web Server:
ESP32 creates a Wi-Fi hotspot or connects to an existing Wi-Fi network.
Access the control panel by entering the ESP32's IP address in a browser.
Use on-screen buttons to control car movement and arm articulation.

IMPORTANT NOTE:
⚠️ Never supply more than the required voltage (typically 3.3V-5V) to the ESP32. 
Over-voltage can irreversibly damage the microcontroller.
Always use voltage regulators or level shifters if needed.

📁 Output
Real-time, responsive control of both car and arm from a browser.
Clean, intuitive web interface hosted directly by ESP32.
Portable system — no dependency on external network or apps.
Capable of navigating and interacting with objects in tight or risky spaces.

🌟 Features
Full wireless control using local web server interface
Independent modules for robotic car and arm (but can be combined into one)
Compact and modular design
Real-time response and minimal latency
Smooth PWM control for motors and servos
Portable, app-free, and user-friendly
