#include <glut.h>
#include <stdio.h>

GLfloat position[] = { 0.0, 4.5, 0.0, 1.0 };

void init()
{
	GLfloat light_ambient[] = {0.1, 0.1, 0.1, 1.0 };
	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glLightfv(GL_LIGHT0, GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR,light_specular);

	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.001);	
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.004);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glTranslatef(position[0], position[1], position[2]);
	glDisable(GL_LIGHTING);
	glColor3f(0.0, 1.0, 1.0);
	glutWireCube(0.5);

	glEnable(GL_LIGHTING);
	glPopMatrix();

	glutSolidTeapot(1.0);
	glFlush();
}

void reshape(int new_w, int new_h)
{
	glViewport(0, 0, new_w, new_h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0*(GLfloat)new_h / (GLfloat) new_w, 5.0*(GLfloat)new_w / (GLfloat)new_h, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state == GLUT_DOWN)
		{
			position[1] -= 0.05;
			printf("Light Postion : (%0.21f, %0.21f, %0.21f)\n",position[0], position[1], position[2]);
		}
		break;

	case GLUT_RIGHT_BUTTON:
		if(state == GLUT_DOWN)
		{
			position[1] += 0.05;
			printf("Light Postion : (%0.21f, %0.21f, %0.21f)\n",position[0], position[1], position[2]);
		}
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("08_3 Moving Lighting Example");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}