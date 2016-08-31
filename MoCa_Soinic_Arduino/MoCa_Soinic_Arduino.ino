// Include definition of "Sonar class"
#include "Sonar.h"
// Using number of sonar pairs
#define SONAR_PAIR_NUMBER 1

#define TOLERANCE 50
#define DELTA 5
#define MOVE_COUNT_LIMIT 3

#define DEBUG

/* Sonar detector pair array
 *  Used to store "Sonar pairs"
 *  "Sonar pairs" is a array of two object of "Sonar class"
 *  Firts is for comming detection
 *  Last is for leaving detection
 */
Sonar sonarPairs[SONAR_PAIR_NUMBER][2] = {
    {Sonar(8, 9), Sonar(11, 10)}
};

int pastDistances[SONAR_PAIR_NUMBER];
int newDistances[SONAR_PAIR_NUMBER];
bool isComing[SONAR_PAIR_NUMBER] = {true};
byte moveCounts[SONAR_PAIR_NUMBER] = {0};

void setup() {
    Serial.begin(9600);
    for (byte i = 0; i < SONAR_PAIR_NUMBER; i++) {
        pastDistances[i] = getDistanceOf(i, isComing[i]);
    }
}

void loop() {
    updateStatus();
    delay(100);
}

int getDistanceOf(byte sonarPairNo, bool isComing) {
    return isComing ?
            sonarPairs[sonarPairNo][0].update() -> getDistance() :
            sonarPairs[sonarPairNo][1].update() -> getDistance();
}

void updateStatus() {
    for (byte i = 0; i < SONAR_PAIR_NUMBER; i++) {
        newDistances[i] = getDistanceOf(i, isComing[i]);
        int delta = abs(newDistances[i] - pastDistances[i]);
        if (delta > TOLERANCE) {
#ifdef DEBUG
            Serial.println("reset");
#endif
            pastDistances[i] = newDistances[i];
            moveCounts[i] = 0;
            return;
        }
        if (isComing[i]) {
#ifdef DEBUG
            Serial.println("is coming");
#endif
            if ( (newDistances[i] < pastDistances[i]) && (delta > DELTA) ) {
                moveCounts[i]++;
                pastDistances[i] = newDistances[i];
            }
        } else {
#ifdef DEBUG
            Serial.println("is leaving");
#endif
            if ( (newDistances[i] > pastDistances[i]) && (delta > DELTA) ) {
                moveCounts[i]++;
                pastDistances[i] = newDistances[i];
            }
        }
        if (moveCounts[i] > MOVE_COUNT_LIMIT) {
            Serial.println(10 + i*2 + 2 - isComing[i]);
            isComing[i] = !isComing[i];
            moveCounts[i] = 0;
            delay(1000);
        }
#ifdef DEBUG
        Serial.println(moveCounts[i]);
#endif
    }
}

