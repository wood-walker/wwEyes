// *****************************************************************************
//      - - - /    eye_scroll_all.ino
//    -( W-W )        CC Attribution 4.0 International License
//      - - - \          www.wood-walker.org - Rainer Radow
//                          2016 Dec 22 - version 1.0
// *****************************************************************************
// Scroll the display.
    
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
   eyeInitialize();
}
// ============================================================================    
void loop() {
   delay(2500);
   scrollRight(); 
   delay(2500);
   scrollLeft();
   delay(2500);
   scrollDiagRight();
   delay(2500);
   scrollStop();
   delay(1000);  
   scrollDiagLeft();         
}
// ============================================================================
void eyeInitialize() {
   delay(500);         // after a power on you have to wait a while to let the eyes start
   eye.select(eyeRight);
   eye.begin();
   eye.display();      // show an empty screen
   eye.select(eyeLeft);
   eye.begin();
   eye.display();      // show an empty screen
}
// ============================================================================
void scrollRight() {
   eye.select(eyeRight);
   eye.startscrollright(0x00, 0x07);
   eye.select(eyeLeft);
   eye.startscrollright(0x00, 0x07);
}
// ============================================================================
void scrollLeft() {
   eye.select(eyeRight);
   eye.startscrollleft(0x00, 0x07);
   eye.select(eyeLeft);
   eye.startscrollleft(0x00, 0x07);
}
// ============================================================================
void scrollDiagRight() {
   eye.select(eyeRight);
   eye.startscrolldiagright(0x00, 0x07);
   eye.select(eyeLeft);
   eye.startscrolldiagright(0x00, 0x07);
}
// ============================================================================
void scrollDiagLeft() {
   eye.select(eyeRight);
   eye.startscrolldiagleft(0x00, 0x07);
   eye.select(eyeLeft);
   eye.startscrolldiagleft(0x00, 0x07);
}
// ============================================================================
void scrollStop() {
   eye.select(eyeLeft);
   eye.stopscroll();
   eye.select(eyeRight);
   eye.stopscroll();
}
// ============================================================================
// ============================================================================

