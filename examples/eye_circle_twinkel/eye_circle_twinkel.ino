// *****************************************************************************
//      - - - /    eye_circle_twinkle.ino
//    -( W-W )        CC Attribution 4.0 International License
//      - - - \          www.wood-walker.org - Rainer Radow
//                          2016 Dec 22 - version 1.0
// *****************************************************************************
// Draw a circle and a dot as eyes.
// Draw a twinkel animation

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
   
   eye.clearBuffer(); // clean the splash screen buffer
   eye.fillCircle(mitteX, mitteY, 10, WHITE);
   for (int16_t i = 29; i < 34; i++) {
      eye.drawCircle(mitteX, mitteY, i, WHITE);
   }
   eyeOutBuffer();
   
   delay(1000);
   for (int16_t i = 28; i > 10; i--) {
      eye.drawCircle(mitteX, mitteY, i, WHITE);
      eyeOutBuffer();
   }
   delay(300);
   for (int16_t i = 14; i < 27; i += 4) {
      eye.drawCircle(mitteX, mitteY, i, BLACK);
      eye.drawCircle(mitteX, mitteY, i+1, BLACK);
      eye.drawCircle(mitteX, mitteY, i+2, BLACK);
      eye.drawCircle(mitteX, mitteY, i+3, BLACK);
      eyeOutBuffer();
   }
   eye.clearBuffer(); // clean the splash screen buffer
   eye.fillCircle(mitteX, mitteY, 10, WHITE);
   for (int16_t i = 29; i < 34; i++) {
      eye.drawCircle(mitteX, mitteY, i, WHITE);
   }
   eyeOutBuffer();
   
   delay(1000);
   // --------------------------------------------------------------
   eye.select(eyeRight);
   
   eye.drawCircle(mitteX, mitteY, 10, BLACK);
   eye.drawCircle(mitteX, mitteY,  9, BLACK);
   for (int16_t i = 28; i > 10; i -=4) {
      eye.drawCircle(mitteX, mitteY, i, WHITE);
      eye.drawCircle(mitteX, mitteY, i-1, WHITE);
      eye.drawCircle(mitteX, mitteY, i-2, WHITE);
      eye.drawCircle(mitteX, mitteY, i-3, WHITE);
      eye.display();
   }
   eye.drawCircle(mitteX, mitteY, 10, WHITE);
   eye.drawCircle(mitteX, mitteY,  9, WHITE);
   eye.display();
   
   delay(10);
   for (int16_t i = 14; i < 27; i += 4) {
      eye.drawCircle(mitteX, mitteY, i, BLACK);
      eye.drawCircle(mitteX, mitteY, i+1, BLACK);
      eye.drawCircle(mitteX, mitteY, i+2, BLACK);
      eye.drawCircle(mitteX, mitteY, i+3, BLACK);
      eye.display();
   }
}
// ============================================================================
void eyeOutBuffer() {
   eye.select(eyeRight);
   eye.display();
   eye.select(eyeLeft);
   eye.display();
}
// ============================================================================
// ============================================================================
