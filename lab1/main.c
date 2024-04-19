#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init() {
    glClearColor(0.2, 0.2, 0.2, 0.2);
}

void Desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 1.0f); // azul
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.3f, 0.3f); 
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.3f, 0.3f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f); // vermelho
    glBegin(GL_POLYGON);
    glVertex2f(-0.3f, -0.5f);
    glVertex2f(-0.3f, 0.3f);  
    glVertex2f(0.3f, 0.3f);
    glVertex2f(0.3f, -0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("Casa no Opengl");
    init();
    glutDisplayFunc(Desenha);
    glutMainLoop();
    return 0;
}
