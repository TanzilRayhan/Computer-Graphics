#include<windows.h>
#include <GL/freeglut.h>
#include <cmath>

GLfloat bladeRotation =0.0;//angle speed

void drawBlade() {
    glColor3ub(255,255,255);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.012, 0.04);
    glEnd();
}

void display() {
    glClearColor(0.529,0.808,0.922,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the green grass background
    glColor3ub(0,128,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0, -0.6);
    glVertex2f(1.0, -0.6);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glEnd();

    // Draw the road
    glColor3ub(139,69,19);
    glBegin(GL_QUADS);
    glVertex2f(-0.25, -0.6);
    glVertex2f(0.25, -0.6);
    glVertex2f(0.25, -1.0);
    glVertex2f(-0.25, -1.0);
    glEnd();

    // Draw the pole
    glColor3ub(255,255,255);  // White color
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0.0, -0.6);
    glVertex2f(0.0, 0.4); // Adjusted pole height
    glEnd();
    //glLineWidth(1.0);

    //Draw the pole for left windmill

    glColor3ub(255,255,255);  // White color
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(-0.4,-0.6);
    glVertex2f(-0.4, -0.15); // Adjusted pole height
    glEnd();

       glColor3ub(255,255,255);  // White color
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(0.4,-0.6);
    glVertex2f(0.4, 0.1); // Adjusted pole height
    glEnd();

    // Draw the blades with rotation
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0.0);
    glRotatef(bladeRotation, 0, 0, 1); // Apply rotation
    for (int i = 0; i < 10; i++) {
        glRotatef(90.0 * i, 0, 0, 1);
        drawBlade();
    }
    glPopMatrix();
    //left blade with it's rotation
    glPushMatrix();
    glTranslatef(-0.4, -0.15, 0.0);
    glRotatef(bladeRotation, 0, 0, 1); // Apply rotation
    for (int i = 0; i < 15; i++) {
        glRotatef(30.0 * i, 0, 0, 1);
        drawBlade();
    }
    glPopMatrix();

    //right blade with its rotation
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.4, 0.1, 0.0);
    glRotatef(bladeRotation, 0, 0, 1); // Apply rotation
    for (int i = 0; i < 4; i++) {
        glRotatef(90.0 * i, 0, 0, 1);
        drawBlade();
    }
    glPopMatrix();

    // Draw the center of the windmill
    glColor3ub(169,169,169);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i ++) {
        float x = 0.05 * cos(i * M_PI / 180);
        float y = 0.05 * sin(i * M_PI / 180);
        glVertex2f(x, y + 0.4); // Adjusted center height
    }
    glEnd();
    //left circle of the windmill
    glColor3ub(169,169,169);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i ++) {
        float x = 0.05 * cos(i * M_PI / 180);
        float y = 0.05 * sin(i * M_PI / 180);
        glVertex2f(x-0.4, y-0.15); // Adjusted center height
    }
    glEnd();
    //right circle of the windmill
    glColor3ub(169,169,169);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i ++) {
        float x = 0.05 * cos(i * M_PI / 180);
        float y = 0.05 * sin(i * M_PI / 180);
        glVertex2f(x+0.4, y+0.1); // Adjusted center height
    }
    glEnd();
    //sun
    glColor3ub(255,204,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i ++) {
        float x = 0.08 * cos(i * M_PI / 180);
        float y = 0.08 * sin(i * M_PI / 180);
        glVertex2f(x-0.7, y+0.88); // Adjusted center height
    }
    glEnd();

    glutSwapBuffers();
    glFlush();
}

void update(int value) {
    // Update blade rotation angle for animation
    bladeRotation += 3.0; // Adjust the rotation speed
    if (bladeRotation > 360.0) {
        bladeRotation = -360.0;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
    //glutTimerFunc(30,update,25); // 60 FPS
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
    glutTimerFunc(0, update, 0); // Start the animation timer
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
