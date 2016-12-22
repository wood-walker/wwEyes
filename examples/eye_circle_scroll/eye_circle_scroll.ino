// *****************************************************************************
//      - - - /    eye_circle_scroll.ino
//    -( W-W )        CC Attribution 4.0 International License
//      - - - \          www.wood-walker.org - Rainer Radow
//                          2016 Dec 22 - version 1.0
// *****************************************************************************
// Demonstrates the use of the Wood-Walker wwEyes.h and scrolling

#include <Wire.h>           // necessary for the I2C Communication
#include <SPI.h>            // used for SD-card communication in the WoodyEyes.h
#include <SD.h>             // used for SD-card communication in the WoodyEyes.h
#include <Adafruit_GFX.h>
#include <wwEyes.h>      // Header with instructions for using the OLED displays
#include <wwFrankPin.h>

//===============================================================================
wwEyes eye;       // set up variables using the wwEyes.h:

void setup() {
   prepareFrank();   // general WW-settings
   // eyes ----------------------------------------------
   Wire.begin();     // Necessary for eyes and SD-card
   eyeInitialize();  // must be done once at the start of each program
   scrollStop();   
   eyeDrawCircle();
}
// ============================================================================
void loop() {
  // put your main code here, to run repeatedly:
scrollRight();
delay(300);
 scrollLeft();
delay(300);
scrollStop();
delay(200);
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
void eyeDrawCircle() {
   eye.clearBuffer(); // clean the splash screen buffer
   eye.fillCircle(eye.width() / 2, eye.height() / 2, 8, WHITE);
   for (int16_t i = 27; i < 30; i++) {
      eye.drawCircle(eye.width() / 2, eye.height() / 2, i, WHITE);
      eye.display();
   }
   eye.select(eyeRight);
   eye.display();
   eye.select(eyeLeft);
   eye.display();
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
void scrollStop() {
   eye.select(eyeLeft);
   eye.stopscroll();
   eye.select(eyeRight);
   eye.stopscroll();
}
// ============================================================================
// ============================================================================
