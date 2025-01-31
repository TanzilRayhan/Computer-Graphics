#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLfloat position = 0.0f;  // Initial position for the car
GLfloat wheelRotation = 0.0f;  // Initial rotation for the wheels

void wheel(GLfloat cx, GLfloat cy, GLfloat r, GLint num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void wheelRims(GLfloat cx, GLfloat cy, GLfloat size) {
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(cx - size, cy);
    glVertex2f(cx + size, cy);
    glVertex2f(cx, cy - size);
    glVertex2f(cx, cy + size);
    glEnd();
    glLineWidth(1.0);
}

void init(void) {
    glClearColor(153.0, 204.0, 255, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 0.0, 500);  // window size
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Road Border
    glColor3ub(64, 64, 64);
    glBegin(GL_POLYGON);
    glVertex2d(0, 50);
    glVertex2d(500, 50);
    glVertex2d(500, 210);
    glVertex2d(0, 210);
    glEnd();

    // Road
    glColor3ub(128, 128, 128);
    glBegin(GL_POLYGON);
    glVertex2d(0, 60);
    glVertex2d(500, 60);
    glVertex2d(500, 200);
    glVertex2d(0, 200);
    glEnd();

    // Dash
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 125);
    glVertex2d(100, 125);
    glVertex2d(100, 150);
    glVertex2d(0, 150);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(140, 125);
    glVertex2d(240, 125);
    glVertex2d(240, 150);
    glVertex2d(140, 150);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(280, 125);
    glVertex2d(380, 125);
    glVertex2d(380, 150);
    glVertex2d(280, 150);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(420, 125);
    glVertex2d(520, 125);
    glVertex2d(520, 150);
    glVertex2d(420, 150);
    glEnd();

    // Draw the car
    glPushMatrix();
    glTranslatef(position, 0, 0);

    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2d(407, 100);
    glVertex2d(495, 100);
    glVertex2d(485, 130);
    glVertex2d(410, 130);
    glEnd();

    glColor3ub(0, 0, 102);
    glBegin(GL_POLYGON);
    glVertex2d(420, 130);
    glVertex2d(475, 130);
    glVertex2d(465, 160);
    glVertex2d(430, 160);
    glEnd();

    glColor3ub(220, 220, 220);  //car window
    glBegin(GL_POLYGON);
    glVertex2d(425, 130);
    glVertex2d(445, 130);
    glVertex2d(445, 150);
    glVertex2d(430, 150);
    glEnd();

    glColor3ub(220, 220, 220);  //car window
    glBegin(GL_POLYGON);
    glVertex2d(450, 130);
    glVertex2d(470, 130);
    glVertex2d(465, 150);
    glVertex2d(450, 150);
    glEnd();

    glPopMatrix();

    //the wheels with rotation
    glPushMatrix();
    glTranslatef(position, 0, 0);

    glPushMatrix();
    glTranslatef(430, 100, 0);
    glRotatef(wheelRotation, 0, 0, 1);  // Rotate the wheel
    glColor3ub(0, 0, 0);
    wheel(0, 0, 14, 100);
    glColor3ub(245, 245, 245);
    wheel(0, 0, 8, 100);
    glColor3ub(0, 0, 0);
    wheelRims(0, 0, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470, 100, 0);
    glRotatef(wheelRotation, 0, 0, 1);  // Rotate the wheel
    glColor3ub(0, 0, 0);
    wheel(0, 0, 14, 100);
    glColor3ub(245, 245, 245);
    wheel(0, 0, 8, 100);
    glColor3ub(0, 0, 0);
    wheelRims(0, 0, 10);
    glPopMatrix();

    glPopMatrix();

    position += 0.05;
    wheelRotation -= 0.1;
    if (position > 100)
        position = -500;

    glutPostRedisplay();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("Moving Car with rotating wheels");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
