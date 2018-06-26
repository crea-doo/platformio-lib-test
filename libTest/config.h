#ifndef __CONFIG_H__
#define __CONFIG_H__

// ------------------------------

/* ------------------------------
 * General configuration
 * ------------------------------ */

#ifndef DEBUG
#define DEBUG               0
#endif


/* ------------------------------
 * WiFi connection configuration
 * ------------------------------ */
#ifndef WIFI_SSID
#define WIFI_SSID           "myssid"
#endif
#ifndef WIFI_PASS
#define WIFI_PASS           "mypassword"
#endif

// Pin for blinking LED while WiFi setup
#ifndef WIFI_GPIO_LED
#define WIFI_GPIO_LED       13
#endif


#endif
