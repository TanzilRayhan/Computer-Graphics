#include <GL/freeglut.h>
#include <cmath>

int currentObject = 0;

void drawRectangle() {
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.4, -0.4);
    glVertex2f(0.4, -0.4);
    glVertex2f(0.4, 0.4);
    glVertex2f(-0.4, 0.4);
    glEnd();
}

void drawTriangle() {
    glColor3ub(0, 255, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.4);
    glVertex2f(-0.4, -0.4);
    glVertex2f(0.4, -0.4);
    glEnd();
}

void drawCircle() {
    glColor3ub(0, 0, 255);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0);
    for (int i = 0; i <= 360; ++i) {
        float angle = i * 3.1416 / 180;
        glVertex2f(0.4 * cos(angle), 0.4 * sin(angle));
    }
    glEnd();
}

void drawPentagon() {
    glColor3ub(255, 255, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; ++i) {
        float angle = i * (2 * 3.1416 / 5);
        glVertex2f(0.4 * cos(angle), 0.4 * sin(angle));
    }
    glEnd();
}

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (currentObject) {
        case 0:
            drawRectangle();
            break;
        case 1:
            drawTriangle();
            break;
        case 2:
            drawCircle();
            break;
        case 3:
            drawPentagon();
            break;
    }

    glutSwapBuffers();
}

void update(int value) {
    currentObject++;

    if (currentObject > 3) {
        currentObject = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(200, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Separate Object Call");

    glutDisplayFunc(draw);
    glutTimerFunc(20, update, 0);

    glutMainLoop();

    return 0;
}
