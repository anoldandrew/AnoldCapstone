#ifndef MQ_sensor_H
#define MQ_sensor_H
#include "MQ135.h"
#include "tem.h"



#define PIN_MQ135 34                       //Analog feed we are receiving from the MQ135 carbondioxide gas sensor 
MQ135 mq135_sensor = MQ135(PIN_MQ135);

int Mq_data = 0;                               //int for calculated ppm
int Mq_data_threshold = 800; 
 
void MQ_loop()
{
  float rzero = mq135_sensor.getRZero();
  float correctedRZero = mq135_sensor.getCorrectedRZero(temperature, humidity);
  float resistance = mq135_sensor.getResistance();
  float ppm = mq135_sensor.getPPM();
  float pinMQ135 = mq135_sensor.getCorrectedPPM(temperature, humidity);
  
 
  int c02_array[10];                                    //int array for co2 readings
  int co2_raw_value = 0;                               //int for raw value of co2
  int average = 0;                                    //int for averaging


  for (int x = 0;x<10;x++)  // add samples in over 0.8 seconds 
  {                  
    c02_array[x]=analogRead(PIN_MQ135);
    delay(800);
  }

  for (int x = 0;x<10;x++)  //adding togethor the samples in the array. 
  {                    
    average = average + c02_array[x];  
  }
 
  co2_raw_value = average/10;                            //divide samples by 10
  Mq_data= co2_raw_value;                //get calculated ppm

  Serial.print("MQ135 RZero: ");
  Serial.print(rzero);
  Serial.print("\t Corrected RZero: ");
  Serial.print(correctedRZero);
  Serial.print("\t Resistance: ");
  Serial.print(resistance);
  Serial.print("\t PPM: ");
  Serial.print(ppm);
  Serial.print("\t Corrected PPM: ");
  Serial.print(Mq_data);
  Serial.println("ppm");
}
#endif 
