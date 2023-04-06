cmake_minimum_required(VERSION 3.24)
project(ray_tracing_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../run/)

add_executable(ray_tracing_cpp src/main.cpp src/objects/vector3d.cpp src/objects/vector3d.h src/objects/ray.cpp src/objects/ray.h src/objects/sphere.cpp src/objects/sphere.h src/objects/camera.cpp src/objects/camera.h src/utils/utils.cpp src/utils/utils.h src/engine/engine.cpp src/engine/engine.h src/objects/visible_object.cpp src/objects/visible_object.h)
set(OpenCV_DIR lib/opencv)
find_package(OpenCV REQUIRED)

target_link_libraries(ray_tracing_cpp ${OpenCV_LIBS})
