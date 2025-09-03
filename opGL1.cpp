#include <iostream>
#include <GL/glut.h>

using namespace std;

#define windowHeight 600
#define windowWidth 600

void rectangle(float x, float y, float h, float w, float color[3]){
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_POLYGON);

    glVertex2d(x, y);
    glVertex2d(x + w, y);
    glVertex2d(x + w, y + h);
    glVertex2d(x, y + h);

    glEnd();
}

void robot(){
    glClear(GL_COLOR_BUFFER_BIT);

    float gray[3] = {0.5, 0.5, 0.5};
    rectangle(-0.7, -0.7, 1.4, 1.4, gray);

    float red[3] = {1, 0, 0};
    rectangle(-0.5, 0.3, 0.3, 0.3, red);
    rectangle(0.2, 0.3, 0.3, 0.3, red);

    float blue[3] = {0, 0, 1};
    rectangle(-0.5, -0.5, 0.4, 1, blue);

    glutSwapBuffers();
}

int main(int argc, char** argv){
  //----- Criar janela -----//
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(windowWidth, windowHeight);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("trying OpenGL");
  glClearColor(1.0, 1.0, 1.0, 1.0);// Limpa a tela (red, green, blue, alpha)

  robot();

  glutMainLoop();

  return 0;
}