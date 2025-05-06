#include <DHT.h>

#define DHTPIN 2        // Digital Pin of Arduino connected to DHT22 data pin
#define DHTTYPE DHT22   // Specify DHT22 sensor

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600);  
  dht.begin();        
}

void loop(){
  delay(2000);  

  float humidity = dht.readHumidity();       // humidity
  float temperature = dht.readTemperature(); // temperature in Celsius

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}