//
// Created by Alexey Shishkov on 05.04.2023.
//
#include "engine.h"


std::tuple<IntersectVisibleObjectWithRayResult, std::shared_ptr<VisibleObject>> closestIntersection(
        const Ray &ray,
        const std::vector<std::shared_ptr<VisibleObject>> &objects) {
    std::shared_ptr<VisibleObject> closestObject;
    IntersectVisibleObjectWithRayResult closestIntersection(false, {}, 0);
    for (const auto &objPtr: objects) {
//        std::cout << objPtr->color << std::endl;
        IntersectVisibleObjectWithRayResult curIntersection = objPtr->intersectWithRay(ray);
        if (curIntersection.intersects && (
                !closestIntersection.intersects ||
                curIntersection.timeToIntersect < closestIntersection.timeToIntersect)) {
            closestIntersection = curIntersection;
            closestObject = objPtr;
        }
    }
    return std::make_tuple(closestIntersection, closestObject);
}

Color ray_trace(const Ray &start,
                const std::vector<std::shared_ptr<VisibleObject>> &objects,
                int depth = 3) {
    Ray current = start;
    std::vector<std::shared_ptr<VisibleObject>> bouncedObjects;
    for (int i = 0; i < depth; ++i) {
        const auto &[intersection, object] = closestIntersection(current, objects);
        if (!intersection.intersects) {
            if (i == 0) {
                if (current.viewDir.z > 0) {
                    return LIGHT_BLUE;
                }
                return LIGHT_BROWN;
            }
            return BLACK;
        }
        bouncedObjects.push_back(object);

        if (object->isLightSource) {
            break;
        }
        Vector3D newDir = Vector3D::randomInHemiSpace(
                object->normalAtPoint(intersection.intersection_point)
        );
        current = Ray(intersection.intersection_point, newDir);
    }
    std::reverse(bouncedObjects.begin(), bouncedObjects.end());
    if (!bouncedObjects[0]->isLightSource) {
        return BLACK;
    }
    Color ans(bouncedObjects[0]->color);
    for (int i = 1; i < bouncedObjects.size(); ++i) {
        ans[0] *= bouncedObjects[i]->color[0];
        ans[1] *= bouncedObjects[i]->color[1];
        ans[2] *= bouncedObjects[i]->color[2];
    }
    return ans;


}

void render(
        cv::Mat &image,
        const std::vector<std::shared_ptr<VisibleObject>> &objects,
        const Camera &cam,
        int w,
        int h
) {
    std::vector<std::vector<Ray>> rays = cam.pixelRays();

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int N = 1000;
            Color ans(0, 0, 0);
            int countGood = 0;
            for (int k = 0; k < N; ++k) {
                Color cc = ray_trace(rays[i][j], objects);
                ans[0] += cc[0];
                ans[1] += cc[1];
                ans[2] += cc[2];
                if (cc != Color(0, 0, 0)) {
                    countGood += 1;
                }
            }
            ans[0] /= (float) countGood;
            ans[1] /= (float) countGood;
            ans[2] /= (float) countGood;
            copyColor(image.at<Color>(i, j), ans);
        }
    }
}