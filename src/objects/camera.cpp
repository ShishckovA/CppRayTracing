//
// Created by Alexey Shishkov on 05.04.2023.
//

#include "camera.h"

Camera::Camera(const Vector3D &pos, const Vector3D &viewDir, int resolutionW, int resolutionH, double fov) :
        pos(pos), viewDir(viewDir.normalize()), resolutionH(resolutionH), resolutionW(resolutionW), fov(
        degreesToRadians(fov)) {}

std::vector<std::vector<Ray>> Camera::pixelRays() const {
    Vector3D v1 = Vector3D(viewDir.y, -viewDir.x, 0).normalize(); // ->
    v1 = v1 * tan(fov / 2) * 2;
    Vector3D v2 = viewDir.cross(v1).normalize(); // ^
    v2 = v2 * v1.norm() * resolutionH / resolutionW;
    Vector3D corner = pos + viewDir - v1 / 2 - v2 / 2;
    std::vector<std::vector<Ray>> result(resolutionH, std::vector<Ray>(resolutionW));
    for (int i = 0; i < resolutionH; ++i) {
        for (int j = 0; j < resolutionW; ++j) {
            Vector3D to_point = corner + v1 * j / resolutionW + v2 * i / resolutionH;
            result[i][j] = Ray(pos, to_point - pos);
        }
    }
    return result;
}
