//
// Created by Alexey Shishkov on 05.04.2023.
//

#include <cmath>
#include "sphere.h"
#include <iostream>

Sphere::Sphere(const Vector3D &center, const double radius, const Color &color_, bool isLightSource) :
        center(center), radius(radius) {
    this->color = color_;
    this->isLightSource = isLightSource;
}

IntersectVisibleObjectWithRayResult Sphere::intersectWithRay(const Ray &ray) {
    double coef_a = ray.viewDir.norm_sq();
    Vector3D diff = ray.pos - center;
    double coef_b = 2 * ray.viewDir.dot(diff);
    double coef_c = diff.norm_sq() - radius * radius;
    double D = coef_b * coef_b - 4 * coef_a * coef_c;
    if (D < 0) {
        return {false, {}, INFINITY};
    }
    double t = (-coef_b - sqrt(D)) / (2 * coef_a);
    if (t < 0) {
        return {false, {}, INFINITY};
    }
    return {true, ray.pos + ray.viewDir * t, t};
}

Vector3D Sphere::normalAtPoint(const Vector3D &point) {
    return (point - center).normalize();
}
