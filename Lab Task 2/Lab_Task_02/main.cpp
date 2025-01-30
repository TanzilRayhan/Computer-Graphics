#include <GL/freeglut.h>
#include <cmath>

void drawHexagon(float x, float y, float size) {
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; ++i) {
        float theta = 2.0f * M_PI * (i / 6.0f);
        float nextTheta = 2.0f * M_PI * ((i + 1) / 6.0f);

        float x1 = x + size * cosf(theta);
        float y1 = y + size * sinf(theta);
        float x2 = x + size * cosf(nextTheta);
        float y2 = y + size * sinf(nextTheta);

        glVertex2f(x, y);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawBatmanLogo(float x, float y, float size) {
    float logoSize = size / 2.0f;
    float logoOffsetX = x - logoSize / 2.0f;
    float logoOffsetY = y - logoSize / 2.0f;

    glColor3f(0.0, 0.0, 0.0);  // Set color to black

    // Draw a simple Batman logo using quads
    glBegin(GL_QUADS);
    // Top left
    glVertex2f(logoOffsetX, logoOffsetY + logoSize);
    // Top right
    glVertex2f(logoOffsetX + logoSize, logoOffsetY + logoSize);
    // Bottom right
    glVertex2f(logoOffsetX + logoSize * 0.8, logoOffsetY);
    // Bottom left
    glVertex2f(logoOffsetX + logoSize * 0.2, logoOffsetY);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw hexagon with quads
    glColor3f(1.0, 1.0, 0.0);  // Set color to yellow
    drawHexagon(250, 250, 100);

    // Draw Batman logo inside the hexagon
    drawBatmanLogo(250, 250, 80);

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hexagon with Batman Logo");

    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background color to white

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
