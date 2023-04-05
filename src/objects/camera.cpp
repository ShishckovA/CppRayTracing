//
// Created by Alexey Shishkov on 05.04.2023.
//

#include "camera.h"

Camera::Camera(const Vector3D &pos, const Vector3D &view_dir, int resolution_w, int resolution_h, double fov) :
        pos(pos), view_dir(view_dir.normalize()), resolution_h(resolution_h), resolution_w(resolution_w), fov(
        degrees_to_radians(fov)) {}

std::vector<std::vector<Ray>> Camera::pixel_rays() const {
    Vector3D v1 = Vector3D(view_dir.y, -view_dir.x, 0).normalize(); // ->
    v1 = v1 * tan(fov / 2) * 2;
    Vector3D v2 = view_dir.cross(v1).normalize(); // ^
    v2 = v2 * v1.norm() * resolution_h / resolution_w;
    Vector3D corner = pos + view_dir - v1 / 2 - v2 / 2;
    std::vector<std::vector<Ray>> result(resolution_h, std::vector<Ray>(resolution_w));
    for (int i = 0; i < resolution_h; ++i) {
        for (int j = 0; j < resolution_w; ++j) {
            Vector3D to_point = corner + v1 * j / resolution_w + v2 * i / resolution_h;
            result[i][j] = Ray(pos, to_point - pos);
        }
    }
    return result;
}
