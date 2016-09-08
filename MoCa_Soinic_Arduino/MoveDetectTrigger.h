#ifndef MOVE_DETECT_TRIGGER_H
#define MOVE_DETECT_TRIGGER_H

#include "SonarPairDetectTriggerInterface.h"
#include "Sonar.h"

class MoveDetectTrigger : public SonarPairDetectTriggerInterface
{
    private:
        const int TOLERANCE = 50;
        const byte OUTRANGE_LIMIT = 20;
        const int DELTA = 3;
        const byte MOVE_COUNT_LIMIT = 5;

        Sonar *frontSonar, *backSonar;
        bool _isTrigger;
        bool isToggle;
        int pastDistance;
        byte outRangeCount;
        byte moveCount;

        void initDistance(Sonar* sonar) {
            pastDistance = sonar -> getDistance();
        }
        
    public:
        MoveDetectTrigger(Sonar* frontSonar, Sonar* backSonar) {
            this->frontSonar = frontSonar;
            this->backSonar = backSonar;
            reset();
        }

        void detect() {
            if (_isTrigger) return;
            
            int newDistance = !isToggle ?
                    frontSonar -> getDistance() :
                    backSonar -> getDistance();
            int delta = newDistance - pastDistance;
            
            if (abs(delta) > TOLERANCE) {
                if (outRangeCount++ < OUTRANGE_LIMIT) return;
                pastDistance = newDistance;
                moveCount = 0;
                return;
            } outRangeCount = 0;

            if (!isToggle) {
                if ( (newDistance < pastDistance) && (abs(delta) > DELTA) ) {
                    moveCount++;
                    pastDistance = newDistance;
                }
            } else {
                if ( (newDistance > pastDistance) && (abs(delta) > DELTA) ) {
                    moveCount++;
                    pastDistance = newDistance;
                }
            }
            
            if (moveCount > MOVE_COUNT_LIMIT) {
                _isTrigger = true;
                if (!isToggle) {
                    Serial.println(getID());
                }
            }
        }

        bool isTrigger() {
            return _isTrigger;
        }

        void toggle() {
            _isTrigger = false;
            isToggle = !isToggle;
            initDistance(isToggle ? frontSonar : backSonar);
            outRangeCount = 0;
            moveCount = 0;
        }

        void reset() {
            _isTrigger = false;
            isToggle = false;
            initDistance(frontSonar);
            outRangeCount = 0;
            moveCount = 0;
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

        void debug() {
            Serial.print(frontSonar -> getTriggerPin()); Serial.print("    ");
            Serial.println(frontSonar -> getDistance());
            Serial.print(backSonar -> getTriggerPin()); Serial.print("    ");
            Serial.println(backSonar -> getDistance());
        }
};

#endif
