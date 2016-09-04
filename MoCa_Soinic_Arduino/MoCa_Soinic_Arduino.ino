// Include definition of "SonarPair class"
#include "SonarPairDetectTriggerInterface.h"
#include "MoveDetectTrigger.h"
#include "Sonar.h"
// Using number of sonar pairs
#define PAIR_NUMBER 1

/* Sonar detector pair array
 *  Used to store "Sonar pairs"
 *  "Sonar pairs" is a array of two object of "Sonar class"
 *  Firts is for comming detection
 *  Last is for leaving detection
 */
 
SonarPairDetectTriggerInterface* triggerMethods[PAIR_NUMBER] = {
//    new MoveDetectTrigger(new Sonar(8, 9), new Sonar(11, 10))
    new InRangeDetectTrigger(new Sonar(8, 9), new Sonar(11, 10))
};

void setup() {
    Serial.begin(9600);
}

void loop() {
    for (byte i = 0; i < PAIR_NUMBER; i++) {
        triggerMethods[i] -> detect();
        if (triggerMethods[i] -> isTrigger()) {
            Serial.print(triggerMethods[i] -> getID());
            triggerMethods[i] -> toggle();
            Serial.println("    toggle");
            delay(1000);
        }
    }
}

