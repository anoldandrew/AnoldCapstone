#ifndef wifi_code_H
#define wifi_code_H
#include <WiFi.h>
const char* ssid = "Anold";
const char* password = "0123456789"; 
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
