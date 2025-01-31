#include <GL/glut.h>

GLfloat red = 1.0f, green = 0.0f, blue = 0.0f;

void update(int value) {

    if (red == 1.0f) {
        red = 0.0f;
        green = 1.0f;
        blue = 0.0f;
    } else if (green == 1.0f) {
        red = 0.0f;
        green = 0.0f;
        blue = 1.0f;
    } else {
        red = 1.0f;
        green = 0.0f;
        blue = 0.0f;
    }

    glutPostRedisplay();

    glutTimerFunc(200, update, 0);
}

void drawBox() {
    glColor3f(1.0f - red, 1.0f - green, 1.0f - blue);
    //glColor3ub(0, 0, 102);
    glBegin(GL_QUADS);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.75f, 0.25f);
    glVertex2f(0.75f, 0.75f);
    glVertex2f(0.25f, 0.75f);
    glEnd();
}

void display() {
    glClearColor(red, green, blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    drawBox();
    glutSwapBuffers();

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Background Color Changing Animation");


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);

    glutDisplayFunc(display);
    glutTimerFunc(200, update, 0);

    glutMainLoop();

    return 0;
}
