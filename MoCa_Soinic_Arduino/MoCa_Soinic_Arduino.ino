// Include definition of "SonarPair class"
#include "SonarPair.h"
// Using number of sonar pairs
#define PAIR_NUMBER 1

/* Sonar detector pair array
 *  Used to store "Sonar pairs"
 *  "Sonar pairs" is a array of two object of "Sonar class"
 *  Firts is for comming detection
 *  Last is for leaving detection
 */
SonarPair sonarPairs[PAIR_NUMBER] = {
    SonarPair(8, 9, 11, 10)
};

void setup() {
    Serial.begin(9600);
}

void loop() {
    updateSensors();
    delay(200);
}

void updateSensors() {
    for (byte i = 0; i < PAIR_NUMBER; i++) {
        sonarPairs[i].update();
    }
}

