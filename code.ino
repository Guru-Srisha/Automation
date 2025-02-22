// Blynk Credentials
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

// WiFi credentials
char ssid[] = "";
char pass[] = "";

#define LIGHT1_PIN 5
#define LIGHT2_PIN 18
#define LIGHT3_PIN 19
#define LIGHT4_PIN 21
#define GAS_SENSOR_PIN 32
#define BUZZER_PIN 22
#define SERVO_PIN 4

const int gasThreshold = 700; //Trial and error

Servo myServo;

void setup() {
  Serial.begin(115200);
  
  pinMode(LIGHT1_PIN, OUTPUT);
  pinMode(LIGHT2_PIN, OUTPUT);
  pinMode(LIGHT3_PIN, OUTPUT);
  pinMode(LIGHT4_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LIGHT1_PIN, LOW);
  digitalWrite(LIGHT2_PIN, LOW);
  digitalWrite(LIGHT3_PIN, LOW);
  digitalWrite(LIGHT4_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  myServo.attach(SERVO_PIN);
  myServo.write(0);

  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  Blynk.config(BLYNK_AUTH_TOKEN);
  if (Blynk.connect()) {
    Serial.println("Connected to Blynk!");
  } else {
    Serial.println("Failed to connect to Blynk.");
  }
}

BLYNK_WRITE(V1) { digitalWrite(LIGHT1_PIN, param.asInt()); }
BLYNK_WRITE(V2) { digitalWrite(LIGHT2_PIN, param.asInt()); }
BLYNK_WRITE(V3) { digitalWrite(LIGHT3_PIN, param.asInt()); }
BLYNK_WRITE(V4) { digitalWrite(LIGHT4_PIN, param.asInt()); }

void loop() {
  Blynk.run();

  int gasValue = analogRead(GAS_SENSOR_PIN);
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue > gasThreshold) {
    Serial.println("Gas level exceeded threshold!");
    Blynk.logEvent("gas_alert", "Gas level exceeded the safe threshold!");

    digitalWrite(BUZZER_PIN, HIGH);

    myServo.write(90);
    delay(5000);

    myServo.write(0);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(1000);
}
