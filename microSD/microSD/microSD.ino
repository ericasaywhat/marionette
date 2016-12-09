#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 10
#include <TMRpcm.h>           //  also need to include this library...

TMRpcm sound;   // create an object for use in this sketch
void setup(){

  sound.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
  sound.setVolume(5);
  sound.quality(0);
  
  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  sound.play("NoCeello.wav");
  Serial.println(sound.isPlaying());  
}

void loop(){ 
//  soundTrack = SD.open("POESound.wav");
//  Serial.println(soundTrack.read());
    
    
}
