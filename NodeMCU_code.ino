#include <WiFi.h>

const char* ssid = "Moto_"; // Hotspot SSID
const char* password = "12345678"; // Password

// Define the GPIO pins
#define ENA 16 // GPIO16 (D0 on some ESP32 boards)
#define IN1 17 // GPIO17 (D1 on some ESP32 boards)
#define IN2 18 // GPIO18 (D2 on some ESP32 boards)
#define IN3 19 // GPIO19 (D3 on some ESP32 boards)
#define IN4 21 // GPIO21 (D4 on some ESP32 boards)
#define ENB 22 // GPIO22 (D5 on some ESP32 boards)

int Speed = 100; // Set the speed (0-255)
WiFiServer server(1234);  // Port to listen for incoming commands

void setup() {
  Serial.begin(115200);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      String command = client.readStringUntil('\n');
      command.trim();

      // Here you can interpret the received data (e.g., command as number of fingers)
      int fingers = command.toInt();
      Serial.println(fingers);
      // Perform actions based on the received data (control your car's movement)
      // For example:
      if (fingers == 1) {
        carforward();
      } else if (fingers == 2) {
        carbackward();
      } else if (fingers == 3) {
        carturnright();
      } else if (fingers == 4) {
        carturnleft();
      } else if (fingers == 5 || fingers == 0) {
        carStop();
      } else {
        carStop();
      }
      Serial.println("Received command: " + command);
    }
    client.stop();
  }
}

void carforward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carbackward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carturnleft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carturnright() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}