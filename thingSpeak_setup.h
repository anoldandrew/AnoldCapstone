#ifndef thingSpeak_setup_H
#define thingSpeak_setup_H
#include "wifi_code.h"

#include "ThingSpeak.h"
unsigned long last = 0; 
unsigned long Delay_thingspeak = 30000; // frequency of publishing data to thingspeak. 
WiFiClient client; // the WI-FI client connects to ThingSpeak 
/*-------------------------------------------*/ 
/* configuration for API key and Channel ID */ 
unsigned long channel_ID = 1651531; 
const char * API_key = "BJKDQQ9RH48DC8MV"; 



void dataupload(){
  if ((millis() - last) > Delay_thingspeak)
            {
              ThingSpeak.setField(1,temperature); 
              ThingSpeak.setField(2, humidity);
              ThingSpeak.setField(3,pm25); 
              ThingSpeak.setField(4,pm10);
              ThingSpeak.setField(5,Mq_data); 
           int Cons = ThingSpeak.writeFields(channel_ID,API_key); 
  
  if(Cons == 200){
           Serial.println("ThingSpeak data successfully published"); 
            }

  else{
           Serial.println("Problems with your channel" + String(Cons)) ; 
  }
   last = millis(); 
 
}
}

#endif 
