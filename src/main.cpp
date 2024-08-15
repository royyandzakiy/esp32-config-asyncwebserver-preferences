#include "webserver/WebServer.h"

WebServer webServer;
ConfigStorage configStorage;

void setup(){
  Serial.begin(115200);
  Serial.println("Start");

  webServer.init();

  Serial.println("End");
}

void loop() {
    
}