#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

const int LED_PIN = 2;  // Innebygd LED på mange ESP32


const char* ssid = "Altibox257312";
const char* password = "qrv9PErq";

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    Serial.begin(115200);
    delay(2000);

    Serial.println("Starter ESP32...");
    WiFi.begin(ssid, password);

    Serial.print("Kobler til WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi tilkoblet!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}

const char* server_ip = "192.168.10.130";  // PC / VM
const uint16_t server_port = 5000;

void loop() {
    WiFiClient client;

    Serial.println("Kobler til server...");

    if (!client.connect(server_ip, server_port)) {
        Serial.println("❌ Kunne ikke koble til server");
        delay(8000);
        return;
    }

    Serial.println("✅ Koblet til server");

    // 1️⃣ Send JSON til server
    client.println("{\"device\":\"ESP32\",\"temp\":23.4,\"status\":\"ok\"}");

    // 2️⃣ Vent på svar
    unsigned long start = millis();
    while (millis() - start < 3000) {
        if (client.available()) {
            String response = client.readStringUntil('\n');
            Serial.print("Svar fra server: ");
            Serial.println(response);

            StaticJsonDocument<200> doc;
            DeserializationError error = deserializeJson(doc, response);

            if (!error) {
                const char* command = doc["command"];

                if (strcmp(command, "LED_ON") == 0) {
                    digitalWrite(LED_PIN, HIGH);
                    Serial.println("LED PÅ");
                }
                else if (strcmp(command, "LED_OFF") == 0) {
                    digitalWrite(LED_PIN, LOW);
                    Serial.println("LED AV");
                }
            }
            break;
        }
    }

    client.stop();
    delay(8000);
}


