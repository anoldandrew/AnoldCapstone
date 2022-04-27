#include "Actuator.h" 
#include "Fan.h"
#include "MQ_sensor.h"
#include "tem.h"
#include "PM_Sensor.h" 
#include "wifi_code.h"
#include "thingSpeak_setup.h"
#include "oled_display.h" 
#include "database.h"

void setup() {
      Serial.begin(9600);
      fan_setup(); 
      actuator_setup();
      wifi_setup();
      temp_start();
      pm_setup();
      oled_setup();  
      ThingSpeak.begin(client);   
}

void loop() {
     MQ_loop(); 
     dhtloop(); 
     pm_loop();
     oled_loop(); 
     dataupload();
     database(); 
     if ((Mq_data > Mq_data_threshold) && !((pm25 >= pm25_threshold) || (pm10 >= pm10_threshold))){
       open_window(); 
    }
    else if ( Mq_data < Mq_data_threshold){
      close_window();  
    } 
    
    else if ((Mq_data > Mq_data_threshold) && ((pm25 >= pm25_threshold) || (pm10 >= pm10_threshold))){
          email(); 
    }

    if (temperature > Temperature_threshold){
      fan_on(); 
    }
    else if (temperature < Temperature_threshold) {
      fan_off();  
    } 
}
