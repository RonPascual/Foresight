#ifndef WARNING_H
#define WARNING_H
#include "foresight_types.h"
//This and its cpp version's purpose is to light up or turn off our common anode RGB LED based on the warnign.
// Similarly, its to turn on or off the buzzer.

const int LRED = 7;
const int LGREEN = 6;
const int LBLUE = 5;
const int RRED = 47;
const int RGREEN = 48;
const int RBLUE = 45;
const int LBUZZ = 4;
const int RBUZZ = 19;

enum LEDID
{
    LEFT,
    RIGHT
};
enum COLOR
{
    RED,
    ORANGE,
    YELLOW,
    OFF
};
//Commands the correct responce to the warning
void handleDetection(DetectionResult result); 
#endif