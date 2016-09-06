// Include definition of "SonarPair class"
#include "SonarPairDetectTriggerInterface.h"
#include "MoveDetectTrigger.h"
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
    new MoveDetectTrigger(new Sonar(2, 3, 9000), new Sonar(4, 5, 20000)),
    new MoveDetectTrigger(new Sonar(6, 7, 9000), new Sonar(8, 9, 9000)),
    new MoveDetectTrigger(new Sonar(10, 11, 9000), new Sonar(12, 13, 9000)),
    new MoveDetectTrigger(new Sonar(14, 15, 9000), new Sonar(16, 17, 9000)),
    new MoveDetectTrigger(new Sonar(18, 19, 9000), new Sonar(20, 21, 9000)),
//    new InRangeDetectTrigger(new Sonar(8, 9), new Sonar(11, 10))
};

void setup() {
    Serial.begin(9600);
}

void loop() {
    for (byte i = 0; i < PAIR_NUMBER; i++) {
//        if (i == 0) continue;
//        if (i == 1) continue;
//        triggerMethods[i] -> detect();
        triggerMethods[i] -> debug();
        if (triggerMethods[i] -> isTrigger()) {
            Serial.print(triggerMethods[i] -> getID());
            triggerMethods[i] -> toggle();
            Serial.println("    toggle");
            delay(1000);
        }
//        delay(10);
    }
    delay(500);
//    Serial.println("");
}

