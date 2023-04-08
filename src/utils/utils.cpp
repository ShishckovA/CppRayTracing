//
// Created by Alexey Shishkov on 05.04.2023.
//

#include "utils.h"

double degreesToRadians(double degrees) {
    return (degrees * M_PI) / 180.0;
}

double radiansToDegrees(double radians) {
    return radians * 180.0 / M_PI;
}

void copyColor(Color &toChange, const Color &toCopy) {
    toChange[0] = toCopy[0];
    toChange[1] = toCopy[1];
    toChange[2] = toCopy[2];
}