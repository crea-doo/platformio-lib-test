// ------------------------------

#include "config.h"

// ------------------------------

#include <Base.h>

// ------------------------------

Base base;

// ------------------------------

/*
   Setup after the device started.
   Initialize input and output pins as well as WiFi.
*/
void setup(void){
  // Initialize
  base.begin();

  // ------------------------------
  
  if (base.initiallyConnectedWiFi == true) {
  
    // ------------------------------
  
    DEBUG_PRINTLN("Connected to WiFi - Start up everything else...");

    // ------------------------------

  }
  
  // ------------------------------

}

// ------------------------------

void loop(void){
  if (base.initiallyConnectedWiFi == true) {
    //
  }
}

// ------------------------------
