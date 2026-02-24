// Interface and connect DHT sensor to ESP32 and write program to display the temperature and humidity data
// Aim: 
// Fetching sensor data and displaying in the serial monitor
//
// Components required:
// - ESP32
// - DHT11

#include "DHT.h" // DHT sensor library by Adafruit
#define DHTTYPE DHT11
#define DHTPIN 18
DHT dht(DHTPIN, DHTTYPE);

void setup(){ 
  Serial.begin(9600);
  Serial.println("Printing data now...");

  dht.begin();
}

void loop(){
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(t) || isnan(h)){
    Serial.println("Error reading data...");
    return;
  }

  float heatIndex = dht.computeHeatIndex(t, h, false);

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" Humidity: ");
  Serial.print(h);
  Serial.print(" heatIndex: ");
  Serial.print(headIndex);

  return;
}
