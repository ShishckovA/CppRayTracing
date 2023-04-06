//
// Created by Alexey Shishkov on 05.04.2023.
//
#pragma once

#ifndef RAY_TRACING_CPP_RAY_H
#define RAY_TRACING_CPP_RAY_H

#include "vector3d.h"

class Ray {
public:
    Vector3D pos;
    Vector3D view_dir;
    Ray(const Vector3D& pos, const Vector3D& view_dir);
    Ray() = default;
};

class IntersectVisibleObjectWithRayResult {
public:
    bool intersects;
    Vector3D intersection_point;
    double time_to_intersect;
    IntersectVisibleObjectWithRayResult() = default;
    IntersectVisibleObjectWithRayResult(bool intersects, const Vector3D& intersection_point, double time_to_intersect);
};

#endif //RAY_TRACING_CPP_RAY_H
