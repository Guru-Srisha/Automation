#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk credentials
char auth[] = ""; 

// WiFi credentials
char ssid[] = "";
char pass[] = "";

#define RELAY_1 D1
#define RELAY_2 D2
#define RELAY_3 D3
#define RELAY_4 D4

void setup() {
    Serial.begin(115200);
    
    WiFi.begin(ssid, pass);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected!");
    
    Blynk.begin(auth, ssid, pass);
    
    pinMode(RELAY_1, OUTPUT);
    pinMode(RELAY_2, OUTPUT);
    pinMode(RELAY_3, OUTPUT);
    pinMode(RELAY_4, OUTPUT);
    
    digitalWrite(RELAY_1, LOW);
    digitalWrite(RELAY_2, LOW);
    digitalWrite(RELAY_3, LOW);
    digitalWrite(RELAY_4, LOW);
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi Disconnected! Reconnecting...");
        WiFi.begin(ssid, pass);
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
        Serial.println("\nWiFi reconnected!");
    }
    Blynk.run();
}

BLYNK_WRITE(V1) {
    int state = param.asInt();
    digitalWrite(RELAY_1, state ? HIGH : LOW);
}

BLYNK_WRITE(V2) {
    int state = param.asInt();
    digitalWrite(RELAY_2, state ? HIGH : LOW);
}

BLYNK_WRITE(V3) {
    int state = param.asInt();
    digitalWrite(RELAY_3, state ? HIGH : LOW);
}

BLYNK_WRITE(V4) {
    int state = param.asInt();
    digitalWrite(RELAY_4, state ? HIGH : LOW);
}
