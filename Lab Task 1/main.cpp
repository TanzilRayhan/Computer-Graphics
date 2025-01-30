#include<windows.h>
#include<GL/glut.h>
void display(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

     //this is for rectangle
     glColor3f(1.0,0.0,0.0);
     glBegin(GL_QUADS);
     glVertex2f(-0.7,0.7);
     glVertex2f(-0.2,0.7);
     glVertex2f(-0.2,0.2);
     glVertex2f(-0.7,0.2);
     glEnd();


     //Arrow
     glColor3f(0.0,1.0,0.0);
     glBegin(GL_TRIANGLES);
     glVertex2f(0.5,0.65);
     glVertex2f(0.5,0.3);
     glVertex2f(0.7,0.47);
     glEnd();
     glColor3f(0.0,1.0,0.0);
     glBegin(GL_QUADS);
     glVertex2f(0.1,0.55);
     glVertex2f(0.1,0.4);
     glVertex2f(0.5,0.4);
     glVertex2f(0.5,0.55);
     glEnd();

     //Triangle (violet)
     glColor3ub(127,0,255);
     glBegin(GL_TRIANGLES);
     glVertex2f(-0.2,-0.6);
     glVertex2f(-0.2,-0.3);
     glVertex2f(-0.7,-0.45);
     glEnd();


     //triangle (Yellow)
     glColor3ub(255,255,0);
     glBegin(GL_TRIANGLES);
     glVertex2f(0.4,-0.30);
     glVertex2f(0.2,-0.6);
     glVertex2f(0.6,-0.6);
     glEnd();

     glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(520,520);
    glutCreateWindow("lab_task_1");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

