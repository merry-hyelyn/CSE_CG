/*
	�ۼ��� : ������
	���α׷��� : �ڵ��� �׸���
	�ۼ��� : 2019-05-12
*/

#include <glut.h>
#include <math.h>
#include <stdlib.h>

GLfloat xangle=0.0, yangle = 0.0, zangle = 0.0;
// ȸ���� ���� ����
GLfloat xt =0.0;
// �ڵ����� ���ư��� �̵��� ���� ����
int wheel_angle=0;
// ���� ȸ�� ����

int count =0;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// ȭ�� �� �ʱ�ȭ
}

void reshape(int new_w, int new_h)
{
	float widthfactor = (float)new_w/250.0;
	float heightfactor = (float)new_h/250.0;

	glViewport(0, 0, new_w, new_h);
	// ����Ʈ�� ��ü�� ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0 * widthfactor, 1.0 * widthfactor, -1.0 * heightfactor, 1.0 * heightfactor);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

// �ڵ��� �׸��� �Լ�
void draw_car()
{
	//*****�� �Ʒ��κп��� �պκ�*****//
	glBegin(GL_QUADS);
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.8, 0.0);
	glVertex3f(-2.0, 0.8, 0.0);

	//*****������ �κ�*****//
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.8, 0.0);
	glVertex3f(2.0, 0.8, -0.8);
	glVertex3f(2.0, 0.0, -0.8);
	
	//*****���� �κ�*****//
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(-2.0, 0.8, 0.0);
	glVertex3f(-2.0, 0.8, -0.8);
	glVertex3f(-2.0, 0.0, -0.8);

	//*****�޺κ�*****//
	glVertex3f(-2.0, 0.0, -0.8);
	glVertex3f(2.0, 0.0, -0.8);
	glVertex3f(2.0, 0.8, -0.8);
	glVertex3f(-2.0, 0.8, -0.8);

	//*****�Ʒ��κ�*****//
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, -0.8);
	glVertex3f(-2.0, 0.0, -0.8);

	glEnd();

	//*****�� ���κп��� �պκ�******//
	glBegin(GL_QUADS);
	glVertex3f(-1.0, 0.8, 0.0);
	glVertex3f(1.15, 0.8, 0.0);
	glVertex3f(1.15, 1.3, 0.0);
	glVertex3f(-1.0, 1.3, 0.0);

	//*****����*****//
	glVertex3f(-1.0, 0.8, 0.0);
	glVertex3f(-1.0, 1.3, 0.0);
	glVertex3f(-1.0, 1.3, -0.4);
	glVertex3f(-1.0, 0.8, -0.4);

	//*****������*****//
	glVertex3f(1.15, 0.8, 0.0);
	glVertex3f(1.15, 1.3, 0.0);
	glVertex3f(1.15, 1.3, -0.4);
	glVertex3f(1.15, 0.8, -0.4);

	//*****�޺κ�*****//
	glVertex3f(1.15, 0.8, -0.4);
	glVertex3f(1.15, 1.3, -0.4);
	glVertex3f(-1.0, 1.3, -0.4);
	glVertex3f(-1.0, 0.8, -0.4);
	glEnd();

	//****����Ʈ*****//
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-2.0, 0.2, 0.0);
	glVertex3f(-2.0, 0.5, 0.0);
	glVertex3f(-2.15, 0.5, 0.0);
	glVertex3f(-2.15, 0.2, 0.0);
	glEnd();
	
	//*****����*****//
	glColor3f(0.0, 0.0, 0.0);
	
	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef(wheel_angle, 0.0, 1.0, 0.0);
	glutSolidTorus(0.07,0.2,10,25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(wheel_angle, 0.0, 1.0, 0.0);
	glutSolidTorus(0.07,0.2,10,25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 0.0, -0.8);
	glRotatef(wheel_angle, 0.0, 1.0, 0.0);
	glutSolidTorus(0.07,0.2,10,25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 0.0, -0.8);
	glRotatef(wheel_angle, 0.0, 1.0, 0.0);
	glutSolidTorus(0.07,0.2,10,25);
	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable(GL_DEPTH_TEST);
	
	glPushMatrix();
	glColor3f(0.0, 0.5, 0.0);
	glTranslatef(xt, 0.0, 0.0);
	// �յڷ� ���ư��� �̵�
	glRotatef(xangle, 1.0, 0.0, 0.0);
	// x�� ȸ��
	glRotatef(yangle, 0.0, 1.0, 0.0);
	// y�� ȸ��
	glRotatef(zangle, 0.0, 0.0, 1.0);
	// z�� ȸ��
	
	draw_car();
	glPopMatrix();

	glutSwapBuffers();
}

void popupMenu(int value)
{
	if(value == 1)
	{

		GLfloat light_position[] = {1.0, 2.0, 3.0, 1.0 };
		GLfloat light_ambient[] = {0.5, 0.5, 0.5, 0.7 };
		GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0 };
		GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0 };

		glClearColor(0.0, 0.0, 0.0, 0.0);

		glLightfv(GL_LIGHT0, GL_POSITION,light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT,light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE,light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR,light_specular);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);
		
		 

		glutPostRedisplay();
	}
}



// Ű���带 ������ �� �߻��ϴ� �̺�Ʈ
void NormalKey(unsigned char key, int x, int y)
{
    switch ( key )    {
    
	  // y������ ȸ��
      case 'y':
        yangle += 1;
        glutPostRedisplay();
        break;

     case 'Y':
        yangle -= 1;
        glutPostRedisplay();
        break;
	  // x ������ ȸ��
		case 'x':
        xangle += 1;
        glutPostRedisplay();
        break;

     case 'X':
        xangle -= 1;
        glutPostRedisplay();
        break;
	  // z ������ ȸ��
		case 'z':
        zangle += 1;
        glutPostRedisplay();
        break;

     case 'Z':
        zangle -= 1;
        glutPostRedisplay();
        break;
	 case 27 : 
		 exit(1);
		 break;
    }

}

static void SpecialKeyFunc(int key, int x, int y)
{
	switch(key)
	{
	// �� Ű�� ������ �� ������ �̵�
	case GLUT_KEY_UP:
		xt -= 0.01;
		glutPostRedisplay();
		break;
	
	// �Ʒ�Ű�� ������ �� �ڷ� �̵�
	case GLUT_KEY_DOWN:
		xt += 0.01;
		glutPostRedisplay();
		break;

	// ������, ���� Ű���带 ������ �� ���� ȸ��
	case GLUT_KEY_RIGHT:
		count++;
		wheel_angle = (wheel_angle + 5) % 360;
		glutPostRedisplay();
		break;

	case GLUT_KEY_LEFT:
		count--;
		wheel_angle = (wheel_angle - 5) % 360;
		glutPostRedisplay();
		break;
	}
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(900, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("�ڵ��� �׸���");

   init();
   glutCreateMenu(popupMenu);
   glutAddMenuEntry("Night",1);
   glutAttachMenu(GLUT_RIGHT_BUTTON);

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(SpecialKeyFunc);
   glutKeyboardFunc(NormalKey);
   
   glutMainLoop();
   return 0;
}