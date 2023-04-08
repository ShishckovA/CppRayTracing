//
// Created by Alexey Shishkov on 05.04.2023.
//
#pragma once

#ifndef RAY_TRACING_CPP_VECTOR3D_H
#define RAY_TRACING_CPP_VECTOR3D_H


#include <ostream>
#include "../utils/utils.h"


float const EPS = 1e-6;

class Vector3D {
public:
    double x, y, z;

    Vector3D(double x, double y, double z);

    Vector3D() = default;

    Vector3D operator+(const Vector3D &other) const;

    Vector3D operator-(const Vector3D &other) const;

    Vector3D operator/(double other) const;

    Vector3D operator*(double other) const;

    bool operator==(const Vector3D &other) const;

    [[nodiscard]] double norm() const;

    [[nodiscard]] double norm_sq() const;

    [[nodiscard]] Vector3D normalize() const;

    [[nodiscard]] double dot(const Vector3D &other) const;

    [[nodiscard]] Vector3D cross(const Vector3D &other) const;

    static Vector3D randomInHemiSpace(const Vector3D &separatorPlaneNormal);

    static Vector3D byPolarAngles(double phi, double psi, double radius = 1);

    friend std::ostream &operator<<(std::ostream &out, const Vector3D &v);
};

std::ostream &operator<<(std::ostream &out, const Vector3D &v);

#endif //RAY_TRACING_CPP_VECTOR3D_H
