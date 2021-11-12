#include "Arduino.h"
#include "Flasher.h"




Flasher :: Flasher(int led1,int led2,int led3,int led4,int led5,int led6,int led7){
    diode1=led1;
    diode2=led2;
    diode3=led3;
    diode4=led4;
    diode5=led5;
    diode6=led6;
    diode7=led7;
}

void Flasher::PinSetup(){
  delay(200U);
  Serial.flush();
  pinMode(diode1,OUTPUT);
  pinMode(diode2,OUTPUT);
  pinMode(diode3,OUTPUT);
  pinMode(diode4,OUTPUT);
  pinMode(diode5,OUTPUT);
  pinMode(diode6,OUTPUT);
  pinMode(diode7,OUTPUT); 
 
}

void Flasher::Sequence1(){
   
  
  digitalWrite(diode1,HIGH);
  delay(100);
  digitalWrite(diode2,HIGH);
  delay(100);
  digitalWrite(diode3,HIGH);
  delay(100);
  digitalWrite(diode4,HIGH);
  delay(100);
  digitalWrite(diode5,HIGH);
  delay(100);
  digitalWrite(diode6,HIGH);
  delay(100);
  digitalWrite(diode7,HIGH);
  delay(100);
 
  digitalWrite(diode7,LOW);
  delay(100);
  digitalWrite(diode6,LOW);
  delay(100);
  digitalWrite(diode5,LOW);
  delay(100);
  digitalWrite(diode4,LOW);
  delay(100);
  digitalWrite(diode3,LOW);
  delay(100);
  digitalWrite(diode2,LOW);
  delay(100);
  digitalWrite(diode1,LOW);
  delay(100);
  
}

