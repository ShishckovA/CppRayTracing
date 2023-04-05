//
// Created by Alexey Shishkov on 05.04.2023.
//
#pragma once

#ifndef RAY_TRACING_CPP_CAMERA_H
#define RAY_TRACING_CPP_CAMERA_H
#include "vector3d.h"
#include "ray.h"
#include "../engine/utils.h"


#include <vector>

class Camera {
public:
    Vector3D pos;
    Vector3D view_dir;
    int resolution_w, resolution_h;
    double fov;
    Camera(const Vector3D& pos, const Vector3D& view_dir, int resolution_w, int resolution_h, double fov);
    [[nodiscard]] std::vector<std::vector<Ray>> pixel_rays() const;
};


#endif //RAY_TRACING_CPP_CAMERA_H
