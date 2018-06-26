#ifndef __BASE_H__
#define __BASE_H__

// ------------------------------

#ifndef DEBUG
#define DEBUG             0
#endif

// ------------------------------

#include "Debug.h"
#include <Arduino.h>

// ------------------------------

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// ------------------------------

#ifndef WIFI_SSID
#define WIFI_SSID       ""
#warning Please specify the missing define 'WIFI_SSID'
#else
#warning Define 'WIFI_SSID' is here!
#endif
#ifndef WIFI_PASS
#define WIFI_PASS       ""
#warning Please specify the missing define 'WIFI_PASS'
#else
#warning Define 'WIFI_PASS' is here!
#endif

// Maximum number of tries during WiFi connection setup
#ifndef WIFI_MAX_TRIES
#define WIFI_MAX_TRIES  30
#endif

// Delay in ms between checks during WiFi connection setup
#ifndef WIFI_DELAY_TRY
#define WIFI_DELAY_TRY  1000
#endif

// Pin for blinking LED while WiFi setup
#ifndef WIFI_GPIO_LED
#define WIFI_GPIO_LED   (-1)
#endif

// ------------------------------

class Base {

	public:
		explicit Base();
		~Base() = default;

        void printWifiStatus();

		bool initiallyConnectedWiFi = false;

		// Initialize
		bool begin();
};

// ------------------------------

#endif
