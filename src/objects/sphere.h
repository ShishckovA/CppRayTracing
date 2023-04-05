//
// Created by Alexey Shishkov on 05.04.2023.
//
#pragma once

#ifndef RAY_TRACING_CPP_SPHERE_H
#define RAY_TRACING_CPP_SPHERE_H
#include "vector3d.h"

class Sphere {
public:
    Vector3D center;
    double radius;
    Sphere(const Vector3D& center, const double radius);
};


#endif //RAY_TRACING_CPP_SPHERE_H
