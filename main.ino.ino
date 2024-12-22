#include "wifi_setup.h"
#include "heart_rate.h"
#include "dht_reading.h"
#include "body_temp.h"
#include "blynk_setup.h"

void setup() {
  Serial.begin(115200);
  delay(100);

  // Initialisations
  setupWiFi();
  initializeHeartRateSensor();
  initializeDHTSensor();
  initializeBodyTempSensor();
  initializeBlynk();

  Serial.println("Système prêt !");
}

void loop() {
  Blynk.run();

  // Lecture des données
  readHeartRate();
  readTemperatureAndHumidity();
  readBodyTemperature();

  // Envoi des données à Blynk
  sendToBlynk();

  delay(1000); // Cycle de 1 seconde
}
