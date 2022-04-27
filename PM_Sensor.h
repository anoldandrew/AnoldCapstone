#ifndef PM_Sensor_H
#define PM_Sensor_H
#include "Fan.h"


#include <SDS011.h>


unsigned long pm25_threshold = 12;
unsigned long pm10_threshold = 35;


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
  if(!error){

  constexpr uint32_t work = 20; 
  count = millis() + work*1000; 
  while(static_cast<int32_t>(count - millis())>0){
    delay(1000); 
  }  

}
}

#endif 
