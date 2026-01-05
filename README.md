# esp32-blink-test
First ESP32 project using PlatformIO in Linux

# ESP32 Blink Test (PlatformIO + Linux)

This project is my first ESP32 test using PlatformIO on Linux.  
It verifies that the toolchain, drivers, serial port and upload process work correctly.

## Features
- PlatformIO build system
- ESP32 Dev Module (Espressif)
- Arduino framework
- Serial output ("ESP32 virker!")
- GPIO 2 LED blinking

## Requirements
- VSCode + PlatformIO
- ESP32 Dev Module
- Linux (tested on Ubuntu)
- USB-to-serial driver (CH340 or CP2102)

## How to build


# ESP32 TCP Client / Python Server

Dette prosjektet demonstrerer kommunikasjon mellom en ESP32 og en Python-basert TCP-server.

## Funksjonalitet
- ESP32 kobler til WiFi
- Sender JSON-data til server
- Server mottar og parser JSON
- Server kan sende kommandoer tilbake
- ESP32 reagerer (LED ON/OFF)

## Teknologi
- ESP32 (Arduino framework)
- PlatformIO
- Python 3
- TCP sockets
- JSON (ArduinoJson)

## Eksempel på JSON
```json
{
  "device": "ESP32",
  "temp": 23.4,
  "status": "ok"
}

# ESP32 IoT Client–Server (WiFi + JSON)

Dette prosjektet demonstrerer kommunikasjon mellom en **ESP32 (WiFi-klient)** og en **Python TCP-server**, med meldinger sendt i **JSON-format**.

Prosjektet er laget for å vise praktisk forståelse av:
- Nettverk (TCP/IP)
- Innebygde systemer (ESP32)
- JSON-basert kommunikasjon
- Klient–server-arkitektur

---

## 🔧 Teknologier brukt
- **ESP32** (Arduino framework)
- **C++ / Arduino**
- **Python 3**
- **WiFi (TCP socket)**
- **JSON (ArduinoJson + Python json)**
- **Git & GitHub**
- **PlatformIO / VSCode**

---

## 🧠 Systemoversikt


ESP32:
- Kobler seg til WiFi
- Sender status i JSON-format
- Mottar kommandoer (f.eks. LED_ON / LED_OFF)

Python-server:
- Lytter på TCP-port
- Parser JSON-meldinger
- Sender svar tilbake til ESP32

---

## 📡 Eksempel på JSON-melding

Fra ESP32 til server:
```json
{
  "device": "ESP32",
  "temp": 23.4,
  "status": "ok"
}

{
  "command": "LED_ON",
  "interval": 2000
}
