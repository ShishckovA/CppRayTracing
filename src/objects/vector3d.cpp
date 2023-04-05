//
// Created by Alexey Shishkov on 05.04.2023.
//

#include <cmath>
#include "vector3d.h"

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

std::ostream& operator<<(std::ostream& out, const Vector3D& v) {
    out << "Vector(" << v.x << " " << v.y << " " << v.z << ")";
    return out;
}

Vector3D Vector3D::operator+(const Vector3D &other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Vector3D Vector3D::operator-(const Vector3D &other) const {
    return {x - other.x, y - other.y, z - other.z};
}

Vector3D Vector3D::operator*(const double other) const {
    return {x * other, y * other, z * other};
}

Vector3D Vector3D::operator/(const double other) const {
    return {x / other, y / other, z / other};
}

bool Vector3D::operator==(const Vector3D &other) const {
    return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS && fabs(z - other.z) < EPS;
}


double Vector3D::norm() const {
    return sqrt(x * x + y * y + z * z);
}

double Vector3D::norm_sq() const {
    return x * x + y * y + z * z;
}

Vector3D Vector3D::normalize() const {
    return (*this) / norm();
}

double Vector3D::dot(const Vector3D &other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3D Vector3D::cross(const Vector3D &other) const {
    return {
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.z
    };
}



