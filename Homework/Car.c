#include <glut.h>
#include <stdio.h>
#include <stdlib.h>

void display()
{
	int i =0, j = 0;

	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.2, 0.2, 0.0);
	glVertex3f(0.8, 0.2, 0.0);
	glVertex3f(0.8, 0.4, 0.0);
	glVertex3f(0.2, 0.4, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.4, 0.4, 0.0);
	glVertex3f(0.6, 0.4, 0.0);
	glVertex3f(0.6, 0.6, 0.0);
	glVertex3f(0.4, 0.6, 0.0);
	glEnd();

	//glColor3f(0.0, 1.0, 0.0);
	//glVertex3f( 0.2, 0.4,0.6);
	//glVertex3f(0.6, 0.5,0.6);
	//glVertex3f(0.6, 0.5,0.2);
	//glVertex3f( 0.2,0.4,0.2);

 // /* bottom of cube*/
 // glVertex3f( 0.2,0.4,0.6);
 // glVertex3f(0.6,0.2,0.6);
 // glVertex3f(0.6,0.2,0.2);
 // glVertex3f( 0.2,0.2,0.2);

 // /* front of cube */
 // glVertex3f( 0.2,0.2,0.6);
 // glVertex3f(0.2, 0.4,0.6);
 // glVertex3f(0.2,0.4,0.2);
 // glVertex3f( 0.2,0.2,0.2);

 // /* back of cube.*/
 // glVertex3f(0.6,0.2,0.6);
 // glVertex3f(0.6,0.5,0.6);
 // glVertex3f(0.6,0.5,0.2);
 // glVertex3f( 0.6,0.2,0.2);

 // /* left of cube*/
 // glVertex3f(0.2,0.2,0.6);
 // glVertex3f(0.6,0.2,0.6);
 // glVertex3f(0.6,0.5,0.6);
 // glVertex3f(0.2,0.4,0.6);

 // /* Right of cube */
 // glVertex3f(0.2,0.2,0.2);
 // glVertex3f( 0.6,0.2,0.2);
 // glVertex3f( 0.6,0.5,0.2);
 // glVertex3f( 0.2,0.4,0.2);

	glEnd();
	glFlush();
}

void reshape(int new_w, int new_h)
{
	
	glViewport(0, 0, new_w, new_h);
	//glutPostRedisplay();
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluLookAt(1.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("자동차 그리기");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
