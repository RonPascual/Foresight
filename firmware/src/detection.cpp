//#include detection.h

/*
Function evaluateRisk(radarReading):

    // Check if the radar detects an object
    IF radarReading.detected == FALSE:
        Return NO_WARNING

    // Check if the radar data is too old
    IF radar.recordedTime > Max_time_allowed:
        Return NO_WARNING
    
    // Get the object's distance and relative closing speed
    distance = radarReading.distance
    closingSpeed = radarReading.closingSpeed

    // If the object is not approaching, no collision is predicted
    IF closingSpeed <= 0:
        RETURN NO_WARNING

    // Calculate how many seconds remain until a possible collision
    TTC = calculateTTC(distance, closingSpeed)

    IF TTC > 5:
        RETURN NO_WARNING
    
    ELSE IF TTC > 3:
        RETURN LOW_WARNING
    
    ELSE IF TTC > 1:
        RETURN MEDIUM_WARNING
    
    ELSE:
        RETURN HIGH_WARNING


FUNCTION evaluateDetection(leftRadar, rightRadar):

    
    CREATE DetectionResult result

    // Evaluate the left radar
    result.leftWarning = evaluateRisk(leftRadar)

    // Evaluate the right radar 
    result.rightWarning = evaluateRisk(rightRadar)

    // Return both warning levels 
    RETURN result


FUNCTION calculateTTC(distance, closingSpeed):

    // If the object is not approaching, TTC cannot be calculated
    IF closingSpeed <= 0:
        RETURN INFINITY

    // Calculate time until the object reaches the user point
    TTC = distance / closingSpeed

    RETURN TTC

*/