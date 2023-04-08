//
// Created by Alexey Shishkov on 05.04.2023.
//

#include "vector3d.h"

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

std::ostream &operator<<(std::ostream &out, const Vector3D &v) {
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

Vector3D Vector3D::randomInHemiSpace(const Vector3D &separatorPlaneNormal) {
    std::random_device dev;
    std::mt19937 rng(dev());

    std::uniform_real_distribution<double> dist_phi(-M_PI, M_PI);
    double phi = dist_phi(rng);
    std::uniform_real_distribution<double> dist_z(-1, 1);
    double z = dist_z(rng);
    double cosArcsinZ = sqrt(1 - z * z);
    Vector3D ans(sin(phi) * cosArcsinZ, cos(phi) * cosArcsinZ, z);
    if (ans.dot(separatorPlaneNormal) < 0) {
        ans = ans * -1;
    }
    return ans;
//    return Vector3D::byPolarAngles(planeNormalPhi + dist(rng), planeNormalPsi + dist(rng));
}

Vector3D Vector3D::byPolarAngles(double phi, double psi, double radius) {
    return Vector3D(sin(phi) * cos(psi), cos(phi) * cos(psi), sin(psi)) * radius;
}



