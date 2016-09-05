#ifndef TRIGGER_METHOD_ONE_H
#define TRIGGER_METHOD_ONE_H

#include "TriggerMethod.h"
#include "Sonar.h"

class TriggerMethodOne : public TriggerMethod
{
    private:
        const int TOLERANCE = 50;
        const byte OUTRANGE_LIMIT = 20;
        const int DELTA = 3;
        const byte MOVE_COUNT_LIMIT = 10;

        Sonar *comingSensor, *leavingSensor;
        bool isComing;
        int pastDistance;
        byte outRangeCount;
        byte moveCount;

        void initDistance(Sonar* sensor) {
            pastDistance = sensor -> update() -> getDistance();
        }
        
    public:
        TriggerMethodOne(Sonar* comingSensor, Sonar* leavingSensor) :
                TriggerMethod() {
            this->comingSensor = comingSensor;
            this->leavingSensor = leavingSensor;
            reset();
        }

        void update() {
            if (isTrigger) return;
            
            int newDistance = isComing ?
                    comingSensor -> update() -> getDistance() :
                    leavingSensor -> update() -> getDistance();
            int delta = abs(newDistance - pastDistance);
            
            if (delta > TOLERANCE) {
                if (outRangeCount++ < OUTRANGE_LIMIT) return;
                Serial.println("reset");
                pastDistance = newDistance;
                moveCount = 0;
                return;
            } outRangeCount = 0;
            
            if (isComing) {
                Serial.print("is coming ");
                if ( (newDistance < pastDistance) && (delta > DELTA) ) {
                    moveCount++;
                    pastDistance = newDistance;
                }
            } else {
                Serial.print("is leaving ");
                if ( (newDistance > pastDistance) && (delta > DELTA) ) {
                    moveCount++;
                    pastDistance = newDistance;
                }
            }
            
            if (moveCount > MOVE_COUNT_LIMIT) {
                isTrigger = true;
            }
            
            Serial.println(moveCount);
        }

        void toggle() {
            isTrigger = false;
            isComing = !isComing;
            initDistance(isComing ? comingSensor : leavingSensor);
            outRangeCount = 0;
            moveCount = 0;
        }

        void reset() {
            isTrigger = false;
            isComing = true;
            initDistance(comingSensor);
            moveCount = 0;
        }

        byte getID() {
            return isComing ? comingSensor -> getTriggerPin() :
                            leavingSensor -> getTriggerPin();
        }
};

#endif
