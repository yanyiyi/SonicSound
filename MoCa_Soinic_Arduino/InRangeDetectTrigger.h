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
            this->reset();
        }

        void detect() {
            if (isTrigger) return;
            int distance = getDistance();
            if ((LEFT_BOUND < distance) && (distance < RIGHT_BOUND)) {
                isTrigger = true;
            }
        }

        void toggle() {
            isToggle = !isToggle;
        }

        void reset() {
            isToogle = false;
        }

        byte getID() {
            
        }

        int getDistance() {
            return (!isToggle) ?
                    frontSonar -> getDistance() :
                    backSonar -> getDistance();
        }
        
        void debug() {
            Serial.print(frontSonar -> getTriggerPin()); Serial.print("    ");
            Serial.println(frontSonar -> getDistance());
            Serial.print(backSonar -> getTriggerPin()); Serial.print("    ");
            Serial.println(backSonar -> getDistance());
        }
};

#endif
