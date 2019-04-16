#include <glut.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat MyVertices[8][3]= 
{
	{ -0.25, -0.25, 0.25 },
	{ -0.25, 0.25, 0.25 },
	{ 0.25, 0.25, 0.25 },
	{ 0.25, -0.25, 0.25 },
	{ -0.25, -0.25, -0.25 },
	{ -0.25, 0.25, -0.25 },
	{ 0.25, 0.25, -0.25 },
	{ 0.25, -0.25, -0.25 }
};

GLfloat MyColors[8][3] = 
{
	{ 0.2, 0.2, 0.2 },
	{ 1.0, 0.0, 0.0 },
	{ 1.0, 1.0, 0.0 },
	{ 0.0, 1.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ 1.0, 0.0, 1.0 },
	{ 1.0, 1.0, 1.0 },
	{ 0.0, 1.0, 1.0 }
};

GLbyte MyVertexList[6][4] = 
{
	{ 0, 3, 2, 1 },
	{ 2, 3, 7, 6},
	{0,4,7,3},
	{ 1,2,6,5 },
	{ 4,5,6,7 },
	{ 0,1,5,4 },
};

void display()
{
	int i =0, j = 0;

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(1.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_CULL_FACE);

	for(i=0; i< 6; i++)
	{
		glBegin(GL_POLYGON);
		for(j=0;j<4;j++)
		{
			glColor3fv(MyColors[MyVertexList[i][j]]);
			glVertex3fv(MyVertices[MyVertexList[i][j]]);
		}
		glEnd();
	}
	glFlush();
}

void reshape(int new_w, int new_h)
{
	glViewport(0, 0, new_w, new_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)new_w/(GLfloat)new_h, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("07_2 RGB Color Cube");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}


