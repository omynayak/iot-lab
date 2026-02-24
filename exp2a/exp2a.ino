// Interface and connect DHT sensor to ESP32 and write program to display the temperature and humidity data
// Aim: 
// Fetching sensor data and displaying in the serial monitor
//
// Components required:
// - ESP32
// - DHT11

// Interface and connect DHT sensor to ESP32 and write program to display the temperature and humidity data
// Aim: 
// Fetching sensor data and displaying in the serial monitor
//
// Components required:
// - ESP32
// - DHT11

#include "DHT.h" // DHT sensor library by Adafruit
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// DHT program:
#define DHTTYPE DHT11
#define DHTPIN 18
DHT dht(DHTPIN, DHTTYPE);

// OLED init:
Adafruit_SSD1306 display(128, 64, &Wire, -1);


void setup(){ 
  Wire.begin(21, 22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.println("System init...");
  display.display();

  dht.begin();
}

void loop(){
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(t) || isnan(h)){
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Error reading data...");
    return;
  }


#include "DHT.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// DHT Configuration
#define DHTTYPE DHT11
#define DHTPIN 18
DHT dht(DHTPIN, DHTTYPE);

// OLED Configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() { 
  Wire.begin(21, 22);

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); 
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    display.setTextSize(1);
    display.println("Sensor Error!");
    display.display();
    return;
  }

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("TEMPERATURE");
  display.setTextSize(2);
  display.print(t, 1); 
  display.println(" C");

  display.setCursor(0, 35);

  display.setTextSize(1);
  display.println("HUMIDITY");
  display.setTextSize(2);
  display.print(h, 0);
  display.println(" %");

  display.display();
}

  return;
}
