#ifndef IN_RANGE_DETECT_TRIGGER_H
#define IN_RANCE_DETECT_TRIGGER_H

#include "SonarPairDetectTriggerInterface.h"
#include "Sonar.h"

class InRangeDetectTrigger : public SonarPairDetectTriggerInterface
{
    private:
        const int LEFT_BOUND = 50;
        const int RIGHT_BOUND = 100;
        
        Sonar *frontSonar, *backSonar;
        bool isTrigger;
        bool isToogle;
        
    public:
        InRangeDetectTrigger(Sonar* frontSonar, Sonar* backSonar) {
            this->frontSonar = frontSonar;
            this->backSonar = backSonar;
            reset();
        }

        void update() {
            if (isTrigger) return;
        }

        void toggle() {
            
        }

        void reset() {
            isComing = true;
        }

        byte getID() {
            
        }
};

#endif
