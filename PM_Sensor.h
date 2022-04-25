#ifndef PM_Sensor_H
#define PM_Sensor_H
#include "Fan.h"


#include <SDS011.h>
//#define pm25_threshold  12 
//#define pm10_threshold  35 

unsigned long pm25_threshold = 9;
unsigned long pm10_threshold = 30;


float pm25,pm10; 
int error, count, counter_three, counter_four; 

SDS011 pm_sensor; 


#ifdef ESP32
HardwareSerial port(2);
#endif


void pm_setup(){
  pm_sensor.begin(16,17); 
}

void pm_loop(){
  error = pm_sensor.read(&pm25, &pm10);
  if(!error){/*
    Serial.println("PM2.5 levels are at:  " + String(pm25)); 
    Serial.println("PM10 levels are at:  " + String(pm10)); *//* 
   if((pm25 >= pm25_threshold) || (pm10 >= pm10_threshold)){
      counter_four = 0; 
      counter_three++; 
     if(counter_three > 20){
    Serial.println("fan on coming "); 
        fan_on(); 
       counter_three =0; 
      }
      
    }
   while(! ((pm25 >= pm25_threshold) || (pm10 >= pm10_threshold))){
   counter_three = 0; 
   counter_four ++; 
   if(counter_four > 20){
    fan_off(); 
    counter_four=0; 
   }
   
  }*/
/*
    if ((pm25 >= pm25_threshold) || (pm10 >= pm10_threshold)){
       Serial.println("time to open window");
       fan_on();
       delay(10000); 
    }
  else if (! ((pm25 >= pm25_threshold) || (pm10 >= pm10_threshold))){
    fan_off(); 
    delay(10000); 
  }
  */
  constexpr uint32_t work = 20; 
  count = millis() + work*1000; 
  while(static_cast<int32_t>(count - millis())>0){
    delay(1000); 
  }  

}
}

#endif 
