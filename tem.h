#ifndef tem_H
#define tem_H
#include "DHT.h"
#define DHT_tem 4

/* initialization of where temperature values will be stored*/ 
float temperature; 
float humidity; 
unsigned long Temperature_threshold = 25; 


// other defintions for the DHT
#define DHTTYPE DHT22 // selecting the type of DHT being used 
DHT dht(DHT_tem,DHT22); // creating a dht object on the pin with DHT22 

void temp_start(){
   dht.begin(); 
}

void dhtloop(){
  // initiating delay before measurements are takenn
  temperature = dht.readTemperature(); 
  humidity = dht.readHumidity(); 
 
  //Verify if readings are being recorded; else, exist and try again.. 
  if(isnan(temperature) || isnan(humidity)) {
    Serial.println(F("No readings recorded so far")); 
    return ; 
  }
}
#endif 
