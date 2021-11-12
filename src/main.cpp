#include <Arduino.h>
#include <Servo.h>
#include <runtimer.h>

#define photoSensorPin 2             // photo Sensor on I/O pin 2
#define servoMotorPin 9              // servo motor control on I/O 9
#define servoOpenPosition 120        // servo value for open
#define servoClosedPosition 0        // servo value for closed

static constexpr int unlockTime{1000};        // how long to open for 1 candy [ms]
bool isLocked{true};                          // is the lock closed (true) or open (false)
int cardWasPresent = 0;                   // remembers if there was a card present the previous time we checked it
int cardIsPresent;
singleTimer openLockTimer;                    // timer controlling how long to open the lock for 1 candy
Servo myServo;                                // create a servo object

bool cardInserted() {        // returns 'true' if a card insert is detected
    bool result = false;
    int cardIsPresent = analogRead(photoSensorPin);
    Serial.println(cardIsPresent);
    if (cardWasPresent==0 && cardIsPresent>20) {
        Serial.println("card inserted");
        result = true;
    }
    else {
        //Serial.println("card removed");
    }
    cardWasPresent = cardIsPresent;
    return result;
}

void lock() {
    isLocked = true;                           // remember we are locked
    myServo.write(servoClosedPosition);        // set motor to locking position
    Serial.println("locking");                 // log a msg
}

void unlock() {
    isLocked = false;                        // remember we are unlocked
    myServo.write(servoOpenPosition);        // set motor to open position
    Serial.println("unlocking");             // log a msg
}

void setup() {
    Serial.begin(115200);                         // open a serial connection to your computer, for monitoring
    //pinMode(photoSensorPin, INPUT_PULLUP);        // set card sensor pin to input, with pullup resistor
    myServo.attach(servoMotorPin);                // attaches the servo on pin 9 to the servo object
    lock();
}

void loop() {
    bool isCardInserted = cardInserted();        // check if card is inserted
    if (isLocked && isCardInserted) {            // when we are locked and a card insert is detected
        unlock();                                // open the lock
        openLockTimer.start(unlockTime);         // start a timer
    }
    if (openLockTimer.expired()) {        // after some time
        lock();                           // close the lock
        //delay(2000);  is not needed
    }
}