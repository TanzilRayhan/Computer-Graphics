#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
void initGL()
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

//Road
    glBegin(GL_QUADS);
    glColor3ub(29,29,31);
    glVertex2f(-100,-30);
    glVertex2f(100,-30);
    glVertex2f(100,00);
    glVertex2f(-100,00);
    glEnd();
//Cross1
    glBegin(GL_QUADS);
    glColor3ub(255,250,250);
    glVertex2f(-100,-20);
    glVertex2f(-54,-20);
    glVertex2f(-54,-10);
    glVertex2f(-100,-10);
    glEnd();
//Cross2
    glBegin(GL_QUADS);
    glColor3ub(255,250,250);
    glVertex2f(-8,-20);
    glVertex2f(38,-20);
    glVertex2f(38,-10);
    glVertex2f(-8,-10);
    glEnd();
//Cross3
    glBegin(GL_QUADS);
    glColor3ub(255,250,250);
    glVertex2f(84,-20);
    glVertex2f(100,-20);
    glVertex2f(100,-10);
    glVertex2f(84,-10);
    glEnd();

//Sky
    glBegin(GL_QUADS);
    glColor3ub(153,204,255);
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



//lamppost
    glBegin(GL_QUADS);
    glColor3ub(15,49,77);
    glVertex2f(20,0);
    glVertex2f(10,0);
    glVertex2f(13,5);
    glVertex2f(17,5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(15,49,77);
    glVertex2f(16,35);
    glVertex2f(14,35);
    glVertex2f(14,5);
    glVertex2f(16,5);
    glEnd();
//light
    glBegin(GL_QUADS);
    glColor3ub(255,252,221);
    glVertex2f(18,45);
    glVertex2f(12,45);
    glVertex2f(12,35);
    glVertex2f(18,35);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(15,49,77);
    glVertex2f(12,45);
    glVertex2f(12,35);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(15,49,77);
    glVertex2f(15,50);
    glVertex2f(15,35);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(15,49,77);
    glVertex2f(18,45);
    glVertex2f(18,35);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(15,49,77);
    glVertex2f(12,35);
    glVertex2f(18,35);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(15,49,77);
    glVertex2f(19,45);
    glVertex2f(11,45);
    glVertex2f(15,50);
    glEnd();

//Left Stand
    glBegin(GL_QUADS);
    glColor3ub(15,49,77);
    glVertex2f(-73,15);
    glVertex2f(-78,15);
    glVertex2f(-78,00);
    glVertex2f(-73,00);
    glEnd();
//Right Stand
    glBegin(GL_QUADS);
    glColor3ub(15,49,77);
    glVertex2f(-48,15);
    glVertex2f(-43,15);
    glVertex2f(-43,00);
    glVertex2f(-48,00);
    glEnd();
//Bench
    glBegin(GL_QUADS);
    glColor3ub(160,82,45);
    glVertex2f(-43,25);
    glVertex2f(-77,25);
    glVertex2f(-85,15);
    glVertex2f(-35,15);
    glEnd();
    //Bench
    glBegin(GL_QUADS);
    glColor3ub(102,51,0);
    glVertex2f(-43,25);
    glVertex2f(-77,25);
    glVertex2f(-77,40);
    glVertex2f(-43,40);
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700); // Initialize GLUT
    glutCreateWindow("Rectangle"); // Create window with the given title
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display); // Register callback handler for window re-paint event
    initGL(); // Our own OpenGL initialization
    gluOrtho2D(-100, 100, -100, 100);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
