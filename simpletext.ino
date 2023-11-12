#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN      8

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  myDisplay.begin();
  myDisplay.setIntensity(0);
  myDisplay.displayClear();
}

void loop() {
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.print("Hello!");
}
