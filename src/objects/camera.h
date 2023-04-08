//
// Created by Alexey Shishkov on 05.04.2023.
//
#pragma once

#ifndef RAY_TRACING_CPP_CAMERA_H
#define RAY_TRACING_CPP_CAMERA_H

#include "vector3d.h"
#include "ray.h"
#include "../utils/utils.h"


#include <vector>

class Camera {
public:
    Vector3D pos;
    Vector3D viewDir;
    int resolutionW, resolutionH;
    double fov;

    Camera(const Vector3D &pos, const Vector3D &view_dir, int resolutionW, int resolutionH, double fov);

    [[nodiscard]] std::vector<std::vector<Ray>> pixelRays() const;
};


#endif //RAY_TRACING_CPP_CAMERA_H
