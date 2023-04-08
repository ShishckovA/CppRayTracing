//
// Created by Alexey Shishkov on 05.04.2023.
//
#pragma once

#ifndef RAY_TRACING_CPP_SPHERE_H
#define RAY_TRACING_CPP_SPHERE_H
#include "vector3d.h"
#include "visible_object.h"
#include "../utils/utils.h"


class Sphere : public VisibleObject {
public:
    Vector3D center;
    double radius;
    Sphere(const Vector3D& center, double radius, const Color& color, bool isLightSource = false);
    IntersectVisibleObjectWithRayResult intersectWithRay(const Ray& ray) override;
    Vector3D normalAtPoint(const Vector3D &point) override;
};


#endif //RAY_TRACING_CPP_SPHERE_H
