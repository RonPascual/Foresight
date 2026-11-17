//#include detection.h

/*
Function evaluateRisk(radarReading): 

    IF radarReading.detected == FALSE:
        Return NO_WARNING

    IF radar.recordedTime > Max_time_allowed:
        Return NO_WARNING

    IF radarReading.distance < Critical_distance:
        Return HIGH_WARNING

    ELSE IF radarReading.distance < Medium_distance
        Return MEDIUM_WARNING

    ELSE IF radarReading.distance < Low_distance:
        Return LOW_WARNING
        
    ELSE:
        Return NO_WARNING


FUNCTION evaluateDetection(leftRadar, rightRadar):

    CREATE DetectionResult result
    result.leftWarning = evaluateRisk(leftRadar)
    result.rightWarning = evaluateRisk(rightRadar)

    Return result

FUNCTION calculateTTC(distance, closingSpeed):

    IF closingSpeed <= 0:

        RETURN INFINITY

    TTC = distance / closingSpeed

    RETURN TTC

*/