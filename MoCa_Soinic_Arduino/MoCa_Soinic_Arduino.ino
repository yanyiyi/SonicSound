// Include definition of "SonarPair class"
#include "SonarPairDetectTriggerInterface.h"
#include "MoveDetectTrigger.h"
#include "InRangeDetectTrigger.h"
#include "SingleSonarInRangeDetectTrigger.h"
#include "SingleSonarMoveDetectTrigger.h"
#include "Sonar.h"
// Using number of sonar pairs
#define PAIR_NUMBER 5

/* Sonar detector pair array
 *  Used to store "Sonar pairs"
 *  "Sonar pairs" is a array of two object of "Sonar class"
 *  Firts is for comming detection
 *  Last is for leaving detection
 */
 
SonarPairDetectTriggerInterface* triggerMethods[PAIR_NUMBER] = {
    new InRangeDetectTrigger(new Sonar(2, 3, 9000), new Sonar(4, 5, 15000)),
    new InRangeDetectTrigger(new Sonar(6, 7, 9000), new Sonar(8, 9, 9000)),
    new InRangeDetectTrigger(new Sonar(10, 11, 9000), new Sonar(12, 13, 9000)),
    new InRangeDetectTrigger(new Sonar(14, 15, 9000), new Sonar(16, 17, 9000)),
    new SingleSonarMoveDetectTrigger(new Sonar(18, 19, 9000))
};

void setup() {
    Serial.begin(9600);
}

void loop() {
    for (byte i = 0; i < PAIR_NUMBER; i++) {
        triggerMethods[i] -> detect();
//        triggerMethods[i] -> debug();
        if (triggerMethods[i] -> isTrigger()) {
            triggerMethods[i] -> toggle();
            delay(1000);
        }
    }
}

