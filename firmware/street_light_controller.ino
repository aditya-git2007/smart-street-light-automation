```cpp
// ==========================================
// SMART STREET LIGHT AUTOMATION SYSTEM
// LDR Twilight Detection & PIR Motion Dimming
// Developer: Aditya Kumar Gupta (aditya.geninfo.in)
// ==========================================

#define PIR_PIN     14  // D5 on NodeMCU/ESP32
#define LIGHT_PIN   12  // D6 to Relay/LED Driver
#define LDR_PIN     A0  // Analog light sensor pin

const int DARK_THRESHOLD = 600; // ADC threshold for twilight
unsigned long lastMotionTime = 0;
const unsigned long TIMEOUT = 10000; // Hold full brightness for 10s after motion

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  Serial.begin(115200);
  digitalWrite(LIGHT_PIN, LOW);
}

void loop() {
  int ambientLight = analogRead(LDR_PIN);
  bool isDark = (ambientLight > DARK_THRESHOLD);
  bool motionDetected = (digitalRead(PIR_PIN) == HIGH);

  if (isDark) {
    if (motionDetected) {
      lastMotionTime = millis();
      digitalWrite(LIGHT_PIN, HIGH); // Full Brightness on Motion
      Serial.println("Motion detected in dark! Lights at 100%.");
    } 
    else if (millis() - lastMotionTime > TIMEOUT) {
      digitalWrite(LIGHT_PIN, LOW);  // Standby Dim / Off when clear
      Serial.println("No motion. Standby mode.");
    }
  } else {
    digitalWrite(LIGHT_PIN, LOW);    // Daytime: Lights OFF
    Serial.println("Daytime. Lights OFF.");
  }
  
  delay(500);
}
