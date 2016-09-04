#ifndef IN_RANGE_DETECT_TRIGGER_H
#define IN_RANCE_DETECT_TRIGGER_H

#include "SonarPairDetectTriggerInterface.h"
#include "Sonar.h"

class InRangeDetectTrigger : public SonarPairDetectTriggerInterface
{
    private:
        const int MIN_DISTANCE = 50;
        const int MAX_DISTANCE = 100;
        const int INTERVAL = 5;
        
        Sonar *frontSonar, *backSonar;
        bool isComing;
        bool isProgressiveMode;
        int intervalCount;

        void init(Sonar* comingSensor, Sonar* leavingSensor, bool enableProgressiveMode) {
            this->comingSensor = comingSensor;
            this->leavingSensor = leavingSensor;
            isProgressiveMode = enableProgressiveMode;
        }

        void progressiveUpdate() {
            int distance = isComing ?
                    comingSensor -> update() -> getDistance() :
                    leavingSensor -> update() -> getDistance();
        }

        void nonprogressiveUpdate() {
            int distance = isComing ?
                    comingSensor -> update() -> getDistance() :
                    leavingSensor -> update() -> getDistance();
            if ((MIN_DISTANCE < distance) && (distance < MAX_DISTANCE)) {
                isTrigger = true;
            }
        }
    public:
        TriggerMethodTwo(Sonar* comingSensor, Sonar* leavingSensor) :
                TriggerMethod() {
            init(comingSensor, leavingSensor, true);
            reset();
        }

        TriggerMethodTwo(Sonar* comingSensor, Sonar* leavingSensor, bool enableProgressiveMode) :
                TriggerMethod() {
            init(comingSensor, leavingSensor, enableProgressiveMode);
            reset();
        }

        void update() {
            if (isTrigger) return;
            if (isProgressiveMode) progressvieUpdate();
            else nonprogressiveUpdate();
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
