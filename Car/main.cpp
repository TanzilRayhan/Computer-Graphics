#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float bx1 = 00; // Initial position for the second car
float bx2 = 490; // Initial position for the second car

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}


void init(void)
{
    glClearColor(153.0, 204.0, 255, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 0.0, 500); // window size
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Road Border
    glColor3ub(64, 64, 64);
    glBegin(GL_POLYGON);
    glVertex2d(0, 50);
    glVertex2d(500, 50);
    glVertex2d(500, 210);
    glVertex2d(0, 210);
    glEnd();

    // Road
    glColor3ub(128, 128, 128);
    glBegin(GL_POLYGON);
    glVertex2d(0, 60);
    glVertex2d(500, 60);
    glVertex2d(500, 200);
    glVertex2d(0, 200);
    glEnd();

    // Dash
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 125);
    glVertex2d(100, 125);
    glVertex2d(100, 150);
    glVertex2d(0, 150);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(140, 125);
    glVertex2d(240, 125);
    glVertex2d(240, 150);
    glVertex2d(140, 150);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(280, 125);
    glVertex2d(380, 125);
    glVertex2d(380, 150);
    glVertex2d(280, 150);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(420, 125);
    glVertex2d(520, 125);
    glVertex2d(520, 150);
    glVertex2d(420, 150);
    glEnd();

    // Draw the first car
    glPushMatrix();
    glTranslatef(bx1, 0, 0);

    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2d(410, 100);
    glVertex2d(495, 100);
    glVertex2d(485, 130);
    glVertex2d(410, 130);
    glEnd();

    glColor3ub(0, 0, 102);
    glBegin(GL_POLYGON);
    glVertex2d(420, 130);
    glVertex2d(475, 130);
    glVertex2d(465, 160);
    glVertex2d(430, 160);
    glEnd();

    glColor3ub(220, 220, 220);  // window
    glBegin(GL_POLYGON);
    glVertex2d(425, 130);
    glVertex2d(445, 130);
    glVertex2d(445, 150);
    glVertex2d(430, 150);
    glEnd();

    glColor3ub(220, 220, 220);  // window
    glBegin(GL_POLYGON);
    glVertex2d(450, 130);
    glVertex2d(470, 130);
    glVertex2d(465, 150);
    glVertex2d(450, 150);
    glEnd();

    glColor3ub(0, 0, 0);
    circle(10, 14, 435, 100);
    circle(10, 14, 465, 100);

    glColor3ub(245, 245, 245);
    circle(6, 10, 435, 100);
    circle(6, 10, 465, 100);

    glPopMatrix();

    // Draw the second car
    glPushMatrix();
    glTranslatef(bx2, 0, 0);

    glColor3ub(255, 0, 0); // Red color for the second car
    glBegin(GL_POLYGON);
    glVertex2d(405, 180);
    glVertex2d(485, 180);
    glVertex2d(485, 210);
    glVertex2d(410, 210);
    glEnd();

    glColor3ub(102, 0, 0); // Dark red color for the second car
    glBegin(GL_POLYGON);
    glVertex2d(420, 210);
    glVertex2d(475, 210);
    glVertex2d(465, 240);
    glVertex2d(430, 240);
    glEnd();

    glColor3ub(153, 255, 255); // window
    glBegin(GL_POLYGON);
    glVertex2d(425, 210);
    glVertex2d(445, 210);
    glVertex2d(445, 230);
    glVertex2d(430, 230);
    glEnd();

    glColor3ub(153, 255, 255);  // window
    glBegin(GL_POLYGON);
    glVertex2d(450, 210);
    glVertex2d(470, 210);
    glVertex2d(465, 230);
    glVertex2d(450, 230);
    glEnd();



    glColor3ub(0, 0, 0);
    circle(10, 14, 435, 180);
    circle(10, 14, 465, 180);

    glColor3ub(245, 245, 245);
    circle(6, 10, 435, 180);
    circle(6, 10, 465, 180);

    glPopMatrix();

    bx1 += 0.05;
    bx2 -= 0.07;

    if (bx1 > 300)
        bx1 = -500;

    if (bx2 < -500)
        bx2 = 500;

    glutPostRedisplay();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("Car with rotating wheels");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
