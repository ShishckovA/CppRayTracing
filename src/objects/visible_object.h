//
// Created by Alexey Shishkov on 06.04.2023.
//

#ifndef RAY_TRACING_CPP_VISIBLE_OBJECT_H
#define RAY_TRACING_CPP_VISIBLE_OBJECT_H

#include "ray.h"
#include "../utils/utils.h"

class VisibleObject {
public:
    Color color;

    bool isLightSource;

    virtual IntersectVisibleObjectWithRayResult intersectWithRay(const Ray &ray) = 0;

    virtual Vector3D normalAtPoint(const Vector3D &point) = 0;

    virtual ~VisibleObject() = default;
};

#endif //RAY_TRACING_CPP_VISIBLE_OBJECT_H
