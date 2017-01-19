#include <FillPat.h>
#include <LaunchPad.h>
#include <OrbitBoosterPackDefs.h>
#include <OrbitOled.h>
#include <OrbitOledChar.h>
#include <OrbitOledGrph.h>
#include <stdlib.h>
#include "Simon.h"
extern const uint32_t Potentiometer;

void setup() {
  WireInit();
  LedSetup();
  Serial.begin(9600);
  delay(100);
  Simon.sequenceLength = 1;
  srand((8 + analogRead(Potentiometer)) * 888);
  GameUIInit();
  gameInit();
  AccelerometerInit();
}

void loop() {
  updateGameUI();
}
