/*
	�ۼ��� : ������
	���α׷��� : ���̵� ����
	�ۼ��� : 2019-05-21
*/

#include <glut.h>
#include <stdlib.h>

void init()
{
	// ��ü ����
	GLfloat mat_ambient[] = { 0.329412, 0.223529, 0.027451 };
	GLfloat mat_diffuse[] = { 0.780392, 0.568627, 0.113725 };
	GLfloat mat_specular[] = { 0.992157, 0.941186, 0.113725 };
	GLfloat mat_shininess[] = { 0.21794872 * 128 };

	// ���� ����
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);	// ���� �� ǥ���� �ε巯�� ����

	// ���� ���� ���� ����
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	// ���� �� ����, light_position�� ���� ��ġ
	glLightfv(GL_FRONT, GL_POSITION, light_position);
	glLightfv(GL_FRONT, GL_AMBIENT, light_ambient);
	glLightfv(GL_FRONT, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_FRONT, GL_SPECULAR, light_specular);

	// ���� ��� Ȱ��ȭ
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glutSolidTeapot(1.0);
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(w<=h)
		glOrtho(-2.0, 2.0, -2.0*(GLfloat)h/(GLfloat)w, 2.0*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.0*(GLfloat)w/(GLfloat)h, 2.0*(GLfloat)w/(GLfloat)h, -2.0, 2.0, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main_menu_select(int value)
{
	switch(value)
	{
	case 1 :
		glShadeModel(GL_FLAT);	// �޴��� Flat Shading�� �����ϸ� �������� ǥ���� �÷� ���̵����� ����
		glutPostRedisplay();	// display �Լ� ��ȣ��
		break;
	case 2:
		glShadeModel(GL_SMOOTH);	// �޴��� Smooth Shading�� �����ϸ� �������� ǥ���� �ε巴�� ���̵��ȴ�
		glutPostRedisplay();
		break;

	case 666:
		exit(0);
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Shading Example");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	// �޴� ����
	glutCreateMenu(main_menu_select);
	glutAddMenuEntry("Flat Shading", 1);
	glutAddMenuEntry("Smooth Shading",2);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
}
