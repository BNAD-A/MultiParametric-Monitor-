#include "DHT.h"

#define DHTPIN 18
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float temperature = 0, humidity = 0;

void initializeDHTSensor() {
  dht.begin();
  Serial.println("DHT11 initialisé !");
}

void readTemperatureAndHumidity() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (!isnan(t) && !isnan(h)) {
    temperature = t;
    humidity = h;
  } else {
    Serial.println("Erreur de lecture du DHT11 !");
  }

  Serial.print("Température : "); Serial.println(temperature);
  Serial.print("Humidité : "); Serial.println(humidity);
}
