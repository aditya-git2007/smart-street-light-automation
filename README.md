# smart-street-light-automation
Energy-efficient smart street lighting system using ESP32, LDR ambient light sensing, and PIR motion-triggered dimming.
# 💡 Smart Street Light Automation & Energy-Saving System

> An intelligent, autonomous street lighting prototype designed to reduce urban energy waste by dynamically modulating LED intensity based on ambient twilight (LDR) and real-time pedestrian/vehicle proximity (PIR motion detection).

[![Status](https://img.shields.io/badge/Status-Completed-emerald?style=for-the-badge)]()
[![MCU](https://img.shields.io/badge/MCU-ESP32_NodeMCU-blue?style=for-the-badge)]()


---

## 🎯 Overview & Mission Objective
Traditional streetlights burn energy continuously throughout the night regardless of traffic. This smart automation system uses a dual-sensor architecture:
1. **Twilight Sensing (LDR):** Automatically turns on the street lights only when ambient sunlight drops below a calibrated threshold.
2. **Proximity Dimming (PIR):** Keeps lights at a low, energy-saving standby glow; instantly ramps up to 100% brightness when motion is detected ahead, and dims back down after the vehicle or pedestrian passes.

---

## 🛠️ Bill of Materials (BOM)
| Component | Specification / Role |
| :--- | :--- |
| **NodeMCU ESP8266 / ESP32** | Wi-Fi enabled microcontroller for logic control and remote cloud monitoring |
| **PIR Motion Sensor (HC-SR501)** | Human / vehicle presence detection |
| **LDR (Light Dependent Resistor)** | Ambient light / twilight intensity monitoring |
| **Relay Module / MOSFET Driver** | High-power switching for LED street light arrays |
| **Power Supply** | Regulated 5V DC power bus |

---

## 📌 GPIO Pinout Mapping
| Component | Component Pin | ESP32 / ESP8266 Pin | Engineering Function |
| :--- | :--- | :--- | :--- |
| **PIR Motion Sensor** | `OUT` | `GPIO 14 (D5)` | Digital human presence trigger |
| **LDR Voltage Divider** | `Analog Out` | `A0 / ADC0` | Ambient light level measurement |
| **Relay / LED Driver** | `Control IN` | `GPIO 12 (D6)` | Street light power switching |

---

## 📂 Repository Structure
```text
📂 smart-street-light-automation
├── 📂 firmware             <-- C++ source code (street_light_controller.ino)
├── 📂 schematics           <-- Wiring & relay control specifications
└── 📄 README.md            <-- Project documentation
