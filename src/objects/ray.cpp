//
// Created by Alexey Shishkov on 05.04.2023.
//

#include "ray.h"

Ray::Ray(const Vector3D &pos, const Vector3D &view_dir) : pos(pos), view_dir(view_dir.normalize()) {}

