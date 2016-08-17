import processing.serial.*;
Serial serial;  
int sensorValue;

import ddf.minim.*;
Minim minim;
AudioPlayer player;
//AudioPlayer player4;
//AudioPlayer player5;

void setup()
{
  serial = new Serial(this, "/dev/cu.usbmodem1421", 9600);
  minim = new Minim(this);
}

void draw()
{

  
  if ( serial.available() > 0)
  {
    sensorValue = serial.read();
    println(sensorValue);
    if(sensorValue == 49 )  //49 is equal to arduino's serial.write=1
    {
      player = minim.loadFile("cicada.mp3", 2048);
      player.play();
    }
    if(sensorValue == 50 ) //50 is equal to arduino's serial.write=2
    {
      player = minim.loadFile("drop.mp3", 2048);
      player.play();
    }
    if(sensorValue == 51 ) //51 is equal to arduino's serial.write=3
    {
      player = minim.loadFile("footsteps.mp3", 2048);
      player.play();
    }
    if(sensorValue == 52 ) //52 is equal to arduino's serial.write=4
    {
      player = minim.loadFile("drop.mp3", 2048);
      player.play();
    }
    if(sensorValue == 53) //53 is equal to arduino's serial.write=5
    {
        player = minim.loadFile("wind.mp3", 2048);
        player.play();
    }  
  }
}
void stop()
{
  player.close();
  minim.stop();
  super.stop();
}
