#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

float dx = 0.0;
float dy = 0.0;
float ang = 0.0;
float tamanho=1;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Define a cor de fundo como branco
}

void teclado (unsigned char tecla, int x, int y)
{
    switch (tecla) {
    case 'a': dx = dx - 0.1; glutPostRedisplay(); break; //esquerda
    case 'd': dx = dx + 0.1; glutPostRedisplay(); break;  //direita
    case 's': dy = dy - 0.1; glutPostRedisplay(); break; //desce
    case 'w': dy = dy + 0.1; glutPostRedisplay(); break;  //sobe
    case 'r': ang=ang+45; glutPostRedisplay(); break;  //rotaciona
    case '+': tamanho=tamanho+0.1; glutPostRedisplay(); break;  //aumenta tamanho
    case '-': tamanho=tamanho-0.1; glutPostRedisplay(); break;  //diminui tamanho
    }
}

void Desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenha uma casinha composta de um quadrado e um triângulo
    glLoadIdentity();
    //desloca na horizontal e vertical pelo valor obtido em dx/dy
    glTranslatef(dx, dy, 0.0);
    //rotaciona
    glRotatef(ang, 0,0,1);
    //muda tamanho
    glScalef(1,tamanho,1);


    // Desenha o retângulo da casa
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3f, -0.5f);
    glVertex2f(-0.3f, 0.3f);  
    glVertex2f(0.3f, 0.3f);
    glVertex2f(0.3f, -0.5f);
    glEnd();

    glLoadIdentity();
    //desloca na horizontal e vertical pelo valor obtido em dx/dy
    glTranslatef(dx, dy, 0.0);
    //rotaciona
    glRotatef(ang, 0,0,1);
    //muda tamanho
    glScalef(1,tamanho,1);

    glColor3f(1.0f, 0.7f, 0.0f); // vermelho
    // telhado
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.3f, 0.3f); 
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.3f, 0.3f);
    glEnd();

    // Executa os comandos OpenGL
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("Casinha com animacao");
    init();
    glutKeyboardFunc(teclado);
    glutDisplayFunc(Desenha);
    glutMainLoop();
    return 0;
}
