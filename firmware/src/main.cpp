#include <Arduino.h>
#include "warning.h"
#include "radar.h"
#include "foresight_types.h"
#include "detection.h"


// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(115200);
  pinMode(LRED, OUTPUT);
  pinMode(LGREEN, OUTPUT);
  pinMode(LBLUE, OUTPUT);
  pinMode(RRED, OUTPUT);
  pinMode(RGREEN, OUTPUT);
  pinMode(RBLUE, OUTPUT);
  pinMode(RBUZZ, OUTPUT);
  pinMode(LBUZZ, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}