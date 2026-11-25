#include <Arduino.h>
#include "warning.h"

static const WarningLevel LEVELS[] = { NO_WARNING, LOW_WARNING, MEDIUM_WARNING, HIGH_WARNING };
static const char* NAMES[] = { "NONE", "LOW", "MEDIUM", "HIGH" };

static int failures = 0;

static void check(const char* label, bool ok)
{
    Serial.printf("  [%s] %s\n", ok ? "PASS" : "FAIL", label);
    if (!ok) failures++;
}

static void runCase(int l, int r)
{
    DetectionResult res;
    res.leftWarning = LEVELS[l];
    res.rightWarning = LEVELS[r];

    Serial.printf("Left=%s  Right=%s\n", NAMES[l], NAMES[r]);
    handleDetection(res);

    // Buzzer should only be on for HIGH
    check("left buzzer",  digitalRead(LBUZZ) == (LEVELS[l] == HIGH_WARNING ? HIGH : LOW));
    check("right buzzer", digitalRead(RBUZZ) == (LEVELS[r] == HIGH_WARNING ? HIGH : LOW));

    delay(2000);  // time to look at the LEDs
}

void setup()
{
    Serial.begin(115200);
    delay(1500);
    Serial.println("=== Warning test start ===");
    //checking all combinations of high and low
    for (int l = 0; l < 4; l++)
        for (int r = 0; r < 4; r++)
            runCase(l, r);

    Serial.printf("=== Done: %d failure(s) ===\n", failures);
}

void loop() {}