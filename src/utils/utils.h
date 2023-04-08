//
// Created by Alexey Shishkov on 05.04.2023.
//
#pragma once

#ifndef RAY_TRACING_CPP_UTILS_H
#define RAY_TRACING_CPP_UTILS_H

#include <cmath>
#include <opencv2/opencv.hpp>
#include <random>
#include <cmath>

typedef cv::Vec3f Color;


const Color BLACK = {0., 0., 0.};
const Color BLUE = {1., 0., 0.};
const Color GREEN = {0, 1., 0};
const Color RED = {0, 0, 1.};
const Color WHITE = {1., 1., 1.};
const Color GREY = {1., 1., 1.};
const Color YELLOW = {0, 1., 1.};
const Color LIGHT_GREY = {.75, .75, .75};
const Color LIGHT_BROWN = {.33, .46, .6};
const Color LIGHT_BLUE = {.98, .8, .05};

double degreesToRadians(double degrees);

double radiansToDegrees(double radians);

void copyColor(Color &toChange, const Color &toCopy);

#endif //RAY_TRACING_CPP_UTILS_H
