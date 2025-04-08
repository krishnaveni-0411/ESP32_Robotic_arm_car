#include <WiFi.h>
#include <ESP32Servo.h>
#include <WebServer.h>

// Replace with your WiFi credentials
const char* ssid = "your_wifi_name"; 
const char* password = "*********"; 

// Web server running on port 80
WebServer server(80);

// Servo objects
Servo baseServo, shoulderServo, elbowServo, gripperServo;

// Define GPIO pins for servos
#define BASE_SERVO_PIN      18
#define SHOULDER_SERVO_PIN  19
#define ELBOW_SERVO_PIN     21
#define GRIPPER_SERVO_PIN   22

void setup() {
    Serial.begin(115200);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected! IP Address: " + WiFi.localIP().toString());

    // Attach servos
    baseServo.attach(BASE_SERVO_PIN);
    shoulderServo.attach(SHOULDER_SERVO_PIN);
    elbowServo.attach(ELBOW_SERVO_PIN);
    gripperServo.attach(GRIPPER_SERVO_PIN);

    // Define server routes
    server.on("/", HTTP_GET, handleRoot);
    server.on("/move", HTTP_GET, handleMove);

    server.begin();
    Serial.println("Server started!");
}

// Serve the Web Page with Sliders
void handleRoot() {
    String html = "<html><head><style>"
                  "input {width: 300px; margin: 10px;}"
                  "h2 {font-family: Arial;}"
                  "</style></head><body>"
                  "<h2>ESP32 Robotic Arm Control</h2>"
                  "Base: <input type='range' min='0' max='180' id='base' oninput='sendValue(\"base\", this.value)'><br>"
                  "Shoulder: <input type='range' min='0' max='180' id='shoulder' oninput='sendValue(\"shoulder\", this.value)'><br>"
                  "Elbow: <input type='range' min='0' max='180' id='elbow' oninput='sendValue(\"elbow\", this.value)'><br>"
                  "Gripper: <input type='range' min='0' max='180' id='gripper' oninput='sendValue(\"gripper\", this.value)'><br>"
                  "<script>"
                  "function sendValue(servo, value) {"
                  "  var xhttp = new XMLHttpRequest();"
                  "  xhttp.open('GET', '/move?servo=' + servo + '&value=' + value, true);"
                  "  xhttp.send();"
                  "}"
                  "</script></body></html>";
    server.send(200, "text/html", html);
}

// Handle Servo Movement
void handleMove() {
    if (server.hasArg("servo") && server.hasArg("value")) {
        String servoName = server.arg("servo");
        int value = server.arg("value").toInt();

        if (servoName == "base") baseServo.write(value);
        else if (servoName == "shoulder") shoulderServo.write(value);
        else if (servoName == "elbow") elbowServo.write(value);
        else if (servoName == "gripper") gripperServo.write(value);

        Serial.println(servoName + " set to " + String(value));
        server.send(200, "text/plain", "OK");
    }
}

void loop() {
    server.handleClient();
}