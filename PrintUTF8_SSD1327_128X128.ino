//
// Copyright (c) 2022 Fw-Box (https://fw-box.com)
// Author: Hartman Hsieh
//
// Description :
//   None
//
// Connections :
//
// Required Library :
//   https://github.com/olikraus/U8g2_Arduino
//

#define PIN_A 34
#define PIN_D 35

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define DEVICE_TYPE 12538
#define FIRMWARE_VERSION "1.0.0"

U8G2_SSD1327_MIDAS_128X128_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  /* Uno: A4=SDA, A5=SCL, add "u8g2.setBusClock(400000);" into setup() for speedup if possible */


void setup(void) {
  pinMode(PIN_A, INPUT);
  pinMode(PIN_D, INPUT);
  
  u8g2.begin();
  u8g2.enableUTF8Print();		// enable UTF8 support for the Arduino print() function
}

void loop(void) {
  u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
  //u8g2.setFont(u8g2_font_b10_t_japanese1);  // all the glyphs of "こんにちは世界" are already included in japanese1: Lerning Level 1-6
  u8g2.setFontDirection(0);
  u8g2.firstPage();
  do {
    u8g2.setCursor(0, 15);
    u8g2.print("Hello World!");
    u8g2.setCursor(0, 40);
    u8g2.print("你好世界");		// Chinese "Hello World" 
    //u8g2.print("こんにちは世界");    // Japanese "Hello World" 
    delay(5);
    u8g2.setCursor(0, 40+25);
    u8g2.print(String("PIN_A = ") + analogRead(PIN_A));
    delay(5);
    u8g2.setCursor(0, 40+25+25);
    u8g2.print(String("PIN_D = ") + digitalRead(PIN_D));
  } while ( u8g2.nextPage() );
  //delay(10);
}
