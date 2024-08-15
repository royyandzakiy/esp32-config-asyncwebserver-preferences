#pragma once

#include <Arduino.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include <functional>

#include "storage/ConfigStorage.h"
#include "credentials.h"

#ifndef CREDENTIALS_H
    #ifndef WIFI_SSID
    #define WIFI_SSID "WIFI_SSID_HERE"
    #endif

    #ifndef WIFI_PASS
    #define WIFI_PASS "WIFI_PASS_HERE"
    #endif
#endif // CREDENTIALS_H

// #define WIFI_MODE_STA
// #define WIFI_MODE_AP
#define WIFI_MODE_AP_STA

#define AP_SSID "ESP32-Access-Point"
#define AP_PASS "123456789"
#define PARAM_MESSAGE "message"

class WebServer {
    public:
        void init();
        void endPointRegister(AsyncWebServer *);
        static void notFound(AsyncWebServerRequest *);
    private:
        AsyncWebServer * server;
};

extern WebServer webServer;

void internetConnect();