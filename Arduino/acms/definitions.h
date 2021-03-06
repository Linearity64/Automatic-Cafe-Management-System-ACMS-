// PIN DEFINITIONS
const int RX_PIN = 2;
const int TX_PIN = 3;
const int IN1 = 4;
const int IN2 = 5;
const int ENA = 6;
const int IN3 = 7;
const int IN4 = 8;
const int ENB = 9;
const int LC_DT = A0;
const int LC_SCK = A1;
const int TCRTF[] = {10, 11, 12, 13};
const int TCRTB[] = {A2, A3, A4, A5};

// MAIN VARIABLES
bool idle = true;

// ESP-01 VARIABLES
const char ssid[] = "OPPO F9";         // WIFI SSID
const char pass[] = "12345678";        // WIFI PASSWORD
const char server[] = "arduino.cc";    // SERVER, FILL WITH SERVER'S IP ADDRESS
const int port = 80;                   // PORT NUMBER, 8080 FOR LOCAL
const long postInterval = 10000L;      // In milliseconds
long lastPostTime = 0;                 // In milliseconds
int status = WL_IDLE_STATUS;
const char identifier = "|";
const int SCRAPED_ARRAY_SIZE = 20;
const int MAX_BUFFER_SIZE = 100;
int scrapedArray[SCRAPED_ARRAY_SIZE] = {};
