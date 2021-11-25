#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define DHTPIN   D4  // DHT22 Sensor            
#define DHTTYPE DHT22           // DHT22 if useDHT22
#define BLYNK_PRINT Serial

char auth[] = "DTXKhyTaUCbWVJbr2rojaPCEQ2GfRdz1";
char ssid[] = "Min'Laptop";
char pass[] = "12082542";

BlynkTimer timer;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  delay(500);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(" C ");   
  Blynk.run();
  Blynk.virtualWrite(V2, h);
  Blynk.virtualWrite(V3, t);
} 
