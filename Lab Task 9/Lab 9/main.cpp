#include <GL/gl.h>
#include <GL/glut.h>

float object1X = 0.0, object1Y = 0.0;
float object2X = 0.0, object2Y = 0.0;
float object3X = 0.0, object3Y = 0.0;
float object4X = 0.0, object4Y = 0.0;

void drawObject(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, 0.2);
    glVertex2f(-0.2, 0.2);
    glEnd();
    glPopMatrix();
}

void update(int value) {
    //right
    object1X += 0.01;
    if (object1X > 1.0) {
        object1X = -1.0;
    }

    //left
    object2X -= 0.01;
    if (object2X < -1.0) {
        object2X = 1.0;
    }

    //upward
    object3Y += 0.01;
    if (object3Y > 1.0) {
        object3Y = -1.0;
    }

    //downward
    object4Y -= 0.01;
    if (object4Y < -1.0) {
        object4Y = 1.0;
    }

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);




    drawObject(object1X, 0.0);
    drawObject(object2X, 0.0);
    drawObject(0.0, object3Y);
    drawObject(0.0, object4Y);
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    glVertex2f(-0.23, -0.23);
    glVertex2f(0.23, -0.23);
    glVertex2f(0.23, 0.23);
    glVertex2f(-0.23, 0.23);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Moving Objects");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}
