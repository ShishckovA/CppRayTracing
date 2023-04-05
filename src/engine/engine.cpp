//
// Created by Alexey Shishkov on 05.04.2023.
//
#include "engine.h"
#include <iostream>

IntersectRaySphereResult::IntersectRaySphereResult(bool intersects,
                                                   const Vector3D &intersection_point,
                                                   double time_to_intersect)
        : intersects(intersects),
          intersection_point(intersection_point),
          time_to_intersect(time_to_intersect) {}

IntersectRaySphereResult intersect_ray_sphere(const Ray &ray, const Sphere &sphere) {
    double coef_a = ray.view_dir.norm_sq();
    std::cout << ray.view_dir << std::endl;
    Vector3D diff = ray.pos - sphere.center;
    double coef_b = 2 * ray.view_dir.dot(diff);
    double coef_c = diff.norm_sq() - sphere.radius * sphere.radius;
//    std::cout << coef_a << " " << coef_b << " " << coef_c << std::endl;
    std::cout << sphere.center << " " << sphere.radius << " " << ray.pos << " " << ray.view_dir << std::endl;
    double D = coef_b * coef_b - 4 * coef_a * coef_c;
    if (D < 0) {
        return {false, {}, 1e23};
    }
    double t = (-coef_b - sqrt(D)) / (2 * coef_a);
    if (t < 0) {
        return {false, {}, 1e23};
    }
    return {true, ray.pos + ray.view_dir * t, t};
}
