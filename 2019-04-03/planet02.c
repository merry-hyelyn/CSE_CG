#include <glut.h>

 

int year =0;

int day = 0;

 

void init()

{

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);

}

 

void display()

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 

	glEnable(GL_DEPTH_TEST);

 

	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0);

	glutSolidSphere(1.0, 20, 16);

 

	glColor3f(1.0, 1.0, 1.0);

	glRotatef(year, 0.0, 1.0, 0.0);

	glTranslatef(2.0, 0.0, 0.0);

	glRotatef(day, 0.0, 1.0, 0.0);

	glutSolidSphere(0.2, 10, 8);

	glPopMatrix();

 

	glutSwapBuffers();

}

 

void reshape(int new_w, int new_h)

{

	glViewport(0,0,new_w, new_h);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	gluPerspective(60.0, (GLfloat)new_w / (GLfloat)new_h,1.0, 20.0);

 

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	gluLookAt(0.0, 0.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

 

	glutPostRedisplay();

}

 

void keyboard(unsigned char key, int x, int y)

{

	switch(key)

	{

	case 'd':

		day = (day+10)%360;

		break;

	case 'D':

		day = (day-10)%360;

		break;

	case 'y':

		year = (year+5)%360;

		break;

	case 'Y':

		year = (year-5)%360;

		break;

	default:

		break;

	}

	glutPostRedisplay();

}

 

int main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

 

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(100, 100);

 

	glutCreateWindow("06_2 planet 실습");

	init();

 

	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;

}