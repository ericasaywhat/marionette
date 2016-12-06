    #include <SimpleSDAudio.h>
    
    void setup()
    {
     // Open serial communications and wait for port to open:
      Serial.begin(9600);
          
      // Using F("...") to avoid wasting RAM  
      Serial.print(F("\nInitializing SD card..."));  
      
      // If your SD card CS-Pin is not at Pin 4, enable and adapt the following line:
      // SdPlay.setSDCSPin(10);
      
      if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER)) {
        Serial.println(F("initialization failed. Things to check:"));
        Serial.println(F("* is a card is inserted?"));
        Serial.println(F("* Is your wiring correct?"));
        Serial.println(F("* maybe you need to change the chipSelect pin to match your shield or module?"));
        Serial.print(F("Error code: "));
        Serial.println(SdPlay.getLastError());
        while(1);
      } else {
       Serial.println(F("Wiring is correct and a card is present.")); 
      }
    
      Serial.print(F("Looking for on.wav... "));
      if(!SdPlay.setFile("out.wav")) {
        Serial.println(F(" not found on card! Error code: "));
        Serial.println(SdPlay.getLastError());
        while(1);
      } else {
       Serial.println(F("found.")); 
      }    
    
      Serial.print(F("Playing... ")); 
      SdPlay.play();
      while(!SdPlay.isStopped()) {
        ;   // no worker needed anymore :-)
      }
      Serial.println(F("done."));
      SdPlay.deInit();
    }
    
    
    void loop(void) {
    
    }
