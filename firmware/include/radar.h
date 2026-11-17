#ifndef RADAR_H
#define RADAR_H

#include <Arduino.h>
#include "foresight_types.h"

void readRadarBytes();
void resetFrame();
bool isFrameValid(const uint8_t* buf, size_t len);
uint16_t combineBytes(const uint8_t* p);
Target decodeTarget(const uint8_t* record);
void printTarget(const Target& target);

#endif // RADAR_H