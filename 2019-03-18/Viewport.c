#include <glut.h>
#include <stdlib.h>

void display(void)
{
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 5.0, 0.0);
	glVertex3f(5.0, 15.0, 0.0);
	glVertex3f(15.0, 15.0, 0.0);
	glVertex3f(15.0, 5.0, 0.0);
	glEnd();

	glFlush();
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void reshape(int new_w, int new_h)
{
	float WidthFactor = (float)new_w/250.0;
	float HeightFactor = (float)new_h/ 250.0;

	//����Ʈ�� ȭ�� ��ü�� ����
	glViewport(0, 0 ,new_w, new_h);

	// ����Ʈ�� �� 1��и����� ����
	glViewport(new_w/2, new_h/2, new_w/2, new_h/2);

	// ����Ʈ�� �� 2��и����� ����
	glViewport(0, new_h/2, new_w/2, new_h/2);

	//����Ʈ�� �� 3��и����� ����
	glViewport(0, 0, new_w/2, new_h/2);

	// ����Ʈ�� �� 4��и����� ����
	glViewport(new_w/2, 0, new_w/2, new_h/2);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-5.0*WidthFactor, 5.0 * WidthFactor, -5.0 *HeightFactor, 5.0*HeightFactor);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("01 �簢�� �׸���");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
} 

