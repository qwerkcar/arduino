#include <MD_MAX72xx.h>
#include <SPI.h>

#define  delay_t  50  // in milliseconds

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

//Hardware SPI Arduino UNO
// CLK Pin  > 13 SCK
// Data Pin > 11 MOSI

#define CS_PIN    8

// Hardware SPI connection
MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

byte heart[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};
byte face[8] = {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
byte face2[8] = {0x00, 0x24, 0x24, 0x24, 0x00, 0x42, 0x3C, 0x00};
byte arrow[8] = {0x18, 0x0C, 0x06, 0xFF, 0xFF, 0x06, 0x0C, 0x18};

void setup() {  
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 0);
  mx.clear();
  }

void loop() {
  drawShape();
}

void drawShape() {
  for (int i = 0; i <= 7; i++) {
    mx.setRow(0, 0, i, heart[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(1, 1, i, face[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(2, 2, i, face2[i]);
  }
  delay(delay_t);
  for (int i = 0; i <= 7; i++) {
    mx.setRow(3, 3, i, arrow[i]);
  }
  delay(delay_t);
}
