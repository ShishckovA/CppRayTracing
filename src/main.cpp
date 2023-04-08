#include <iostream>
#include "utils/utils.h"
#include "objects/vector3d.h"
#include "objects/sphere.h"
#include "objects/camera.h"
#include "engine/engine.h"
#include <opencv2/opencv.hpp>



int main() {
    std::vector<std::shared_ptr<VisibleObject>> spheres;
    spheres.push_back(std::make_shared<Sphere>(
            Vector3D(0, 0, 0),
            29.4167,
            LIGHT_GREY
    ));
    spheres.push_back(std::make_shared<Sphere>(
            Vector3D(4.90056, -0.952006, 29.3005),
            0.292315,
            RED
    ));
//    spheres.push_back(std::make_shared<Sphere>(
//            Vector3D(4.12547, 0.417787, 29.5553),
//            0.292315,
//            GREEN
//    ));
    spheres.push_back(std::make_shared<Sphere>(
            Vector3D(-90.8769, 20.2614, 80.5198),
            10.4248,
            WHITE,
            true
    ));
    Vector3D C = Vector3D(11.6385, -5.32811, 30.057);
    Vector3D dr = (Vector3D(6.28092, -0.952006, 29.767) - C).normalize();
    int downscale = 20;
    int w = 1920 / downscale, h = 1080 / downscale;
    Camera cam = Camera(C, dr, w, h, 80);

    cv::Mat image(h, w, CV_32FC3, cv::Scalar(0, 0, 0));
    std::cout << "Starting rendering... ";
    std::cout.flush();
    auto start = clock();
    render(image, spheres, cam, w, h);
    auto end = clock();
    std::cout << "done!" << std::endl;
    std::cout << "Rendering took " << (float) (end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
    cv::imwrite("out.png", image * 256.);
    return 0;
}