#ifndef AsyncElegantOTA_h
#define AsyncElegantOTA_h

#warning AsyncElegantOTA.loop(); is deprecated, please remove it from loop() if defined. This function will be removed in a future release.

#include "Arduino.h"
#include "stdlib_noniso.h"

#if defined(ESP8266)
    #include "ESP8266WiFi.h"
    #include "ESPAsyncTCP.h"
    #include "flash_hal.h"
    #include "FS.h"
#elif defined(ESP32)
    #include "WiFi.h"
    #include "AsyncTCP.h"
    #include "Update.h"
    #include "esp_int_wdt.h"
    #include "esp_task_wdt.h"
#endif

#include "Hash.h"
#include "ESPAsyncWebServer.h"
#include "FS.h"

#include "elegantWebpage.h"


class AsyncElegantOtaClass{

    public:
        void
            setID(const char* id),
            begin(AsyncWebServer *server, const char* username = "", const char* password = ""),
            loop(),
            restart();
        
        // Returns whether we're updating the firmware (accessing the flash) or not
		bool want_to_update(){ return _want_to_update; }
		void can_update(){ _can_update = true; }

    private:
        AsyncWebServer *_server;

        String getID();

        String _id = getID();
        String _username = "";
        String _password = "";
        bool _authRequired = false;
        
        // Add this to know what's happening
		bool _want_to_update = false;
		bool _can_update = false;

};

extern AsyncElegantOtaClass AsyncElegantOTA;

#endif
