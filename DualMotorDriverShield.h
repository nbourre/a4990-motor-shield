#ifndef DualMotorDriverShield_h
#define DualMotorDriverShield_h

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined (__AVR_ATmega32U4__)
  #define DualMotorDriverShield_USE_20KHZ_PWM
#endif

#include <Arduino.h>

class DualMotorDriverShield 
{
  public:
    static void setPins (int M1PWM, int M1DIR, int M2PWM, int M2DIR);
    static void setM1Speed(int speed);
    static void setM2Speed(int speed);
    static void setSpeeds(int m1Speed, int m2Speed);
    static void flipM1(boolean flip);
    static void flipM2(boolean flip);
    static boolean getFault();
    
  private:
    static void initPinsAndMaybeTimer();
    const static unsigned char _M1DIR;
    const static unsigned char _M2DIR;
    const static unsigned char _M1PWM;
    const static unsigned char _M2PWM;
    const static unsigned char _FAULT;
    static boolean _flipM1;
    static boolean _flipM2;
    
    static inline void init()
    {
      static boolean initialized = false;
      if (!initialized)
      {
        initialized = true;
        initPinsAndMaybeTimer();
      }
    }
};
#endif