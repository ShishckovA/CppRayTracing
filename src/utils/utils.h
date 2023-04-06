//
// Created by Alexey Shishkov on 05.04.2023.
//
#pragma once

#ifndef RAY_TRACING_CPP_UTILS_H
#define RAY_TRACING_CPP_UTILS_H
#include <cmath>
#include <opencv2/opencv.hpp>

typedef cv::Vec3b Color;

const Color BLACK = {0, 0, 0};
const Color BLUE = {255, 0, 0};
const Color GREEN = {0, 255, 0};
const Color RED = {0, 0, 255};
const Color WHITE = {255, 255, 255};
const Color GREY = {127, 127, 127};
const Color YELLOW = {0, 255, 255};
const Color LIGHT_GREY = {196, 196, 196};
const Color LIGHT_BROWN = {84, 118, 152};
const Color LIGHT_BLUE = {250, 206, 135};

double degrees_to_radians(double degrees);
double radians_to_degrees(double radians);

void copy_color(Color& to_change, const Color& to_copy);

#endif //RAY_TRACING_CPP_UTILS_H
