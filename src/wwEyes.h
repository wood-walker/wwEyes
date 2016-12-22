/*********************************************************************
This is a library for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include "Arduino.h"
#define WIRE_WRITE Wire.write

#ifdef __SAM3X8E__
 typedef volatile RwReg PortReg;
 typedef uint32_t PortMask;
#else
  typedef volatile uint8_t PortReg;
  typedef uint8_t PortMask;
#endif

#include <Adafruit_GFX.h>

#define BLACK 0
#define WHITE 1
#define INVERSE 2

/*=========================================================================*/
#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 64

#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define EYE_NORMALDISPLAY 0xA6
#define EYE_INVERTDISPLAY 0xA7
#define EYE_OFF 0xAE
#define EYE_ON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

// Scrolling #defines
#define EYE_ACTIVATE_SCROLL 0x2F
#define EYE_DEACTIVATE_SCROLL 0x2E
#define EYE_SET_VERTICAL_SCROLL_AREA 0xA3
#define EYE_RIGHT_HORIZONTAL_SCROLL 0x26
#define EYE_LEFT_HORIZONTAL_SCROLL 0x27
#define EYE_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define EYE_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A

#define eyeLeft 0x3d    //Ra
#define eyeRight 0x3c   //Ra


class wwEyes : public Adafruit_GFX {    // name changed by Rainer for Wood-Walker, 2015/04/18
 public:
  wwEyes();   // name changed by Rainer for Wood-Walker, 2015/04/18

  void select(uint8_t i2caddr = eyeLeft);  // added by Rainer for Wood-Walker, 2015/04/05  
  
  void begin(void);   // changed to void by Rainer for Wood-Walker, 2015/04/18
    
  void command(uint8_t c);  // name changed by Rainer for Wood-Walker, 2015/04/18
  void ssd1306_data(uint8_t c);

  void clearBuffer(void);
  void invertDisplay(uint8_t i);
  void display();

  uint8_t sd2Eye(const char *filename);
  
  void startscrollright(uint8_t start, uint8_t stop);
  void startscrollleft(uint8_t start, uint8_t stop);

  void startscrolldiagright(uint8_t start, uint8_t stop);
  void startscrolldiagleft(uint8_t start, uint8_t stop);
  void stopscroll(void);

  void dim(boolean dim);

  void drawPixel(int16_t x, int16_t y, uint16_t color);

  virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
  virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);

 private:
  int8_t _vccstate, eyeAddress;

  inline void drawFastVLineInternal(int16_t x, int16_t y, int16_t h, uint16_t color) __attribute__((always_inline));
  inline void drawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color) __attribute__((always_inline));

};
