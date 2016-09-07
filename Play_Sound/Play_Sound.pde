import ddf.minim.*;
import processing.serial.*;

Serial port; 
Minim windSound01,windSound02,windSound03,windSound04,windSound05;
AudioPlayer player1,player2,player3,player4,player5;

// Sensor
int iLight_Counts = 1 ; // how many sensor
int[] iLight_Vals = new int[iLight_Counts]; // storage sensor
String nowStat ;
int lf = 10 ;
//



void setup() {

 // Start arduino
  port = new Serial( this, Serial.list()[0], 9600 );
  windSound01 = new Minim(this);
  windSound02 = new Minim(this);
  windSound03 = new Minim(this);
  windSound04 = new Minim(this);
  windSound05 = new Minim(this);
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

  if(i == 1){
      player1 = windSound01.loadFile("w0"+int(random(1,6))+".mp3");
      player1.play();
    }
    
      if(i == 2){
      player2 = windSound02.loadFile("forest0"+int(random(1,10))+".mp3");
      player2.play();
    }
    
      if(i == 3){
      player3 = windSound03.loadFile("thu0"+int(random(1,7))+".mp3");
      player3.play();
    }
    
      if(i == 4){
      player4 = windSound04.loadFile("fl0"+int(random(1,7))+".mp3");
      player4.play();
    }
    
      if(i == 5){
      player5 = windSound05.loadFile("frog0"+int(random(1,5))+".mp3");
      player5.play();
    }
}