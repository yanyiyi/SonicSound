import processing.sound.*;
import processing.serial.*;

Serial port; 
SoundFile windSound01,windSound02,windSound03,windSound04,windSound05;


// Sensor
int iLight_Counts = 2 ; // how many sensor
int[] iLight_Vals = new int[iLight_Counts]; // storage sensor
String nowStat ;
int lf = 10 ;
//



void setup() {

 // Start arduino
  //port = new Serial( this, Serial.list()[5], 9600 );
  size(1024, 768);
  noStroke();
}

void draw() {
    //if ( 0 < port.available() ) {
    //      nowStat = port.readStringUntil( lf ) ;
    //            if ( nowStat != null ) {
    //                    print( "\n Receiving:" + nowStat ) ;        
    //                    iLight_Vals = int( splitTokens( nowStat, "," ) ) ;
                        
                        
    //                    // IF distance near down to 50 goto next page
    //                    //if (iLight_Vals[0] > 1 && iLight_Vals[0] < 50){
    //                    //    flyingSigL++; 
    //                    //    print("LGO");
    //                    //      if (flyingSigL == 10){
    //                    //        flyingSigL = 0;
    //                    //        backPage();
                                
    //                    //    }
    //                    //}
    //                    //if (iLight_Vals[1] > 1 && iLight_Vals[1] < 50){
    //                    //    flyingSigR++; 
    //                    //    print("RGO");
    //                    //      if (flyingSigR == 10){
    //                    //        flyingSigR = 0;
    //                    //        forwardPage();
    //                    //    }
    //                    //}
                        
    //          }
    //} //end of Arduino



 
}//end of draw



void keyPressed() {
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