#include <glut.h>

int yangle = 0;
GLfloat xangle=0.0;
GLfloat wheel_x=0.0;

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
	//*****차 아랫부분에서 앞부분*****//
	glBegin(GL_QUADS);
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.8, 0.0);
	glVertex3f(-2.0, 0.8, 0.0);

	//*****오른쪽 부분*****//
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.8, 0.0);
	glVertex3f(2.0, 0.8, -0.8);
	glVertex3f(2.0, 0.0, -0.8);
	
	//*****왼쪽 부분*****//
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(-2.0, 0.8, 0.0);
	glVertex3f(-2.0, 0.8, -0.8);
	glVertex3f(-2.0, 0.0, -0.8);

	//*****뒷부분*****//
	glVertex3f(-2.0, 0.0, -0.8);
	glVertex3f(2.0, 0.0, -0.8);
	glVertex3f(2.0, 0.8, -0.8);
	glVertex3f(-2.0, 0.8, -0.8);
	glEnd();

	//*****차 윗부분에서 앞부분******//
	glBegin(GL_QUADS);
	glVertex3f(-1.0, 0.8, 0.0);
	glVertex3f(1.15, 0.8, 0.0);
	glVertex3f(1.15, 1.3, 0.0);
	glVertex3f(-1.0, 1.3, 0.0);

	//왼쪽
	glVertex3f(-1.0, 0.8, 0.0);
	glVertex3f(-1.0, 1.3, 0.0);
	glVertex3f(-1.0, 1.3, -0.4);
	glVertex3f(-1.0, 0.8, -0.4);

	//오른쪽
	glVertex3f(1.15, 0.8, 0.0);
	glVertex3f(1.15, 1.3, 0.0);
	glVertex3f(1.15, 1.3, -0.4);
	glVertex3f(1.15, 0.8, -0.4);

	//뒤에
	glVertex3f(1.15, 0.8, -0.4);
	glVertex3f(1.15, 1.3, -0.4);
	glVertex3f(-1.0, 1.3, -0.4);
	glVertex3f(-1.0, 0.8, -0.4);
	glEnd();

	//****라이트*****//
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-2.0, 0.2, 0.0);
	glVertex3f(-2.0, 0.5, 0.0);
	glVertex3f(-2.15, 0.5, 0.0);
	glVertex3f(-2.15, 0.2, 0.0);
	glEnd();

	//바퀴
	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef(wheel_x, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glutSolidTorus(0.07,0.2,10,25);

	glTranslatef(1.95, 0.0, 0.0);
	glRotatef(wheel_x, 1.0, 0.0, 0.0);
	glutSolidTorus(0.07,0.2,10,25);
	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable(GL_DEPTH_TEST);

	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(xangle, 0.0, 0.0);
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

static void SpecialKeyFunc(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		xangle += 0.05;
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN:
		xangle -= 0.05;
		glutPostRedisplay();
		break;

	case GLUT_KEY_RIGHT:
	case GLUT_KEY_LEFT:
	}
}

/*void keyboardProcess(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'y': 
		yangle=(yangle + 1) % 360;
		glutPostRedisplay();
		break;
	case 'Y':
		yangle=(yangle - 1 ) % 360;
		glutPostRedisplay();
		break;
	}
	
}*/

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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
   glutSpecialFunc(SpecialKeyFunc);
   //glutMouseFunc(mouseProcess);
   
   glutMainLoop();
   return 0;
}