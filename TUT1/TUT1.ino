#include <SoftwareSerial.h>   
#define sensorPin A0
SoftwareSerial BT(8, 9);
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {
  if(Serial.available()>0){ 
    char re = Serial.read();
    
    switch(re){
     case 'E':
     start();
     break; 
    }
  }
  if(BT.available()>0){ 
    char re = BT.read();
    Serial.print(re);
    switch(re){
     case 'E':
     start();
     break; 
    }
  }
}

void start(){
 while(1){
  Serial.print('s');
  BT.print('s');
  Serial.print(floatMap(analogRead(sensorPin),0,1023,0,5),2);
  BT.print(floatMap(analogRead(sensorPin),0,1023,0,5),2);
  delay(30);
  
  if(Serial.available()>0){
    if (Serial.read()=='Q') return;
  }
  if(BT.available()>0){
    if (BT.read()=='Q') return;
  }
 } 
}

float floatMap(float x, float inMin, float inMax, float outMin, float outMax){
  return (x-inMin)*(outMax-outMin)/(inMax-inMin)+outMin;
}
