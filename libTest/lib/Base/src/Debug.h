#ifndef __BASE_DEBUG_H__
#define __BASE_DEBUG_H__

// ------------------------------

#if DEBUG == 1
#define DEBUG_PRINT(x)  Serial.print (x)
#define DEBUG_PRINTLN(x)  Serial.println (x)
#define DEBUG_PRINTF(x, y)  Serial.printf (x, y)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINTF(x, y)
#endif

#endif
