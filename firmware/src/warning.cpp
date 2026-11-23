#include <Arduino.h>
#include "warning.h"

void Light_Up(LEDID id, COLOR color)
{
    if (id == LEFT)
    {
        switch (color)
        {
            case RED:
            {
                analogWrite(LRED, 0);
                analogWrite(LGREEN, 255);
                analogWrite(LBLUE, 255);
                break;
            }
            case ORANGE:
            {
                analogWrite(LRED, 0 );
                analogWrite(LGREEN, 123 );
                analogWrite(LBLUE, 224);
                break;
            }
            case YELLOW:
            {
                analogWrite(LRED, 7);
                analogWrite(LGREEN, 0);
                analogWrite(LBLUE,224 );
                break;
            }
            default:
            {
                analogWrite(LRED, 255);
                analogWrite(LGREEN, 255);
                analogWrite(LBLUE, 255);
                break;
            }
        }
    }
    else
    {
        switch (color)
        {
            case RED:
            {
                analogWrite(RRED, 0);
                analogWrite(RGREEN, 255);
                analogWrite(RBLUE, 255);
                break;
            }
            case ORANGE:
            {
                analogWrite(RRED, 0 );
                analogWrite(RGREEN, 123 );
                analogWrite(RBLUE, 224);
                break;
            }
            case YELLOW:
            {
                analogWrite(RRED, 7);
                analogWrite(RGREEN, 0);
                analogWrite(RBLUE,224 );
                break;
            }
            default:
            {
                analogWrite(LRED, 255);
                analogWrite(LGREEN, 255);
                analogWrite(LBLUE, 255);
                break;
            }
        }
    }
}

void handleDetection(DetectionResult result) {
    //Accessing left and right warnings
    WarningLevel left = result.leftWarning;
    WarningLevel right = result.rightWarning;

    if (left == HIGH_WARNING)
    {
    Light_Up(LEFT, RED);
    digitalWrite(LBUZZ, HIGH);
    }
    else if(left == MEDIUM_WARNING)
    {
    Light_Up(LEFT, ORANGE);
    digitalWrite(LBUZZ, LOW);
    }
    else if(left == LOW_WARNING)
    {
    Light_Up(LEFT, YELLOW);
    digitalWrite(LBUZZ, LOW);
    }
    else
    {
    Light_Up(LEFT, OFF);
    digitalWrite(LBUZZ, LOW);
    }
    if (right == HIGH_WARNING)
    {
        Light_Up(RIGHT, RED);
        digitalWrite(RBUZZ, HIGH);
    }
    else if (right == MEDIUM_WARNING)
    {
        Light_Up(RIGHT, ORANGE);
        digitalWrite(RBUZZ, LOW);
    }
    else if (right == LOW_WARNING)
    {
        Light_Up(RIGHT, YELLOW);
        digitalWrite(RBUZZ, LOW);
    }
    else
    {
        Light_Up(RIGHT, OFF);
        digitalWrite(RBUZZ, LOW);
    }

}
