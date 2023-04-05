cmake_minimum_required(VERSION 3.24)
project(ray_tracing_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(ray_tracing_cpp src/main.cpp src/objects/vector3d.cpp src/objects/vector3d.h src/objects/ray.cpp src/objects/ray.h src/objects/sphere.cpp src/objects/sphere.h src/objects/camera.cpp src/objects/camera.h src/engine/utils.cpp src/engine/utils.h src/engine/engine.cpp src/engine/engine.h)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(ray_tracing_cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
