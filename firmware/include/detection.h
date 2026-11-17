
#ifndef DETECTION_H
#define DETECTION_H

#include "foresight_types.h"

// Analyze both radar sensors
DetectionResult evaluateDetection(
    RadarReading leftRadar,
    RadarReading rightRadar
);

#endif
