/*
 the list of all the font is in U8g2\src\clib\u8x8.h file 
 */
#include <Arduino.h>
#include <U8x8lib.h>

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  u8x8.begin();
  u8x8.setFlipMode(1);
}

void loop(void) {
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  printTxt("hello");
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  printTxt("hello");
  u8x8.setFont(u8x8_font_inr21_2x4_f);
  printTxt("hello");
}

void printTxt(char txt[])
{
  u8x8.clear();
  u8x8.setCursor(0, 0);
  u8x8.print(txt);
  delay(1000);
}
