import ddf.minim.Minim;
import processing.serial.Serial;

Serial serialPort;

void setup() {
  serialPort = new Serial( this, Serial.list()[1], 9600 );
  noStroke();
}

void draw() {
  if ( serialPort.available() > 0 ) {
    String input = serialPort.readStringUntil(10);
    if (input == null) return;
    print("Received: " + input);
    int triggerPin = Integer.parseInt(input.trim());
    playRandomSound(triggerPin);
  }
} //end of draw

void playRandomSound(int i) {
  String fileName = "";
  switch (i) {
  case 2:
    fileName = "w0" + (int)(random(1, 6)); break;
  case 6:
    fileName = "forest0" + (int)(random(1, 10)); break;
  case 10:
    fileName = "thu0" + (int)(random(1, 7)); break;
  case 14:
    fileName = "fl0" + (int)(random(1, 7)); break;
  case 18:
    fileName = "frog0" + (int)(random(1, 5)); break;
  default: return;
  }
  
  println("play " + fileName);
  (new Minim(this)).loadFile(fileName + ".mp3").play();
}

// for debug
void keyPressed() {
  if (key == 'b' || key == 'B') playRandomSound(2);
  if (key == 'v' || key == 'V') playRandomSound(6);
  if (key == 'c' || key == 'C') playRandomSound(10);
  if (key == 'x' || key == 'X') playRandomSound(14);
  if (key == 'z' || key == 'Z') playRandomSound(18);
} // END of keyPressed