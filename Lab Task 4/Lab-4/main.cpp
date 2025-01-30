#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>

void initGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
//Left Stand
    glBegin(GL_QUADS);
    glColor3ub(15,49,77);
    glVertex2f(-55,-60);
    glVertex2f(-65,-60);
    glVertex2f(-65,-18);
    glVertex2f(-55,-18);
    glEnd();
//Right Stand
    glBegin(GL_QUADS);
    glColor3ub(15,49,77);
    glVertex2f(55,-60);
    glVertex2f(65,-60);
    glVertex2f(65,-18);
    glVertex2f(55,-18);
    glEnd();

//Bench
    glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2f(-75,-20);
    glVertex2f(75,-20);
    glVertex2f(75,20);
    glVertex2f(-75,20);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700); // Initialize GLUT
    glutCreateWindow("Rectangle"); // Create window with the given title
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register callback handler for window re-paint event
    initGL(); // Our own OpenGL initialization
    gluOrtho2D(-100, 100, -100, 100);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
