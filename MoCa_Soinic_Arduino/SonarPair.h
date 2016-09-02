#include "Sonar.h"

class SonarPair {
    private:
        const long TOLERANCE = 50;
        const long DELTA = 5;
        const byte MOVE_COUNT_LIMIT = 3;
        
        Sonar comingSonar, leavingSonar;
        Sonar* sonar;
        int pastDistance;
        int newDistance;
        bool isComing;
        byte moveCount;
    public:
        SonarPair(byte comingTriggerPin, byte comingEchoPin,
                byte leavingTriggerPin, byte leavingEchoPin) :
                        comingSonar(comingTriggerPin, comingEchoPin),
                        leavingSonar(leavingTriggerPin, leavingEchoPin) {
            isComing = true;
            moveCount = 0;
            sonar = &comingSonar;
            pastDistance = getDistance();
        }
        void update() {
            newDistance = getDistance();
            int delta = abs(newDistance - pastDistance);
            if (delta > TOLERANCE) {
                Serial.println("reset");
                pastDistance = newDistance;
                moveCount = 0;
                return;
            }
            if (isComing) {
                Serial.println("is coming");
                if ( (newDistance < pastDistance) && (delta > DELTA) ) {
                    moveCount++;
                    pastDistance = newDistance;
                }
            } else {
                Serial.println("is leaving");
                if ( (newDistance > pastDistance) && (delta > DELTA) ) {
                    moveCount++;
                    pastDistance = newDistance;
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
        int getDistance() {
            return isComing ?
                comingSonar.update() -> getDistance() :
                leavingSonar.update() -> getDistance();
        }
};
