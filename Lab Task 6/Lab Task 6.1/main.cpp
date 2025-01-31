#include <GL/glut.h>
#include <math.h>

GLfloat angle = 45.0f;
GLfloat position = 0.0f;

void Circle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int triangleAmount = 100;

    GLfloat twicePi = 2.0f * 3.1416;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void timer(int val) {
    glutPostRedisplay();
    glutTimerFunc(1, timer, 0);
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2f(0, 100);
        glVertex2f(100, 100);
        glVertex2f(100, 0);
        glVertex2f(0, 0);
    glEnd();

    // Road
    glBegin(GL_QUADS);
        glColor3ub(52,52,52);
        glVertex2f(0, 32);
        glVertex2f(100, 32);
        glVertex2f(100, 0);
        glVertex2f(0, 0);
    glEnd();

    for (int i = 0; i < 100; i += 10) {
        glBegin(GL_QUADS);
            glColor3ub(255, 255, 255);
            glVertex2f(5-2.5+i, 16);
            glVertex2f(10-2.5+i, 16);
            glVertex2f(10-2.5+i, 14);
            glVertex2f(5-2.5+i, 14);
        glEnd();
    }
    glPushMatrix();
    // Car
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 51);
        glVertex2f(30, 22+4);
        glVertex2f(31.5, 28+4);
        glVertex2f(34, 28+4);
        glVertex2f(38, 32+4);

        glVertex2f(44, 32+4);
        glVertex2f(49, 28+4);
        glVertex2f(52, 28+4);
        glVertex2f(55, 22+4);
    glEnd();
    // Windows
    glBegin(GL_QUADS);
        glColor3ub(102, 178, 255);
        glVertex2f(35, 30+2);
        glVertex2f(38, 33+2);
        glVertex2f(39.5, 33+2);
        glVertex2f(39.5, 30+2);
    glEnd();
    glBegin(GL_QUADS);
         glColor3ub(102, 178, 255);
        glVertex2f(40, 33+2);
        glVertex2f(43.8, 33+2);
        glVertex2f(47.5, 30+2);
        glVertex2f(40, 30+2);
    glEnd();

    // Rotation 1
    glPushMatrix();
    glTranslatef(36.5f, 26.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-17.0f, -24.0f, 0.0f);
        // Car - Wheels
        glColor3ub(32, 32, 32);
            Circle(17, 24, 3);
        glColor3ub(246, 241, 238);
            Circle(17, 24, 2.2);
        glBegin(GL_LINES);
            glColor3ub(32, 32, 32);
            glVertex2f(17-2.3, 24);
            glVertex2f(17+2.3, 24);

            glVertex2f(17, 24-2.3);
            glVertex2f(17, 24+2.3);
        glEnd();

    glPopMatrix();
    // Rotation 2

    glTranslatef(46.0f, 26.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-7.0f, -24.0f, 0.0f);
        glColor3ub(32, 32, 32);
            Circle(7, 24, 3);
        glColor3ub(246, 241, 238);
            Circle(7, 24, 2.2);
        glBegin(GL_LINES);
             glColor3ub(32, 32, 32);
            glVertex2f(7-2.3, 24);
            glVertex2f(7+2.3, 24);
            glVertex2f(7, 24-2.3);
            glVertex2f(7, 24+2.3);
        glEnd();
    glPopMatrix();


    position += 0.07;

    if (position > 100)
        position = -500;

    glutPostRedisplay();

    glFlush();
    glLineWidth(4.0f);
    glutSwapBuffers();
    angle -= 0.5;
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(924, 712);
    glutCreateWindow("Car with rotating wheels");
    glutDisplayFunc(Display);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
