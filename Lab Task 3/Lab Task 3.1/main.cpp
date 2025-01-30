#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	// Building
	glBegin(GL_QUADS);
	glColor3ub(0, 128, 255);
	glVertex2f(-50.0f, -80.0f);
	glVertex2f(50.0f,-80.0f);
	glVertex2f(50.0f, 80.0f);
	glVertex2f(-50.0f, 80.0f);
	glEnd();

	// Door
	glBegin(GL_QUADS);
	glColor3ub(17, 17, 17);
	glVertex2f(-15.0f, -80.0f);
	glVertex2f(15.0f, -80.0f);
	glVertex2f(15.0f, -40.0f);
	glVertex2f(-15.0f, -40.0f);
	glEnd();

	// 1st floor window left
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(-45.0f, -50.0f);
	glVertex2f(-20.0f, -50.0f);
	glVertex2f(-20.0f, -30.0f);
	glVertex2f(-45.0f, -30.0f);
	glEnd();

	// 1st floor window right
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(45.0f, -50.0f);
	glVertex2f(20.0f, -50.0f);
	glVertex2f(20.0f, -30.0f);
	glVertex2f(45.0f, -30.0f);
	glEnd();


	// 2nd floor window left
	glBegin(GL_QUADS);
	glColor3ub(17, 17, 17);
	glVertex2f(-45.0f, -25.0f);
	glVertex2f(-20.0f, -25.0f);
	glVertex2f(-20.0f, -05.0f);
	glVertex2f(-45.0f, -05.0f);
	glEnd();


	// 2nd floor window right
	glBegin(GL_QUADS);
	glColor3ub(17, 17, 17);
	glVertex2f(45.0f, -25.0f);
	glVertex2f(20.0f, -25.0f);
	glVertex2f(20.0f, -05.0f);
	glVertex2f(45.0f, -05.0f);
	glEnd();

    // 3rd floor window left
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(-45.0f, -0.0f);
	glVertex2f(-20.0f, -0.0f);
	glVertex2f(-20.0f, 20.0f);
	glVertex2f(-45.0f, 20.0f);
	glEnd();

	// 3rd floor window right
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(45.0f, -0.0f);
	glVertex2f(20.0f, -0.0f);
	glVertex2f(20.0f, 20.0f);
	glVertex2f(45.0f, 20.0f);
	glEnd();


	// 4th floor window left
	glBegin(GL_QUADS);
	glColor3ub(17, 17, 17);
	glVertex2f(-45.0f, 25.0f);
	glVertex2f(-20.0f, 25.0f);
	glVertex2f(-20.0f, 45.0f);
	glVertex2f(-45.0f, 45.0f);
	glEnd();


	// 4th floor window right
	glBegin(GL_QUADS);
	glColor3ub(17, 17, 17);
	glVertex2f(45.0f, 25.0f);
	glVertex2f(20.0f, 25.0f);
	glVertex2f(20.0f, 45.0f);
	glVertex2f(45.0f, 45.0f);
	glEnd();


    // 5th floor window left
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(-45.0f, 50.0f);
	glVertex2f(-20.0f, 50.0f);
	glVertex2f(-20.0f, 70.0f);
	glVertex2f(-45.0f, 70.0f);
	glEnd();

	// 5th floor window right
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(45.0f, 50.0f);
	glVertex2f(20.0f, 50.0f);
	glVertex2f(20.0f, 70.0f);
	glVertex2f(45.0f, 70.0f);
	glEnd();


	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Five Storied building");
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	initGL();
	gluOrtho2D(-100, 100, -100, 100);
	glutMainLoop();
	return 0;
}
