// *****************************************************************************
//      - - - /    eye_roundrect_invert.ino
//    -( W-W )        CC Attribution 4.0 International License
//      - - - \          www.wood-walker.org - Rainer Radow
//                          2016 Dec 22 - version 1.0
// *****************************************************************************
// Draw a rounded rectangle and a dot as eyes.
// animate and invert display

#include <Wire.h>           // necessary for the I2C Communication
#include <SPI.h>            // used for SD-card communication in the WoodyEyes.h
#include <SD.h>             // used for SD-card communication in the WoodyEyes.h
#include <Adafruit_GFX.h>
#include <wwEyes.h>      // Header with instructions for using the OLED displays
#include <wwFrankPin.h>

wwEyes eye;       // set up variables using the WoodyEyes.h:
// ============================================================================
void setup() {
   prepareFrank();   // general WW-settings
   // eyes ----------------------------------------------
   Wire.begin();     // Necessary for eyes and SD-card
   eyeInitialize();  // must be done once at the start of each program
}
// ============================================================================
void loop() {
   eyeDrawCircle();
}
// ============================================================================
void eyeInitialize() {
   delay(500);         // after a power wait a while to let the eyes start
   eye.select(eyeRight);
   eye.begin();
   eye.display();      // show an empty screen
   eye.select(eyeLeft);
   eye.begin();
   eye.display();      // show an empty screen
}
// ============================================================================
void eyeDrawCircle() {
   const int mitteX = 64;
   const int mitteY = 32;
   const int pupil = 8;
   const int apple = 22; 
   
   eye.clearBuffer(); // clean the splash screen buffer
   eye.fillCircle(mitteX, mitteY, apple, WHITE);
   eye.fillCircle(mitteX, mitteY, pupil, BLACK);
   for (int16_t i = 0; i < 3; i++) {
      eye.drawRoundRect(25+i, 0+i, 78-2*i, 64-2*i, 38-i, WHITE);
   }
   eyeOutBuffer(); 
   delay(1000);
   eye.fillCircle(mitteX, mitteY, apple, BLACK);  //Erase the eye ball
   eye.fillCircle(mitteX+8, mitteY+0, apple, WHITE);   
   eye.fillCircle(mitteX+12, mitteY+0, pupil, BLACK);  
   eyeOutBuffer();    
    delay(1000);  
   eye.fillCircle(mitteX+8, mitteY+0, apple, BLACK);  //Erase the eye ball
   eye.fillCircle(mitteX-8, mitteY-0, apple, WHITE);
   eye.fillCircle(mitteX-12, mitteY-0, pupil, BLACK);
   eyeOutBuffer();  
   delay(1000); 
    
   eyesInvert();
   delay(100); 
   eyesNormal(); 
   delay(200); 
   eyesInvert();
   delay(100);
   eyesNormal();
   delay(200);
   eyesInvert();
   delay(100);
   eyesNormal();
   delay(200);   
}
// ============================================================================
void eyeOutBuffer() {
   eye.select(eyeRight);
   eye.display();
   eye.select(eyeLeft);
   eye.display();
}
// ============================================================================
void eyesInvert() {
   eye.select(eyeRight);
   eye.command(EYE_INVERTDISPLAY);   
   eye.display();
   eye.select(eyeLeft);
   eye.command(EYE_INVERTDISPLAY);   
   eye.display();
}
// ============================================================================
void eyesNormal() {
   eye.select(eyeRight);
   eye.command(EYE_NORMALDISPLAY);
   eye.display();
   eye.select(eyeLeft);
   eye.command(EYE_NORMALDISPLAY);
   eye.display();
}
// ============================================================================
// ============================================================================
