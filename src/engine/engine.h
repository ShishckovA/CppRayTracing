//
// Created by Alexey Shishkov on 05.04.2023.
//
#pragma once

#ifndef RAY_TRACING_CPP_ENGINE_H
#define RAY_TRACING_CPP_ENGINE_H

#include "../objects/vector3d.h"
#include "../objects/ray.h"
#include "../objects/sphere.h"
#include "utils.h"

class IntersectRaySphereResult {
public:
    bool intersects;
    Vector3D intersection_point;
    double time_to_intersect;
    IntersectRaySphereResult(bool intersects, const Vector3D& intersection_point, double time_to_intersect);
};

IntersectRaySphereResult intersect_ray_sphere(const Ray& ray, const Sphere& sphere);


#endif //RAY_TRACING_CPP_ENGINE_H
