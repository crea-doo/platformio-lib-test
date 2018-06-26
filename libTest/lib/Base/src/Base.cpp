#include "Base.h"

// ------------------------------

Base::Base()
{
    //
}

/**
 * This is the initialisation function for the Base class.
 */
bool Base::begin()
{
    // ------------------------------

    // Initialize serial and wait for port to open:
    Serial.begin(115200);

    // ------------------------------

    // Start with a new line
    DEBUG_PRINTLN("");
    DEBUG_PRINTLN("");

    // ------------------------------

    // Prepare GPIO
    if (WIFI_GPIO_LED >= 0) {
      pinMode(WIFI_GPIO_LED, OUTPUT);
      digitalWrite(WIFI_GPIO_LED, LOW);
    }

    // ------------------------------

    // check for the presence of the shield:
    if (WiFi.status() == WL_NO_SHIELD) {
        DEBUG_PRINTLN("WiFi shield not present");
        // Force WDT to restart - don't continue
        return false;
    }

    // ------------------------------

    // Try to connect to Wifi network:
    DEBUG_PRINT("WiFi connecting to '" + String(WIFI_SSID) + "'");
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    int wifiCounter = WIFI_MAX_TRIES;
    bool blinkState = LOW;

    while (WiFi.status() != WL_CONNECTED && wifiCounter > 0) {
      if (WIFI_GPIO_LED >= 0) {
        // let GPIO_LED blink during connection setup
        digitalWrite(WIFI_GPIO_LED, blinkState);
        blinkState = !blinkState;
      }
      delay(WIFI_DELAY_TRY);
      wifiCounter--;
      DEBUG_PRINT(".");
    }
    if (WIFI_GPIO_LED >= 0) {
      digitalWrite(WIFI_GPIO_LED, LOW);
    }
    DEBUG_PRINTLN("");

    /*
    * If connection is lost once established
    * See: https://arduino-esp8266.readthedocs.io/en/2.4.0/esp8266wifi/readme.html#quick-start
    * Note: if connection is established, and then lost for some reason, ESP will automatically
    * reconnect to last used access point once it is again back on-line. This will be done
    * automatically by Wi-Fi library, without any user intervention.
    */
    
    if (WiFi.status() == WL_CONNECTED) {
      initiallyConnectedWiFi = true;
      printWifiStatus();
    } else {
      initiallyConnectedWiFi = false;
      DEBUG_PRINTLN("WiFi could not be started. Deactivating all WiFi related stuff...");
      
      // Just restart if no connection could be made
      // Force WDT to restart - don't continue
      //while(true);
    }

    // ------------------------------

	// TODO: only return true if everything setup up correctly
	return true;
}

// ------------------------------

// Print out some info about the WiFi connection
void Base::printWifiStatus() {
  // Print the SSID of the network you're attached to:
  DEBUG_PRINT("SSID: ");
  DEBUG_PRINTLN(WiFi.SSID());

  // Print your WiFi shield's IP address:
  DEBUG_PRINT("IP Address: ");
  DEBUG_PRINTLN(WiFi.localIP());

  // Print your WiFi shield's MAC address:
  DEBUG_PRINT("MAC Address: ");
  DEBUG_PRINTLN(WiFi.macAddress());

  // Print the received signal strength:
  DEBUG_PRINT("Signal strength (RSSI):");
  DEBUG_PRINT(WiFi.RSSI());
  DEBUG_PRINTLN(" dBm");
}
