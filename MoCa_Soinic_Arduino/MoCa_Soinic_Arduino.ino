#include "Sonar.h"
#define SONAR_PAIR_NUMBER 1
#define TOLERANCE 50
#define DELTA 5
#define MOVE_COUNT_LIMIT 3

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
            sonarPairs[sonarPairNo][0].ranging() :
            sonarPairs[sonarPairNo][1].ranging();
}

void updateStatus() {
    for (byte i = 0; i < SONAR_PAIR_NUMBER; i++) {
        newDistances[i] = getDistanceOf(i, isComing[i]);
        int delta = abs(newDistances[i] - pastDistances[i]);
        if (delta > TOLERANCE) {
//            Serial.println("reset");
            pastDistances[i] = newDistances[i];
            moveCounts[i] = 0;
            return;
        }
        if (isComing[i]) {
//            Serial.println("is coming");
            if ( (newDistances[i] < pastDistances[i]) && (delta > DELTA) ) {
                moveCounts[i]++;
                pastDistances[i] = newDistances[i];
            }
        } else {
//            Serial.println("is leaving");
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
//        Serial.println(moveCounts[i]);
    }
}

