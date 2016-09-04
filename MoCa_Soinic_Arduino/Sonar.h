#ifndef SONAR_H
#define SONAR_H

class Sonar
{
    private:
        byte triggerPin, echoPin;   // Arduino pins for HC-SR04
        unsigned long duration;     // Duration of sound wave
        unsigned long timeOut;      // Time out for no sound wave return
        
        void init(byte triggerPin, byte echoPin, unsigned long timeOut) {
            pinMode(triggerPin, OUTPUT);
            pinMode(echoPin, INPUT);
            this->triggerPin = triggerPin;
            this->echoPin = echoPin;
            this->timeOut = timeOut;
        }
        
    public:
        Sonar(byte triggerPin, byte echoPin) {
            this->init(triggerPin, echoPin, 20000);
            // 3000 µs = 50cm // 30000 µs = 5 m
            // HC-SR40 range: 4cm ~ 400cm
        }
        Sonar(byte triggerPin, byte echoPin, unsigned long timeOut) {
            this->init(triggerPin, echoPin, timeOut);
        }
        
        Sonar* detect() {
            digitalWrite(triggerPin, LOW);
            delayMicroseconds(5);
            digitalWrite(triggerPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(triggerPin, LOW);
            duration = pulseIn(echoPin, HIGH, timeOut);
            return this;
        }
        
        unsigned long getDuration() {
            return duration;
        }
        
        int getDistance() {
            return (int)(duration / 28.5 / 2);
        }
        
        byte getTriggerPin() {
            return triggerPin;
        }
        
        byte getEchoPin() {
            return echoPin;
        }
};

#endif
