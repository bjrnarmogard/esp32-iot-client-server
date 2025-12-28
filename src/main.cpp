
#include <Arduino.h>
#include <WiFi.h>

// 🔧 Endre disse
const char* ssid     = "Altibox257312";
const char* password = "qrv9PErq";

// 🔧 IP-adressen til PC-en som kjører server.py
const char* server_ip = "192.168.10.114";
const uint16_t server_port = 5000;

void connectToWiFi() {
    Serial.print("Kobler til WiFi");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("WiFi tilkoblet!");
    Serial.print("ESP32 IP: ");
    Serial.println(WiFi.localIP());
}

void sendMessageToServer() {
    WiFiClient client;

    Serial.println("Kobler til server...");

    if (!client.connect(server_ip, server_port)) {
        Serial.println("Kunne ikke koble til server");
        return;
    }

    Serial.println("Koblet til server");
    client.println("Hei fra ESP32!");
    client.stop();

    Serial.println("Melding sendt og forbindelse lukket");
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    connectToWiFi();
}

void loop() {
    sendMessageToServer();
    delay(5000);  // Send melding hvert 5. sekund
}

