#ifndef oled_display_H
#define oled_display_H

#include <Wire.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> 

#define width 128
#define height 32

#define OLED_RESET -1
Adafruit_SSD1306 display(width,height, &Wire, OLED_RESET); 

void oled_setup(){ 
  
 if(!display.begin(SSD1306_SWITCHCAPVCC,0X3C)){
  Serial.println(F("could not allocate SSD1306")); 
  for(;;); // dont proceed, keep lopping 
 }
 delay(2000); // delay for the oled to have enough time and initialize 
 display.clearDisplay(); // clear the display
 display.setTextColor(WHITE); // setting the colour to white 
  display.display();
}

void oled_loop(){
  
// PM_Sensor data: PM25 and PM10 ----------------------------------
  display.clearDisplay(); 
  display.setTextSize(2); 
  display.setCursor(0,0); 
  display.print("PM_2.5: "); 
  display.setTextSize(2); 
  display.setCursor(80,0); 
  display.print(pm25); 

  display.setTextSize(2); 
  display.setCursor(0,15); 
  display.print("PM_10:"); 
  display.setTextSize(2); 
  display.setCursor(80,15); 
  display.print(pm10); 
  display.display(); 
  delay(3000); 
// Temperature and Humidity Sensor ------------------------------------

  display.clearDisplay(); 
  display.setTextSize(2); 
  display.setCursor(0,0); 
  display.print("Temp:"); 
  display.setTextSize(2); 
  display.setCursor(80,0); 
  display.print(temperature);
  display.cp437(true); // used to acces the degree symbol
  display.write(167); // location of the degree symbol. 
  display.setTextSize(2); 
  display.print("C");  

  display.setTextSize(2); 
  display.setCursor(0,15); 
  display.print("Humi:"); 
  display.setTextSize(2); 
  display.setCursor(80,15); 
  display.print(humidity);
  display.display(); 
  delay(1000); 

  //---MQ135--Carbondioxide Sensor-------------------------------------
  display.clearDisplay(); 
  display.setTextSize(2); 
  display.setCursor(0,0); 
  display.print("CO2: "); 
  display.setTextSize(2); 
  display.setCursor(80,15); 
  display.print(Mq_data);
  display.display(); 
   delay(200); 
}

#endif 
