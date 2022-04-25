#ifndef wifi_code_H
#define wifi_code_H
#include <WiFi.h>
const char* ssid = "Anold";
const char* password = "0123456789"; 
//WiFiClient client;
//const char* ssid = "No Wifi";
//const char* password ="87yu31xjq";
void wifi_setup(){
  WiFi.begin(ssid,password); 
/* checking whether WiFi is connected.*/ 
  while (WiFi.status() != WL_CONNECTED){
  delay(400); 
  Serial.println("connecting to your hotpsot"); 
}
  Serial.println("connected yheeeh"); 
}

#endif 
