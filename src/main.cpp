#include <iostream>
#include "utils/utils.h"
#include "objects/vector3d.h"
#include "objects/sphere.h"
#include "objects/camera.h"
#include "objects/ray.h"
#include <opencv2/opencv.hpp>


void render(
        cv::Mat& image,
        const std::vector<std::unique_ptr<VisibleObject>>& objects,
        const Camera& cam,
        int w,
        int h
) {
    std::vector<std::vector<Ray>> rays = cam.pixel_rays();

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            double min_t = INFINITY;
            Color closest_color;
            IntersectVisibleObjectWithRayResult closest_intersection{};
            auto& color = image.at<Color>(i, j);

            for (const auto& obj_ptr : objects) {
                IntersectVisibleObjectWithRayResult cur_intersection = obj_ptr->intersectWithRay(rays[i][j]);
                if (cur_intersection.time_to_intersect < min_t) {
                    closest_intersection = cur_intersection;
                    closest_color = obj_ptr->color;
                    min_t = cur_intersection.time_to_intersect;
                }
            }
            if (min_t < INFINITY) {
                copy_color(color, closest_color);
            } else if (rays[i][j].view_dir.z > 0) {
                copy_color(color, LIGHT_BLUE);
            } else {
                copy_color(color, LIGHT_BROWN);
            }
        }
    }
}


int main() {
    std::vector<std::unique_ptr<VisibleObject>> spheres;
    Sphere s1(Vector3D(0, 0, 0), 29.4167, LIGHT_GREY);
    std::cout << s1.color << std::endl;
    spheres.push_back(std::make_unique<Sphere>(s1));
    spheres.push_back(std::make_unique<Sphere>(Vector3D(4.90056, -0.952006, 29.3005), 0.292315, RED));
    spheres.push_back(std::make_unique<Sphere>(Vector3D(4.12547, 0.417787, 29.5553), 0.292315, GREEN));
    spheres.push_back(std::make_unique<Sphere>(Vector3D(-90.8769, 20.2614, 80.5198), 10.4248, YELLOW));
    Vector3D C = Vector3D(11.6385, -5.32811, 30.057);
    Vector3D dr = (Vector3D(6.28092, -0.952006, 29.767) - C).normalize();
    int w = 1920 * 2, h = 1080 * 2;
    Camera cam = Camera(C, dr, w, h, 90);

    cv::Mat image(h, w, CV_8UC3, cv::Scalar(0, 0, 0));
    auto start = clock();
    render(image, spheres, cam, w, h);
    auto end = clock();
    std::cout << (float) (end - start)  / CLOCKS_PER_SEC << std::endl;
    cv::imwrite("out.jpg", image);
    std::cout << "Hello, world!" << std::endl;
    return 0;
}