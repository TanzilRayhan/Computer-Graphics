#include <GL/glut.h>

const int windowWidth = 400;
const int windowHeight = 600;

void drawTrafficLight() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the outer frame of the traffic light
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2); // Dark gray color for the frame
    glVertex2f(150, 50);
    glVertex2f(250, 50);
    glVertex2f(250, 500);
    glVertex2f(150, 500);
    glEnd();

    // Draw the red light
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0); // Red color
    glVertex2f(175, 450);
    glVertex2f(225, 450);
    glVertex2f(225, 500);
    glVertex2f(175, 500);
    glEnd();

    // Draw the yellow light
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0); // Yellow color
    glVertex2f(175, 350);
    glVertex2f(225, 350);
    glVertex2f(225, 400);
    glVertex2f(175, 400);
    glEnd();

    // Draw the green light
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0); // Green color
    glVertex2f(175, 250);
    glVertex2f(225, 250);
    glVertex2f(225, 300);
    glVertex2f(175, 300);
    glEnd();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Traffic Light");
    glutDisplayFunc(drawTrafficLight);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
