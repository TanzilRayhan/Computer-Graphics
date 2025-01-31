#include <GL/freeglut.h>

float bgColorDay[3] = {0.529, 0.808, 0.922};
float bgColorNight[3] = {0.0, 0.0, 0.2};

float* currentBgColor = bgColorDay;

void drawScene() {
    glClearColor(currentBgColor[0], currentBgColor[1], currentBgColor[2], 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void switchToDay() {
    currentBgColor = bgColorDay;
    drawScene();
}

void switchToNight() {
    currentBgColor = bgColorNight;
    drawScene();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'D':
        case 'd':
            switchToDay();
            break;
        case 'N':
        case 'n':
            switchToNight();
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Day and Night Scenario with key");
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
