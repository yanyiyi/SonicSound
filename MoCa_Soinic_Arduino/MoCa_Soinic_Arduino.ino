#include <Ultrasonic.h>
#define TRIGGER_PIN  8
#define ECHO_PIN     9
#define TRIGGER_PIN2  12
#define ECHO_PIN2     11
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
Ultrasonic ultrasonic2(TRIGGER_PIN2, ECHO_PIN2);

const int trig = 8;
const int ech = 9;
const int trig2 = 12;
const int ech2 = 11;
const int inter_time = 2000;
int time = 0;



void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(ech, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(ech2, INPUT);
}

void loop() {
  
  float cmMsec, inMsec;
  float cmMsec2, inMsec2;
  int cmN;
  int cmN2;
  long microsec = ultrasonic.timing();
  long microsec2 = ultrasonic2.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
  cmN = int(cmMsec);
  cmMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::CM); // 計算距離，單位: 公分
  cmN2 = int(cmMsec2); 
   Serial.print(cmN);
     Serial.print(",");
      Serial.print(cmN2);
     Serial.print(",");
     Serial.println("0");
}

