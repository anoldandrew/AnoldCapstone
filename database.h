
#ifndef database_H
#define database_H
#include "wifi_code.h"
#include <HTTPClient.h>


String  host = "http://172.16.4.105:80/Capstone/connect.php?"; 

void database(){
    if(WiFi.status()== WL_CONNECTED){
 
      HTTPClient http;
    Serial.println("Database"); 
   
  
   String serverPath = host + ("temperature=") + temperature +
              ("&humidity=") + humidity +
              ("&Mq_data=") + Mq_data +
              ("&pm25=") + pm25 +
              ("&pm10=") + pm10;
              
  // Serial.println(serverPath);
 //  Serial.println(serverPath.c_str());
               
   http.begin(serverPath.c_str());
   int httpResponseCode = http.GET();
   
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      http.end();
      
    }
  
}

#endif 
