
#include "detection.h"

// Experimental thresholds (meters)
// Must be calibrated through testing.
const float LOW_THRESHOLD = 10.0;
const float MEDIUM_THRESHOLD = 5.0;
const float HIGH_THRESHOLD = 2.0;

// Ignore old radar readings
const unsigned long MAX_DATA_AGE_MS = 500;

// Evaluate one radar sensor
WarningLevel evaluateRisk(RadarReading radar) {

    // No object detected
    if (!radar.detected) {
        return NO_WARNING;
    }

    // Ignore invalid or stale readings
    if (radar.distanceM < 0 ||
        radar.ageMs > MAX_DATA_AGE_MS) {
        return NO_WARNING;
    }

    // Evaluate distance
    if (radar.distanceM <= HIGH_THRESHOLD) {
        return HIGH_WARNING;
    }

    if (radar.distanceM <= MEDIUM_THRESHOLD) {
        return MEDIUM_WARNING;
    }

    if (radar.distanceM <= LOW_THRESHOLD) {
        return LOW_WARNING;
    }

    return NO_WARNING;
}

// Evaluate left and right radar sensors
DetectionResult evaluateDetection(
    RadarReading leftRadar,
    RadarReading rightRadar
) {
    DetectionResult result;

    result.leftWarning = evaluateRisk(leftRadar);
    result.rightWarning = evaluateRisk(rightRadar);

    return result;
}
