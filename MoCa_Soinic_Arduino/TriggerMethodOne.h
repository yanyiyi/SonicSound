#include "TriggerMethod.h"

class TriggerMethodOne : private TriggerMethod
{
    private:
        const long TOLERANCE = 50;
        const long DELTA = 5;
        const byte MOVE_COUNT_LIMIT = 3;

        int pastDistance;
        byte moveCount;

    public:
        TriggerMethodOne(int initData) : TriggerMethod() {
            pastDistance = initData;
            moveCount = 0;
        }

        void update(int data) {
            int delta = abs(data - pastDistance);
            if (delta > TOLERANCE) {
                Serial.println("reset");
                pastDistance = data;
                moveCount = 0;
                return;
            }
            if (isComing) {
                Serial.println("is coming");
                if ( (data < pastDistance) && (delta > DELTA) ) {
                    moveCount++;
                    pastDistance = data;
                }
            } else {
                Serial.println("is leaving");
                if ( (data > pastDistance) && (delta > DELTA) ) {
                    moveCount++;
                    pastDistance = data;
                }
            }
            if (moveCount > MOVE_COUNT_LIMIT) {
                if (isComing) {
                    Serial.println(comingSonar.getID());
                } else {
                    Serial.println(leavingSonar.getID());
                }
                isComing = !isComing;
                moveCount = 0;
                delay(1000);
            }
            Serial.println(moveCount);
        }
        bool isTrigger()
}

