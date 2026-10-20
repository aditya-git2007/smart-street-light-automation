# Smart Street Light Automation — Wiring & Control Schematic

## ⚡ Power & Control Logic
* **Sensing Layer:** The LDR sensor forms a voltage divider with a 10kΩ pull-down resistor connected to `A0`. The PIR sensor outputs a digital 3.3V signal to `GPIO 14` upon detecting motion.
* **Actuation Layer:** `GPIO 12` drives an optocoupler relay module capable of safely switching high-voltage AC LED street lamps or DC LED strips.
