#include <OneWire.h>
#include <DallasTemperature.h>

#define DS18B20 5
OneWire oneWire(DS18B20);
DallasTemperature sensors(&oneWire);

float bodyTemperature = 0;

void initializeBodyTempSensor() {
  sensors.begin();
  Serial.println("DS18B20 initialisé !");
}

void readBodyTemperature() {
  sensors.requestTemperatures();
  bodyTemperature = sensors.getTempCByIndex(0);
  Serial.print("Température corporelle : "); Serial.println(bodyTemperature);
}
