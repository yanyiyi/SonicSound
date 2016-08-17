// HCSR04Ultrasonic/examples/UltrasonicDemo/UltrasonicDemo.pde
#include <Ultrasonic.h>

#define TRIGGER_PIN1  3
#define ECHO_PIN1     2
#define TRIGGER_PIN2  5
#define ECHO_PIN2     4
#define TRIGGER_PIN3  7
#define ECHO_PIN3     6
#define TRIGGER_PIN4  9
#define ECHO_PIN4     8
#define TRIGGER_PIN5  11
#define ECHO_PIN5     10


Ultrasonic ultrasonic1(TRIGGER_PIN1, ECHO_PIN1);
Ultrasonic ultrasonic2(TRIGGER_PIN2, ECHO_PIN2);
Ultrasonic ultrasonic3(TRIGGER_PIN3, ECHO_PIN3);
Ultrasonic ultrasonic4(TRIGGER_PIN4, ECHO_PIN4);
Ultrasonic ultrasonic5(TRIGGER_PIN5, ECHO_PIN5);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float cmMsec1, inMsec1;
  float cmMsec2, inMsec2;
  float cmMsec3, inMsec3;
  float cmMsec4, inMsec4;
  float cmMsec5, inMsec5;
  long microsec1 = ultrasonic1.timing();
  long microsec2 = ultrasonic2.timing();
  long microsec3 = ultrasonic3.timing();
  long microsec4 = ultrasonic4.timing();
  long microsec5 = ultrasonic5.timing();


  cmMsec1 = ultrasonic1.convert(microsec1, Ultrasonic::CM); // 計算距離，單位: 公分
  cmMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::CM); // 計算距離，單位: 公分
  cmMsec3 = ultrasonic3.convert(microsec3, Ultrasonic::CM); // 計算距離，單位: 公分
  cmMsec4 = ultrasonic4.convert(microsec4, Ultrasonic::CM); // 計算距離，單位: 公分
  cmMsec5 = ultrasonic5.convert(microsec5, Ultrasonic::CM); // 計算距離，單位: 公分
  //inMsec1 = ultrasonic1.convert(microsec1, Ultrasonic::IN); // 計算距離，單位: 英吋
  //inMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::IN); // 計算距離，單位: 英吋
  //Serial.print("MS_1: ");
  //Serial.print(microsec1);
  //Serial.print(", CM_4: ");
  //Serial.print(cmMsec4);
  //Serial.print(", IN_1: ");
  //Serial.println(inMsec1);
  //Serial.println();

  
  //Serial.print("MS_2: ");
  //Serial.print(microsec2);
  //Serial.print(", CM_5: ");
  //Serial.print(cmMsec5);
  //Serial.print(", IN_2: ");
  //Serial.println(inMsec2);
  
  if(cmMsec1 < 25) 
  {
    Serial.write("1");
    delay(2000);
  }
  
  else if(cmMsec2 < 25) 
  {
    Serial.write("2");
    delay(2000);
  }
  else if(cmMsec3 < 25) 
  {
    Serial.write("3");
    delay(2000);
  }

  else if(cmMsec4 < 25) 
    {
      Serial.write("4");
      delay(2000); 
    }
  else if(cmMsec5 < 25) 
    {
      Serial.write("5");
      delay(2000);
    
    }
}


