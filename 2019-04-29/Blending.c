#include <glut.h>
#include <stdlib.h>

// blending = 여러 물체를 겹쳐 그릴 때 사용

static int leftFirst = GL_TRUE;
float alpha = 0.5;

void init()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// SRC = source 먼저 들어온
	// ONE MINUS 하나빼라 1.0빼라(1.0-0.5)
	// 처음은 alpha = 0.5

	glShadeModel(GL_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void drawLeftSquare()
{
	glColor4f(1.0, 0.0, 0.0, alpha);
	glBegin(GL_POLYGON);
	glVertex3f(-0.6, -0.75, 0.0);
	glVertex3f(0.0, -0.75, 0.0);
	glVertex3f(0.0, 0.75, 0.0);
	glVertex3f(-0.6, 0.75, 0.0);
	glEnd();
}

void drawRightSquare()
{
	glColor4f(0.0, 0.0, 1.0, alpha);
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, -0.75, 0.0);
	glVertex3f(0.5, -0.75, 0.0);
	glVertex3f(0.5, 0.75, 0.0);
	glVertex3f(-0.1, 0.75, 0.0);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(leftFirst)
	{
		drawLeftSquare();
		drawRightSquare();
	}

	else
	{
		drawRightSquare();
		drawLeftSquare();
	}
	glFlush();
}

void reshape(int new_w, int new_h)
{
	glViewport(0, 0, new_w, new_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 't':
	case 'T':
		leftFirst = !leftFirst;
		glutPostRedisplay();
		break;

	case 'a':
		if(alpha>0) alpha -= 0.01;
		else alpha = 0.9;
		glutPostRedisplay();
		break;

	case 27:
		exit(0);
	default:
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("08_1 Alpha Blending");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}