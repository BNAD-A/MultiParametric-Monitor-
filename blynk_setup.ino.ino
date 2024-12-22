#include <BlynkSimpleEsp32.h>
#include "config.h"

void initializeBlynk() {
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Blynk connecté !");
}

void sendToBlynk() {
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, beatAvg);
  Blynk.virtualWrite(V4, bodyTemperature);
}
