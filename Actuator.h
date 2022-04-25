#ifndef ACTUATOR_H
#define ACTUATOR_H


int actuator_pin_one = 26; 
int actuator_pin_two = 27; 



void actuator_setup(){ 
   pinMode(actuator_pin_one, OUTPUT); 
   pinMode(actuator_pin_two, OUTPUT); 
   
}


void open_window(){
  digitalWrite(actuator_pin_one, LOW); 
  digitalWrite(actuator_pin_two, HIGH);
  Serial.println("openning window"); 
  }


void close_window(){
  digitalWrite(actuator_pin_one, HIGH); 
  digitalWrite(actuator_pin_two, LOW); 
    Serial.println("closing window"); 
}


void stop_actuator(){
  digitalWrite(actuator_pin_one, LOW); 
  digitalWrite(actuator_pin_two, LOW);
    Serial.println("stop actautor");   
}
#endif 
