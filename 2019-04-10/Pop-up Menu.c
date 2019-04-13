#include <stdio.h>
#include <glut.h>
#include <stdlib.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0, 0.0, 0.0);
	glFlush();
}

void popupmenu(int value)
{
	switch(value)
	{
	case 1:
		glutSetWindowTitle("ù��° �޴�");
		printf("ù��° �޴��� �����ϼ̽��ϴ�.\n");
		break;

	case 2:
		glutSetWindowTitle("�ι�° �޴�");
		printf("�ι�° �޴��� �����ϼ̽��ϴ�.\n");
		break;
	case 3:
		glutSetWindowTitle("����° �޴�");
		printf("����° �޴��� �����ϼ̽��ϴ�.\n");
		break;
	case 99:
		glutSetWindowTitle("OpenGL���α׷��� �����մϴ�.");
		exit(0);
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("07-1 Pop-up Menu");

	glutCreateMenu(popupmenu);
	glutAddMenuEntry("First",1);
	glutAddMenuEntry("Second",2);
	glutAddMenuEntry("Third",3);
	glutAddMenuEntry("Exit",99);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}