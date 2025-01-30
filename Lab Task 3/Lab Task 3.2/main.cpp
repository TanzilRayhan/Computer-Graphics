#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);

    //tree
    glBegin(GL_QUADS);
    glColor3ub(237,153,80);
    glVertex2f(-10,-80);
    glVertex2f(10,-80);
    glVertex2f(10,-15);
    glVertex2f(-10,-15);
    glEnd();

    //Leaf 1
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(-50,-15);
    glVertex2f(50,-15);
    glVertex2f(0.0,50);
    glEnd();

    //Leaf 2
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-35,20);
    glVertex2f(35,20);
    glVertex2f(0.0,80);
    glEnd();

    glFlush();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Rectangle");
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    initGL();
    gluOrtho2D(-100, 100, -100, 100);
    glutMainLoop();

    return 0;
}


