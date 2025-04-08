#include <WiFi.h>
#include <WebServer.h>

// Replace with your Wi-Fi credentials
const char* ssid = "your_wifi_name";
const char* password = "********";

// Define Motor Pins
#define ENA 32  // PWM Speed control for Motor A
#define IN1 25  // Motor A control pin
#define IN2 26  // Motor A control pin
#define IN3 27  // Motor B control pin
#define IN4 14  // Motor B control pin
#define ENB 33  // PWM Speed control for Motor B

WebServer server(80);

// Function to move the car
void moveCar(String direction) {
    Serial.println("Command: " + direction);

    if (direction == "forward") {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    } 
    else if (direction == "backward") {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    } 
    else if (direction == "left") {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    } 
    else if (direction == "right") {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    } 
    else if (direction == "stop") {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
    }

    server.send(200, "text/plain", "OK");
}

// HTML Web Page
String webpage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Robotic Car</title>
    <style>
        body { font-family: Arial; text-align: center; margin-top: 50px; }
        .btn { font-size: 20px; padding: 10px; width: 120px; margin: 10px; }
        .container { display: flex; flex-direction: column; align-items: center; }
        .row { display: flex; justify-content: center; }
    </style>
</head>
<body>
    <h2>ESP32 Robotic Car Control</h2>
    <div class="container">
        <div class="row">
            <button class="btn" onclick="sendCommand('forward')">Forward</button>
        </div>
        <div class="row">
            <button class="btn" onclick="sendCommand('left')">Left</button>
            <button class="btn" onclick="sendCommand('stop')">Stop</button>
            <button class="btn" onclick="sendCommand('right')">Right</button>
        </div>
        <div class="row">
            <button class="btn" onclick="sendCommand('backward')">Backward</button>
        </div>
    </div>

    <script>
        function sendCommand(command) {
            fetch('/move?cmd=' + command)
                .then(response => response.text())
                .then(data => console.log(data))
                .catch(error => console.error('Error:', error));
        }
    </script>
</body>
</html>
)rawliteral";

// Handle Web Page
void handleRoot() {
    server.send(200, "text/html", webpage);
}

// Handle Car Movement
void handleMove() {
    if (server.hasArg("cmd")) {
        String command = server.arg("cmd");
        moveCar(command);
    }
}

// Setup Function
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("\nConnected to WiFi!");
    Serial.println("IP Address: " + WiFi.localIP().toString());

    // Initialize Motor Pins
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    // Set initial speed
    analogWrite(ENA, 80);  // Adjust speed (0-255)
    analogWrite(ENB, 80);

    // Start Web Server
    server.on("/", HTTP_GET, handleRoot);
    server.on("/move", HTTP_GET, handleMove);
    server.begin();
    
    Serial.println("Web Server Started!");
}

// Loop Function
void loop() {
    server.handleClient();
}
