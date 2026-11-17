#ifndef FORESIGHT_TYPES_H
#define FORESIGHT_TYPES_H

struct RadarReading {
    bool detected;
    float distanceM;
    unsigned long ageMs;
};

enum WarningLevel {
    NO_WARNING,
    LOW_WARNING,
    MEDIUM_WARNING,
    HIGH_WARNING
};

struct DetectionResult {
    WarningLevel leftWarning;
    WarningLevel rightWarning;
};

#endif