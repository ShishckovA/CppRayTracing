//#include <iostream>
//#include "engine/utils.h"
//#include "engine/engine.h"
//#include "objects/vector3d.h"
//#include "objects/sphere.h"
//#include "objects/ray.h"
//#include <iostream>
//
//
//
//
//int main() {
//    Vector3D A = Vector3D(3.4796837855602, -2.075148115942, 0);
//    double R = 7.222120;
//    Sphere s = Sphere(A, R);
//    Vector3D C = Vector3D(-5.4578883691403, 3.9933997900341, 1.0539281081868);
//    Vector3D D = Vector3D(-2.6642031557155, 3.8605904050278, 0.4014265611753);
//    Vector3D dr = D - C;
//    std::cout << dr << " dr" << std::endl;
//    Ray r = Ray(C, dr);
//    IntersectRaySphereResult result = intersect_ray_sphere(r, s);
//    std::cout << result.intersection_point << " " << result.time_to_intersect << " " << result.intersects << std::endl;
//    std::cout << Vector3D(-0.7617402003450486, 3.770148957335032, -0.042918426422460465) << std::endl;
//    return 0;
//}

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.0,0.5,0.0);
    glVertex3f(0.5,-0.5,0.0);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv) {

    // инициализация
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("Урок 1");

    // регистрация обратных вызовов
    glutDisplayFunc(renderScene);

    // Основной цикл GLUT
    glutMainLoop();

    return 1;
}