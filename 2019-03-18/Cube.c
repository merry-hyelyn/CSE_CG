#include <glut.h>

#include <stdio.h>

#include <stdlib.h>

 

void display()

{

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);

	glLoadIdentity();

 

	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

 

	glScalef(1.0, 1.0, 1.0);

	glutWireCube(2.0);

	glutSwapBuffers();

}

 

void init()

{

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT);

}

 

void reshape(int new_w, int new_h)

{

	glViewport(0,0, new_w, new_h);

	

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

 

	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);

	//1.5 ~ 20 깊이 설정가능

	glMatrixMode(GL_MODELVIEW);

}

 

int main(int argc, char **argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

 

	glutInitWindowSize(250, 250);

	glutInitWindowPosition(100, 100);

 

	glutCreateWindow("03_3 3차원 큐브");

	init();

 

	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutMainLoop();

 

 return 0;

}