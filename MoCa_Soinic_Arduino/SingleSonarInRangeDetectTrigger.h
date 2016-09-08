#ifndef SINGLE_SONAR_IN_RANGE_DETECT_TRIGGER
#define SINGLE_SONAR_IN_RANGE_DETECT_TRIGGER

#include "SonarPairDetectTriggerInterface.h"
#include "Sonar.h"

class SingleSonarInRangeDetectTrigger : public SonarPairDetectTriggerInterface
{
    private:
        const int LEFT_BOUND = 50;
        const int RIGHT_BOUND = 70;
        
        Sonar* sonar;
        bool _isTrigger;
        bool isToggle;
    public:
        SingleSonarInRangeDetectTrigger(Sonar* sonar) {
            this->sonar = sonar;
            reset();
        }
        
        void detect() {
            if (_isTrigger) return;
            int distance = getDistance();
            if ((LEFT_BOUND < distance) && (distance < RIGHT_BOUND)) {
                _isTrigger = true;
                Serial.println(getID());
            }
        }
        
        bool isTrigger() {
            return _isTrigger;
        }
        
        void toggle() {
            reset();
        }
        
        void reset() {
            _isTrigger = false;
            isToggle = false;
        }
        
        byte getID() {
            return sonar -> getTriggerPin();
        }
        
        int getDistance() {
            return sonar -> getDistance();
        }
        
        void debug() {
            
        }
};

#endif
