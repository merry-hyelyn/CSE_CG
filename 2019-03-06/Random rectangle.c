#include <stdlib.h>
#include <glut.h>
#include <time.h>

static int delay = 10;

void display(void)
{
	int x1, x2, y1, y2, r, g, b;

	x1 = rand() % 50; y1 = rand() % 50;
	x2 = rand() % 50; y2 = rand() % 50;
	r = rand() % 250; g = rand() % 250; b = rand() % 250;
	
	glColor3f((GLfloat)r/255, (GLfloat)g/255, (GLfloat)b/255);

	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x1, y2);
	glVertex2f(x2, y2);
	glVertex2f(x2, y1);
	glEnd();

	glFlush();
}

void init(void)
{
	srand(time(0));
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void timer(int t)
{
	glutPostRedisplay();
	glutTimerFunc(delay, timer, t);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("02 랜덤 사각형 그리기");
	glutDisplayFunc(display);
	glutTimerFunc(delay, timer, 0);
	init();
	glutMainLoop();
	return 0;
}