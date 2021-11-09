#include <Arduino.h>
// include the Servo library
#include <Servo.h>

//servo int
Servo myServo;  // create a servo object
int servoAngle=0; // variable to hold the angle for the servo motor

//lasor int:
int photoSensorPin=2;
int photoSensorVal=0;
int previousPhotosState=0;

void setup() {
  Serial.begin(9600); // open a serial connection to your computer
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  
}

void loop() {

int currentPhotosState = analogRead(photoSensorPin);
  
  // servo motor
   myServo.write(servoAngle);
   Serial.print("Servo angle:");
   Serial.println(servoAngle);

   // laser
   photoSensorVal= analogRead(photoSensorPin);
   Serial.print("Photosensor: ");
   Serial.println(photoSensorVal);

if (previousPhotosState==0&&currentPhotosState>500) {  
    
    Serial.println("accepted");
  // set the servo position
   servoAngle=120;
   myServo.write(servoAngle);
   delay(1000); //DELAY TO REPLACE
   //accepted==true;
   servoAngle=0;
   myServo.write(servoAngle);
   delay(2000); //DELAY TO REPLACE
}

else if (previousPhotosState>500){
    
    Serial.println("declined");
    servoAngle=0;
    myServo.write(servoAngle);
}

previousPhotosState = currentPhotosState;
}