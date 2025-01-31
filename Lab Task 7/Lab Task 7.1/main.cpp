#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat position1 = -1.0f;
GLfloat position2 = 1.0f;

void update(int value)
{
    if (position1 < -1.5)
        position1 = 1.0f;
    position1 -= 0.10;

    if (position2 > 1.5)
        position2 = -1.0f;
    position2 += 0.10;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // BOX 1
    glPushMatrix();
    glTranslatef(position1, -0.3f, -0.3f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.03f, -0.2f);
    glVertex2f(0.03f, -0.2f);
    glVertex2f(0.03f, 0.2f);
    glVertex2f(-0.03f, 0.2f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2f, -0.03f);
    glVertex2f(0.2f, -0.03f);
    glVertex2f(0.2f, 0.03f);
    glVertex2f(-0.2f, 0.03f);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.03f, -1.0f);
    glVertex2f(0.03f, -1.0f);
    glVertex2f(0.03f, 1.0f);
    glVertex2f(-0.03f, 1.0f);
    glEnd();

    // BOX 2
    glPushMatrix();
    glTranslatef(position2, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(-0.2f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.03f, -0.2f);
    glVertex2f(0.03f, -0.2f);
    glVertex2f(0.03f, 0.2f);
    glVertex2f(-0.03f, 0.2f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2f, -0.03f);
    glVertex2f(0.2f, -0.03f);
    glVertex2f(0.2f, 0.03f);
    glVertex2f(-0.2f, 0.03f);
    glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(320, 320);
    glutCreateWindow("Moving Box");
    glutDisplayFunc(display);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
    return 0;
}
