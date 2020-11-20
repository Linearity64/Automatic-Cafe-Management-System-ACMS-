/*
  WEB CLIENT MODULE
  This module handles the ESP-01
  Functionality included: Connection, Client, and WebScraper
*/

void initWiFiModule() {

  // Init ESP-01
  WiFi.init(&espSerial);

  // Check for ESP-01 Module, don't continue if not found
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("[DEBUG] ESP-01 is not found");
    while (true);
  }

  // Attempt to connect to WiFi
  while (status != WL_CONNECTED) {
    Serial.print("[DEBUG] Attempting to connect... SSID : ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }

  /*
  // Display successful result
  Serial.print("[DEBUG] Connected to SSID : ");
  Serial.println(ssid);
  */
  
}

void httpRequest() {

  // Clean up serial monitor and close any connection before sending request
  Serial.println();
  client.stop();
  yield();

  // Check for successful connection
  if (client.connect(server, port)) {

    // GET REQUEST
    client.println(F("GET /asciilogo.txt HTTP/1.1"));
    client.print(F("Host: "));
    client.println(server);
    client.println("Connection: close");
    client.println();

    // Note last refresh time
    lastPostTime = millis();
  } else {
    Serial.println("[DEBUG] Connection failed");
  }

}

int scrape() {

  // Create a buffer
  char bufferArray[MAX_BUFFER_SIZE] = {0};

  // Find identifier character
  if (!client.find(identifier)) {
    Serial.println("[DEBUG] Identifier not found");
  } else {
    Serial.println("[DEBUG] Identifier found");

    // Read until the end identifier
    client.readBytesUntil(identifier, bufferArray, MAX_BUFFER_SIZE);

    /*
      Serial.println("BUFFER");
      for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
      Serial.print(bufferArray[i]);
      }
    */

    for (int i = 0; i < SCRAPED_ARRAY_SIZE; i++) {
      scrapedArray[i] = bufferArray[i];
    }
  }

}
