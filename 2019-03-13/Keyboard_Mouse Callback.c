#include <glut.h>
#include <stdio.h>

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void display()
{
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glEnd();

	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case '1':
		printf("���� 1Ű�� �Է��Ͽ����ϴ�.\n");
		break;
	case '2':
		printf("���� 2Ű�� �Է��Ͽ����ϴ�.\n");
		break;
	case '5':
		printf("���� 5Ű�� �Է��Ͽ����ϴ�.\n");
		break;
	case 'Q':
		printf("QŰ�� �Է��Ͽ����ϴ�.\n");
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("���� ���콺 ��ư�� Ŭ���ϼ̽��ϴ�.\n");
	}

	else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		printf("��� ���콺 ��ư�� Ŭ���ϼ̽��ϴ�.\n");
	}

	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		printf("������ ���콺 ��ư�� Ŭ���ϼ̽��ϴ�.\n");
	}

	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		printf("���� ���콺 ��ư�� �ý��ϴ�.\n");
	}

	else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
	{
		printf("��� ���콺 ��ư�� �ý��ϴ�.\n");
	}

	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		printf("������ ���콺 ��ư�� �ý��ϴ�.\n");
	}	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100 ,100);
	glutCreateWindow("Keyboard/Mouse Callback");

	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;
}