import ddf.minim.*;
import processing.serial.*;

Serial port; 
Minim windSound01,windSound02,windSound03,windSound04,windSound05;


// Sensor
int iLight_Counts = 1 ; // how many sensor
int[] iLight_Vals = new int[iLight_Counts]; // storage sensor
String nowStat ;
int lf = 10 ;
//



void setup() {

 // Start arduino
  port = new Serial( this, Serial.list()[0], 9600 );

  noStroke();
}

void draw() {
  if ( port.available() > 0 ) {
    nowStat = port.readStringUntil( 10 ) ;
    if ( nowStat != null ) {
      print( "\n Receiving:" + nowStat ) ;
      int triggerPinNumber = Integer.parseInt(nowStat.trim());
      randomSound((triggerPinNumber / 4) + 1);
      //switch (triggerPinNumber) {
      //  case 2:
      //    randomSound(1);
      //    break;
      //  case 6:
      //    randomSound(2);
      //    break;
      //  case 10:
      //    randomSound(3);
      //    break;
      //  case 14:
      //    randomSound(4);
      //    break;
      //  case 18:
      //    randomSound(5);
      //    break;
      //}
    }
  } 
}//end of draw



void keyPressed() {
  if (key == 'a') {
    randomSound(0);
  }
   if (key == 'b' || key == 'B') {
randomSound(1);
     }
     
        if (key == 'v' || key == 'V') {
randomSound(2);
     }   if (key == 'C' || key == 'c') {
randomSound(3);
     }
     
        if (key == 'x' || key == 'X') {
randomSound(4);
     }   if (key == 'Z' || key == 'z') {
randomSound(5);
     }
  }// END of kPressed


void randomSound(int i){
  if (i == 0) {
    (new SoundFile(this, "frog01.wav")).play();
  }
  if(i == 1){
      windSound01 = new SoundFile(this, "w0"+int(random(1,6))+".wav");
      windSound01.play();
    }
    
      if(i == 2){
      windSound02 = new SoundFile(this, "forest0"+int(random(1,10))+".wav");
      windSound02.play();
    }
    
      if(i == 3){
      windSound03 = new SoundFile(this, "thu0"+int(random(1,7))+".wav");
      windSound03.play();
    }
    
      if(i == 4){
      windSound04 = new SoundFile(this, "fl0"+int(random(1,7))+".wav");
      windSound04.play();
    }
    
      if(i == 5){
      windSound05 = new SoundFile(this, "frog0"+int(random(1,5))+".wav");
      windSound05.play();
    }
}