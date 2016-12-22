// ****************************************************************************
//      - - - /    eye_scroll_text.ino
//    -( W-W )        www.wood-walker.org - Rainer Radow
//      - - - \          2016 Dec 22, version 1.0
// ****************************************************************************
#include <wwFrankPin.h>
#include <wwEyes.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <SD.h>
    
wwEyes eye;
// ============================================================================
void setup()   {
   prepareFrank();   // general WW-settings
   delay (500);
   
   eye.clearBuffer();
   eye.select(eyeLeft);
   eye.begin();
   eye.display();
       
   eye.select(eyeRight);
   eye.begin();
   eye.display();
       
   eye.setTextColor(WHITE);
   eye.setTextSize(1);
   eye.setCursor(0, 0);
   eye.println("Line 1");
   eye.println("Line 2");
   eye.println("Line 3");
   eye.println("Line 4");
   eye.println("Line 5");
   eye.println("Line 6");
   eye.println("Line 7");
   eye.println("Line 8");
   eye.display();
   delay(1000);
}
// =============================================================================
void loop() {
   // all this scroll instruction scroll multiple of 8 pixel in height
   eye.startscrollright(0, 0); //scroll line 1 to the right
   delay(900);
   eye.startscrollleft(2, 2);  //scroll line 3 to the left
   delay(700);
   eye.startscrollright(4, 4); //scroll line 5 to the right
   delay(1200);
   eye.startscrollleft(6, 7);  //scroll line 7 and 8 to the left
   delay(500);
}
// ============================================================================
// ============================================================================

