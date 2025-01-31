#include <GL/freeglut.h>

float bgColor[3] = {0.0, 0.0, 0.2};
float transitionSpeed = 0.01;

void drawScene() {
    glClearColor(bgColor[0], bgColor[1], bgColor[2], 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void update(int value) {
    bgColor[0] -= transitionSpeed;
    bgColor[1] -= transitionSpeed;
    bgColor[2] -= transitionSpeed;
    if (bgColor[0] < 0.0 || bgColor[0] > 1.0) {
        transitionSpeed *= -1;
    }

    drawScene();

    glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Day and Night Scenario");
    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update, 0);

    glutMainLoop();

    return 0;
}
