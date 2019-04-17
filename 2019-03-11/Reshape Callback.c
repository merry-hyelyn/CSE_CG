#include <glut.h>

void display()
{
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);
	glVertex3f(-0.75, -0.75, 0.0);
	glVertex3f(0.75, -0.75, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(-0.75, 0.75, 0.0);
	glEnd();

	glFlush();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void reshape(int new_w, int new_h)
{
	float WidthFactor = (float)new_w/250.0;
	float HeightFactor = (float)new_h/250.0;
	
	glViewport(0, 0, new_w, new_h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-1.0*WidthFactor, 1.0*WidthFactor, -1.0*HeightFactor, 1.0*HeightFactor);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("02 Reshape Callback");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}