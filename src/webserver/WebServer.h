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

// #define MAIN_STA
// #define MAIN_SOFT_AP
#define MAIN_AP_STA

#ifndef WIFI_SSID
#define WIFI_SSID "WIFI_SSID_HERE"
#endif

#ifndef WIFI_PASS
#define WIFI_PASS "WIFI_PASS_HERE"
#endif

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

void internetConnect();

extern WebServer webServer;
