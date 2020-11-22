/*
  MAIN MODULE
  This module houses the main function of setup() and loop()
*/

// LIBRARIES
#include <WiFiEsp.h>
#include <SoftwareSerial.h>
#include <HX711.h>
#include "definitions.h"

// OBJECT CREATION
SoftwareSerial espSerial(RX_PIN, TX_PIN); // RX, TX
WiFiEspClient client;
HX711 scale;

void setup() {

  // Set up serial communications for both ESP-01 and Serial Monitor
  Serial.begin(9600);
  espSerial.begin(9600);

  initWiFiModule();

}

void loop() {

  // If robot is idle, check website
  if (idle) {

    // REFRESH CONNECTION
    if (millis() - lastPostTime > postInterval) {
      httpRequest();

      // If data is found after scraping, exit idle mode
      scrape();
      if (scrapedArray[0] != '0' && scrapedArray[0] != NULL) {
        idle = false;
      } else {
        idle = true;
        for (int i = 0; i < SCRAPED_ARRAY_SIZE; i++) {
          scrapedArray[i] = 0;
        }
      }

      Serial.println();
    }


  } else {

    sendResponse(interpretScrapedArray());
    weightSensor();
    moveRobot();
    weightSensor();
    moveRobot();

    Serial.println("[DEBUG] Turning back to idle...");
    idle = true;

  }

}
