#ifndef Fan_H
#define Fan_H


#define RELAY 14


void fan_setup(){
  pinMode(RELAY, OUTPUT); 
}



void fan_on(){
  digitalWrite(RELAY,HIGH); 
  Serial.println("fan on"); 
}


void fan_off(){
  digitalWrite(RELAY,LOW); 
  Serial.println("fan off"); 
}

#endif 
