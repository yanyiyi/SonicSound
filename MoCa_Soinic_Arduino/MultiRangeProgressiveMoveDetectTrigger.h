#ifndef MULTI_RANGE_PROGRESSIVE_MOVE_DETECT_TRIGGER_H
#define MULTI_RANGE_PROGRESSIVE_MOVE_DETECT_TRIGGER_H

#include "SonarPairDetectTriggerInterface.h"
#include "Sonar.h"

class MultiRangeProgressiveMoveDetectTrigger : public SonarPairDetectTriggerInterface
{
    private:
        const int MIN_DISTANCE = 50;
        const int MAX_DISTANCE = 100;
        const int INTERVAL = 5;
        
        Sonar *frontSensor, *backSensor;
        bool isToggle;
        int intervalCount;

    public:
        TriggerMethodTwo(Sonar* frontSensor, Sonar* backSensor) {
            this->frontSensor = frontSensor;
            this->backSensor = backSensor;
            this->reset();
        }

        void detect() {
            if (isTrigger) return;
            
        }

        void toggle() {
            isToggle = !isToggle;
        }

        void reset() {
            isToggle = false;
        }

        byte getID() {
            return !isToggle ?
                    frontSonar -> getTriggerPin() :
                    backSonar -> getTriggerPin();
        }

        int getDistance() {
            return !isToggle ?
                    frontSonar -> getDistance() :
                    backSonar -> getDistance();
        }

        int getLeftBoundOfInterval(int interval) {
            int delta = (MAX_DISTANCE - MIN_DISTANCE) / INTERVAL;
            return MIN_DISTANCE + (delta * interval);
        }

        int getRightBoundOfInterval(int interval) {
            int delta = (MAX_DISTANCE - MIN_DISTANCE) / INTERVAL;
            return MIN_DISTANCE + (delta * (interval + 1));
        }

        void debug() {
            Serial.print(frontSonar -> getTriggerPin()); Serial.print("    ");
            Serial.println(frontSonar -> getDistance());
            Serial.print(backSonar -> getTriggerPin()); Serial.print("    ");
            Serial.println(backSonar -> getDistance());
        }
};

#endif
