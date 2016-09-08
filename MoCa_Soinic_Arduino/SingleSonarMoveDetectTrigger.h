#ifndef SINGLE_SONAR_MOVE_DETECT_TRIGGER
#define SINGLE_SONAR_MOVE_DETECT_TRIGGER

#include "SonarPairDetectTriggerInterface.h"
#include "Sonar.h"

class SingleSonarMoveDetectTrigger : public SonarPairDetectTriggerInterface
{
    private:
        const int TOLERANCE = 50;
        const byte OUTRANGE_LIMIT = 20;
        const int DELTA = 3;
        const byte MOVE_COUNT_LIMIT = 5;

        Sonar* sonar;
        bool _isTrigger;
        int pastDistance;
        byte outRangeCount;
        byte moveCount;

        void initDistance() {
            pastDistance = getDistance();
        }
        
    public:
        SingleSonarMoveDetectTrigger(Sonar* sonar) {
            this->sonar = sonar;
            reset();
        }
        
        void detect() {
            if (_isTrigger) return;
            
            int newDistance = getDistance();
            int delta = newDistance - pastDistance;
            
            if (abs(delta) > TOLERANCE) {
                if (outRangeCount++ < OUTRANGE_LIMIT) return;
                pastDistance = newDistance;
                moveCount = 0;
                return;
            } outRangeCount = 0;

            if ( (newDistance < pastDistance) && (abs(delta) > DELTA) ) {
                moveCount++;
                pastDistance = newDistance;
            }
            
            if (moveCount > MOVE_COUNT_LIMIT) {
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
            initDistance();
            outRangeCount = 0;
            moveCount = 0;
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
