#ifndef Flasher_h
#define Flasher_h
#include "Arduino.h"

class Flasher {
  private:

  int diode1;
  int diode2;
  int diode3;
  int diode4;
  int diode5;
  int diode6;
  int diode7;


  public:
   Flasher(int led1,int led2,int led3,int led4,int led5,int led6,int led7);
   void PinSetup();
   void Sequence1();
};
#endif