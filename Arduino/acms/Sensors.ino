/*
  SENSORS MODULE
  This module handles robot's sensor
  Functionality included : TCRT, Load Cell
*/

void readTCRT() {

  int _f[4] = {};
  int _b[4] = {};
  for (int i = 0; i < 4; i++) {
    _f[i] = digitalRead(TCRTF[i]);
    _b[i] = digitalRead(TCRTB[i]);
  }

  int _pidError;
  parseTCRT();

}

void parseTCRT() {

}

void weightSensor() {
  Serial.println("[DEBUG] WAITING FOR LOAD");
  delay(1000);
  Serial.println("[DEBUG] Received order, sending...");
}
