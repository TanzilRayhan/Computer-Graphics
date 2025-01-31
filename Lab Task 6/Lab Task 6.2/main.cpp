#include<windows.h>
#include <GL/freeglut.h>
#include <cmath>

GLfloat bladeRotation = 0.0;//angle speed

void drawBlade() {
    glColor3ub(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.5, 0);
    glVertex2f(-0.05, 0.05);
    glEnd();
}

void display() {
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the background
    glColor3ub(64,64,64);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.6);
    glVertex2f(1.0, -0.6);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glEnd();

    // Pole
    glColor3ub(0,0,0);
    glLineWidth(15);
    glBegin(GL_LINES);
    glVertex2f(0.0, -0.6);
    glVertex2f(0.0, 0.4);
    glEnd();

    // blade rotation
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0.0);
    glRotatef(bladeRotation, 0, 0, 1); //rotation
    for (int i = 0; i < 5; i++) {
        glRotatef(90.0 * i, 0, 0, 1);
        drawBlade();
    }
    glPopMatrix();

    // Circle
    glColor3ub(64,64,64);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i ++) {
        float x = 0.05 * cos(i * M_PI / 180);
        float y = 0.05* sin(i * M_PI / 180);
        glVertex2f(x, y + 0.4);
    }
    glEnd();

    glutSwapBuffers();
    glFlush();
}

void update(int value) {
    bladeRotation += 2.0;
    if (bladeRotation > 360.0) {
        bladeRotation = -360.0;
    }
    glutPostRedisplay();
    glutTimerFunc(12, update, 0);
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Windmill");
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
