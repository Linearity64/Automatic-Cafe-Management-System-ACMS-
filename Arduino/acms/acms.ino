/*
  MAIN MODULE
  This module houses the main function of setup() and loop()
*/

// LIBRARIES
#include <WiFiEsp.h>
#include <SoftwareSerial.h>
#include "definitions.h"

// OBJECT CREATION
SoftwareSerial espSerial(RX_PIN, TX_PIN); // RX, TX
WiFiEspClient client;

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
      if(scrape() != 0){
        idle = false;
      } else {
        idle = true;
      }
    }
    
  } else {

    // SEND ACKNOWLEDGEMENT
    // WAIT FOR WEIGHT SENSOR
    // START MOVE ROUTINE
    // WAIT FOR WEIGHT SENSOR
    // START MOVE ROUTINE
    // RESET VARIABLES BACK TO IDLE
    
  }

}
