#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
void initGL()
{
    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
}

const int windowWidth = 700;
const int windowHeight = 700;

void drawCircle(float centerX, float centerY, float radius, int segments, float red, float green, float blue) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(red, green, blue);

    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(segments);
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(centerX + x, centerY + y);
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

//Road
    glBegin(GL_QUADS);
    glColor3ub(29,29,31);
    glVertex2f(-100,-45);
    glVertex2f(100,-45);
    glVertex2f(100,00);
    glVertex2f(-100,00);
    glEnd();
//Cross1
    glBegin(GL_QUADS);
    glColor3ub(255,250,250);
    glVertex2f(-100,-30);
    glVertex2f(-64,-30);
    glVertex2f(-64,-15);
    glVertex2f(-100,-15);
    glEnd();
//Cross2
    glBegin(GL_QUADS);
    glColor3ub(255,250,250);
    glVertex2f(-35,-30);
    glVertex2f(38,-30);
    glVertex2f(38,-15);
    glVertex2f(-35,-15);
    glEnd();
//Cross3
    glBegin(GL_QUADS);
    glColor3ub(255,250,250);
    glVertex2f(100,-30);
    glVertex2f(68,-30);
    glVertex2f(68,-15);
    glVertex2f(100,-15);
    glEnd();

//Road2
    glBegin(GL_QUADS);
    glColor3ub(29,29,31);
    glVertex2f(-30,-40);
    glVertex2f(30,-40);
    glVertex2f(30,-100);
    glVertex2f(-30,-100);
    glEnd();
//Cross1
    glBegin(GL_QUADS);
    glColor3ub(255,250,250);
    glVertex2f(-9,-50);
    glVertex2f(9,-50);
    glVertex2f(9,-100);
    glVertex2f(-9,-100);
    glEnd();


//Sky
    glBegin(GL_QUADS);
    glColor3ub(102,178,255);
    glVertex2f(-100,00);
    glVertex2f(100,00);
    glVertex2f(100,100);
    glVertex2f(-100,100);
    glEnd();


// Building
    glBegin(GL_QUADS);
    glColor3ub(224,224,224);
    glVertex2f(80,00);
    glVertex2f(40,00);
    glVertex2f(40,90);
    glVertex2f(80,90);
    glEnd();
//Door
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2f(55,00);
    glVertex2f(65,00);
    glVertex2f(65,20);
    glVertex2f(55,20);
    glEnd();
//Window ground left
    glBegin(GL_QUADS);
    glColor3ub(80,86,134);
    glVertex2f(53,25);
    glVertex2f(43,25);
    glVertex2f(43,35);
    glVertex2f(53,35);
    glEnd();
//Window ground right
    glBegin(GL_QUADS);
    glColor3ub(80,86,134);
    glVertex2f(77,25);
    glVertex2f(67,25);
    glVertex2f(67,35);
    glVertex2f(77,35);
    glEnd();
//Window 1st left
    glBegin(GL_QUADS);
    glColor3ub(80,86,134);
    glVertex2f(53,40);
    glVertex2f(43,40);
    glVertex2f(43,50);
    glVertex2f(53,50);
    glEnd();
//Window 1st right
    glBegin(GL_QUADS);
    glColor3ub(80,86,134);
    glVertex2f(77,40);
    glVertex2f(67,40);
    glVertex2f(67,50);
    glVertex2f(77,50);
    glEnd();
//Window 2nd left
    glBegin(GL_QUADS);
    glColor3ub(80,86,134);
    glVertex2f(53,55);
    glVertex2f(43,55);
    glVertex2f(43,65);
    glVertex2f(53,65);
    glEnd();
//Window 2nd right
    glBegin(GL_QUADS);
    glColor3ub(80,86,134);
    glVertex2f(77,55);
    glVertex2f(67,55);
    glVertex2f(67,65);
    glVertex2f(77,65);
    glEnd();
//Window 3rd left
    glBegin(GL_QUADS);
    glColor3ub(80,86,134);
    glVertex2f(53,70);
    glVertex2f(43,70);
    glVertex2f(43,80);
    glVertex2f(53,80);
    glEnd();
//Window 3rd right
    glBegin(GL_QUADS);
    glColor3ub(80,86,134);
    glVertex2f(77,70);
    glVertex2f(67,70);
    glVertex2f(67,80);
    glVertex2f(77,80);
    glEnd();
//Window Rooftop
    glBegin(GL_QUADS);
    glColor3ub(80,86,134);
    glVertex2f(83,85);
    glVertex2f(37,85);
    glVertex2f(37,90);
    glVertex2f(83,90);
    glEnd();


// Building2
    glBegin(GL_QUADS);
    glColor3ub(255,255,204);
    glVertex2f(-80,00);
    glVertex2f(-40,00);
    glVertex2f(-40,60);
    glVertex2f(-80,60);
    glEnd();
//Door
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);
    glVertex2f(-55,00);
    glVertex2f(-65,00);
    glVertex2f(-65,20);
    glVertex2f(-55,20);
    glEnd();
//Window ground left
    glBegin(GL_QUADS);
    glColor3ub(102,0,0);
    glVertex2f(-53,25);
    glVertex2f(-43,25);
    glVertex2f(-43,35);
    glVertex2f(-53,35);
    glEnd();
//Window ground right
    glBegin(GL_QUADS);
    glColor3ub(102,0,0);
    glVertex2f(-77,25);
    glVertex2f(-67,25);
    glVertex2f(-67,35);
    glVertex2f(-77,35);
    glEnd();
//Window 1st left
    glBegin(GL_QUADS);
    glColor3ub(102,0,0);
    glVertex2f(-53,40);
    glVertex2f(-43,40);
    glVertex2f(-43,50);
    glVertex2f(-53,50);
    glEnd();
//Window 1st right
    glBegin(GL_QUADS);
    glColor3ub(102,0,0);
    glVertex2f(-77,40);
    glVertex2f(-67,40);
    glVertex2f(-67,50);
    glVertex2f(-77,50);
    glEnd();
//Window Rooftop
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);
    glVertex2f(-83,55);
    glVertex2f(-37,55);
    glVertex2f(-37,60);
    glVertex2f(-83,60);
    glEnd();



//tree
    glBegin(GL_QUADS);
    glColor3ub(237,153,80);
    glVertex2f(-13,00);
    glVertex2f(-20,00);
    glVertex2f(-20,30);
    glVertex2f(-13,30);
    glEnd();
//Leaf 1
    glBegin(GL_TRIANGLES);
    glColor3ub(0,100,0);
    glVertex2f(-03,20);
    glVertex2f(-30,20);
    glVertex2f(-17.5,50);
    glEnd();
//Leaf 2
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2f(-05,30);
    glVertex2f(-29,30);
    glVertex2f(-17.5,60);
    glEnd();



//Traffic Signal
    glBegin(GL_QUADS);
    glColor3ub(64,64,64);
    glVertex2f(25,35);
    glVertex2f(20,35);
    glVertex2f(20,0);
    glVertex2f(25,0);
    glEnd();

    //light
    glBegin(GL_QUADS);
    glColor3ub(32,32,32);
    glVertex2f(15,60);
    glVertex2f(30,60);
    glVertex2f(30,23);
    glVertex2f(15,23);
    glEnd();
     // Draw the red light
    drawCircle(22.5, 53, 4.7, 100, 1.0, 0.0, 0.0);
    // Draw the yellow light
    drawCircle(22.5, 42, 4.7, 100, 1.0, 1.0, 0.0);
    // Draw the green light
    drawCircle(22.5, 31, 4.7, 100, 0.0, 1.0, 0.0);

    glFlush(); // Render now
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Traffic Signal with Building");
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    initGL();
    gluOrtho2D(-100, 100, -100, 100);
    glutMainLoop();
    return 0;
}
