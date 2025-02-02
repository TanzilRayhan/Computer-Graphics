#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#define SPACE_KEY 32
#define CHANGE_COLOR_TIMER 2000

struct Bullet {
    float x;
    float y;
    float speed;

    Bullet(float x, float y, float speed) : x(x), y(y), speed(speed) {}
};

struct Spaceship {
    float x;
    float y;
    float width;
    float height;
    float speed;

    Spaceship(float x, float y, float width, float height, float speed) : x(x), y(y), width(width), height(height), speed(speed) {}

    std::vector<Bullet> bullets;
};

Spaceship spaceship(0.0f, -2.0f, 0.2f, 0.2f, 0.05f);

void drawSpaceship() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(spaceship.x - spaceship.width / 2, spaceship.y - spaceship.height / 2);
    glVertex2f(spaceship.x + spaceship.width / 2, spaceship.y - spaceship.height / 2);
    glVertex2f(spaceship.x + spaceship.width / 2, spaceship.y + spaceship.height / 2);
    glVertex2f(spaceship.x - spaceship.width / 2, spaceship.y + spaceship.height / 2);
    glEnd();
}

void drawBullets() {
    glColor3f(1.0f, 0.0f, 0.0f);
    for (const Bullet& bullet : spaceship.bullets) {
        glPointSize(5.5f);
        glBegin(GL_POINTS);
        glVertex2f(bullet.x, bullet.y);
        glEnd();
    }
}

void drawStarField() {
    glColor3ub(255, 255, 255);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < 1000; ++i) {
        float x = static_cast<float>(rand()) / RAND_MAX * 2.0f - 1.0f;
        float y = static_cast<float>(rand()) / RAND_MAX * 4.0f - 2.0f;
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawStarField(); // Draw star field in the background
    drawSpaceship();
    drawBullets();

    glutSwapBuffers();
}

void updateSpace(int value){
    // Change background color every 2000ms
    static int colorChangeTime = 0;
    colorChangeTime += 3;
    if (colorChangeTime > CHANGE_COLOR_TIMER) {
        glClearColor(static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, static_cast<float>(rand()) / RAND_MAX, 1.0f);
        colorChangeTime = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(200, updateSpace, 0);
}


void update(int value) {
    for (Bullet& bullet : spaceship.bullets) {
        bullet.y += bullet.speed;
    }

    spaceship.bullets.erase(std::remove_if(spaceship.bullets.begin(), spaceship.bullets.end(),
                                           [](const Bullet& bullet) { return bullet.y > 2.0f; }),
                            spaceship.bullets.end());

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case SPACE_KEY:
            spaceship.bullets.emplace_back(spaceship.x, spaceship.y + spaceship.height / 2, 0.05f);
            break;
        case 27:
            exit(0);
            break;
    }
}

void special(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            spaceship.x -= spaceship.speed;
            break;
        case GLUT_KEY_RIGHT:
            spaceship.x += spaceship.speed;
            break;
        case GLUT_KEY_UP:
            spaceship.y += spaceship.speed;
            break;
        case GLUT_KEY_DOWN:
            spaceship.y -= spaceship.speed;
            break;
    }
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned>(time(nullptr)));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Bullet Shooting Game");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutTimerFunc(25, update, 0);
    glutTimerFunc(25, updateSpace, 0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);

    glutMainLoop();
    return 0;
}
