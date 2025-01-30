#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>


void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

//lamppost

    glBegin(GL_QUADS);
    glColor3ub(128,128,128);
    glVertex2f(-15.0f, -50.0f);
    glVertex2f(15.0f, -50.0f);
    glVertex2f(07.0f, -40.0f);
    glVertex2f(-07.0f, -40.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(15,49,77);
    glVertex2f(-07,-40);
    glVertex2f(07,-40);
    glVertex2f(07,40);
    glVertex2f(-07,40);
    glEnd();

//light

    glBegin(GL_TRIANGLES);
    glColor3ub(15,49,77);
    glVertex2f(15,60);
    glVertex2f(-15,60);
    glVertex2f(00,70);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,252,221);
    glVertex2f(-07,40);
    glVertex2f(07,40);
    glVertex2f(15,60);
    glVertex2f(-15,60);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(15,49,77);
    glVertex2f(-01,40);
    glVertex2f(01,40);
    glVertex2f(01,60);
    glVertex2f(-01,60);
    glEnd();

    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Lamp Post");
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    initGL();
    gluOrtho2D(-100, 100, -100, 100);
    glutMainLoop();

    return 0;
}


