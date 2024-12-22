#include <Wire.h>
#include "MAX30105.h"

MAX30105 particleSensor;
float beatsPerMinute = 0, beatAvg = 0;
#define RATE_SIZE 4
float rateValues[RATE_SIZE] = {0};
byte rateSpot = 0;
long lastBeatTime = 0;

void initializeHeartRateSensor() {
  if (!particleSensor.begin()) {
    Serial.println("MAX30105 non détecté. Vérifiez les connexions !");
    while (1);
  }

  particleSensor.setup();
  particleSensor.setPulseAmplitudeRed(0x1F);
  particleSensor.setPulseAmplitudeIR(0x1F);
  Serial.println("MAX30105 initialisé !");
}

void readHeartRate() {
  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue)) {
    long currentTime = millis();
    long delta = currentTime - lastBeatTime;
    lastBeatTime = currentTime;

    beatsPerMinute = 60.0 / (delta / 1000.0);
    if (beatsPerMinute > 20 && beatsPerMinute < 200) {
      rateValues[rateSpot++] = beatsPerMinute;
      rateSpot %= RATE_SIZE;

      beatAvg = 0;
      for (byte i = 0; i < RATE_SIZE; i++) {
        beatAvg += rateValues[i];
      }
      beatAvg /= RATE_SIZE;
    }
  }
  Serial.print("BPM : "); Serial.println(beatAvg);
}
