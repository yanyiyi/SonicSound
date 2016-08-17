import processing.serial.*;

Serial port; 

int iLight_Counts = 2 ; // how many sensor
int[] iLight_Vals = new int[iLight_Counts]; // storage sensor

String nowStat ;
int lf = 10 ;

void setup() {
  port = new Serial( this, Serial.list()[5], 9600 );
  size(1024, 768);
  noStroke();
}

void draw() {
  if ( 0 < port.available() ) {
    nowStat = port.readStringUntil( lf ) ;
          if ( nowStat != null ) {
                        print( "\n Receiving:" + nowStat ) ;        
                        iLight_Vals = int( splitTokens( nowStat, "," ) ) ;
                        
                        
                        // IF distance near down to 50 goto next page
                        //if (iLight_Vals[0] > 1 && iLight_Vals[0] < 50){
                        //    flyingSigL++; 
                        //    print("LGO");
                        //      if (flyingSigL == 10){
                        //        flyingSigL = 0;
                        //        backPage();
                                
                        //    }
                        //}
                        //if (iLight_Vals[1] > 1 && iLight_Vals[1] < 50){
                        //    flyingSigR++; 
                        //    print("RGO");
                        //      if (flyingSigR == 10){
                        //        flyingSigR = 0;
                        //        forwardPage();
                        //    }
                        //}
          }
    } //end of Arduino

  
}//end of draw