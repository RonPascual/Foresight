#ifndef FORESIGHT_TYPES_H
#define FORESIGHT_TYPES_H

// One detected target's information
struct Target {
  uint8_t id;
  uint8_t direction;   // 1 = left, 2 = right
  float   distance_m;
  float   speed_kmh;
  bool    highSpeed;
  bool    associated;
  uint8_t frames;
  int16_t angle_deg;
  int ignored;
};

// A frame of radar data containing multiple targets
struct RadarFrame {
    Target targets[10];
    size_t count;  // number of targets in the frame
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