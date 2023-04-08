//
// Created by Alexey Shishkov on 05.04.2023.
//
#pragma once

#ifndef RAY_TRACING_CPP_ENGINE_H
#define RAY_TRACING_CPP_ENGINE_H

#include "../objects/vector3d.h"
#include "../objects/ray.h"
#include "../objects/sphere.h"
#include "../utils/utils.h"
#include "../objects/camera.h"

void render(
        cv::Mat &image,
        const std::vector<std::shared_ptr<VisibleObject>> &objects,
        const Camera &cam,
        int w,
        int h
);


#endif //RAY_TRACING_CPP_ENGINE_H
