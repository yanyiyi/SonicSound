#include "Sonar.h"
#define SONAR_PAIR_NUMBER 1
#define TOLERANCE 100
#define DELTA 10
#define MOVE_COUNT_LIMIT 5

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
//    delay(2);
//    for (byte i = 0; i < SONAR_PAIR_NUMBER; i++) {
//        newDistances[i] = getDistanceOf(i, isComing[i]);
//        Serial.print(newDistances[i]);
//        Serial.print(",");
//    } Serial.println();
//    for (byte i = 0; i < SONAR_PAIR_NUMBER; i++) {
//        for (byte j = 0; j < 2; j++) {
//            Serial.print(sonarPairs[i][j].ranging());
//            Serial.print(",");
//        } Serial.println();
//    }
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
        Serial.print("    ");
        Serial.print(delta);
        Serial.print("   ");
        Serial.print(isComing[i] ? "Coming" : "Leaving");
//        if (delta > DELTA) {
//            if (isComing[i] && (newDistances[i] < pastDistances[i])) {
////                Serial.println("is coming");
//                moveCounts[i]++;
//            }
//            else if (!isComing[i] && (newDistances[i] > pastDistances[i])) {
////                Serial.println("is leaving");
//                moveCounts[i]++;
//            }
////            else
////                moveCounts[i] = 0;
////            pastDistances[i] = newDistances[i];
//        }
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
        Serial.println(moveCounts[i]);
    }
}

