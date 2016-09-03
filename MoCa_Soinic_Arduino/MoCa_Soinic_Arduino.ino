// Include definition of "SonarPair class"
#include "Sonar.h"
#include "TriggerMethod.h"
#include "TriggerMethodOne.h"
// Using number of sonar pairs
#define PAIR_NUMBER 1

/* Sonar detector pair array
 *  Used to store "Sonar pairs"
 *  "Sonar pairs" is a array of two object of "Sonar class"
 *  Firts is for comming detection
 *  Last is for leaving detection
 */
 
TriggerMethod* triggerMethods[PAIR_NUMBER] = {
    new TriggerMethodOne(new Sonar(8, 9), new Sonar(11, 10))
};

void setup() {
    Serial.begin(9600);
}

void loop() {
    updateSensors();
    //delay(1);
}

void updateSensors() {
    for (byte i = 0; i < PAIR_NUMBER; i++) {
        triggerMethods[i] -> update();
        if (triggerMethods[i] -> isTrigger) {
            Serial.print(triggerMethods[i] -> getID());
            triggerMethods[i] -> toggle();
            Serial.println("    reset");
            delay(1000);
        }
    }
}

