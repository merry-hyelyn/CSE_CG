#include <glut.h>
float yangle = 0;
//int yangle = 0;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void reshape(int new_w, int new_h)
{
	float widthfactor = (float)new_w/250.0;
	float heightfactor = (float)new_h/250.0;

	glViewport(0, 0, new_w, new_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(45.0, (GLfloat)new_w/new_h, 0.1, 100.0);
	gluOrtho2D(-1.0 * widthfactor, 1.0 * widthfactor, -1.0 * heightfactor, 1.0 * heightfactor);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void draw_car()
{
	glBegin(GL_QUADS);
	glVertex3f( 0.6, 0.5,0.6);
	glVertex3f(0.6, 0.2,0.6);
	glVertex3f(1.8, 0.2, 0.6);
	glVertex3f(1.8,0.5,0.6);

	/* bottom of cube*/
	glVertex3f( 0.6,0.2,0.6);
	glVertex3f(0.6,0.2,0.2);
	glVertex3f(1.8,0.2,0.2);
	glVertex3f( 1.8,0.2,0.6);

	/* back of cube.*/
	glVertex3f(0.6,0.5,0.2);
	glVertex3f(0.6,0.2,0.2);
	glVertex3f(1.8,0.2,0.2);
	glVertex3f(1.8,0.5,0.2);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);
	glRotatef(yangle, 0.0, 1.0, 0.0);
	draw_car();

	glutSwapBuffers();
}

void popupMenu(int value)
{
	if(value == 1)
	{
		// 여기다가 night 코딩
		glutPostRedisplay();
	}
}
void keyboardProcess(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'y': 
		yangle = (yangle + 5.0) % 360;
		break;
	case 'Y':
		yangle = (yangle - 5.0 ) % 360;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(900, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("자동차 그리기");

   init();
   glutCreateMenu(popupMenu);
   glutAddMenuEntry("Night",1);
   glutAttachMenu(GLUT_RIGHT_BUTTON);

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboardProcess);
   //glutMouseFunc(mouseProcess);
   
   glutMainLoop();
   return 0;
}