#include <glut.h>
#include <stdlib.h>

void  myinit()
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };	 //�ֺ� �ݻ籤 : ������
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };	 // Ȯ�� �ݻ� �Ի籤 : ���
	GLfloat position[] = { 0.0 , 3.0, 2.0, 0.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };	
	GLfloat local_view[] = { 0.0 };

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// ������ ��, ��ġ, ���⿡ ���õ� ���� ����
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0 , GL_POSITION, position);

	// ���� �ֺ��� ����
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glEnable(GL_LIGHTING);	// ���� ��� Ȱ��ȭ
	glEnable(GL_LIGHT0);	// ������ Ȱ��ȭ

	glClearColor(0.0, 0.1, 0.1, 0.0);
}

void display()
{
	// ��ü�� ���� ���� ����
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0};
	GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat no_shininess[] = { 0.0 };
	GLfloat low_shininess[] = { 5.0 };
	GLfloat high_shininess[] = { 100.0 };
	GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* ù ��° �� �� ����
		- ambient : ����
		- diffuse : ����
		- specular : ����
		- shininess : ����
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(-3.75, 3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();
	
	/* �� ��° �� �� ����
		- ambient : ����
		- diffuse : ����
		- specular : ����
		- shininess : ����(low)
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(-1.25, 3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	/* �� ��° �� �� ����
		- ambient : ����
		- diffuse : ����
		- specular : ����
		- shininess : ����(high)
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(1.25, 3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	/* �� ��° �� �� ����
		- ambient : ����
		- diffuse : ����
		- specular : ����
		- shininess : ����
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(3.75, 3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	/* �ټ� ��° �� �� ����
		- ambient : ����
		- diffuse : ����
		- specular : ����
		- shininess : ����
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(-3.75, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	/* ���� ��° �� �� ����
		- ambient : ����
		- diffuse : ����
		- specular : ����
		- shininess : ����(low)
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(-1.25, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	/* �ϰ� ��° �� �� ����
		- ambient : ����
		- diffuse : ����
		- specular : ����
		- shininess : ����(high)
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(1.25, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	/* ���� ��° �� �� ����
		- ambient : ����
		- diffuse : ����
		- specular : ����
		- shininess : ����
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(3.75, 3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	/* ��ȩ ��° �� �� ����
		- ambient : ����(���� �� �ֺ���)
		- diffuse : ����
		- specular : ����
		- shininess : ����
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(-3.75, -3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	/* �� ��° �� �� ����
		- ambient : ����(���� �ִ� �ֺ���)
		- diffuse : ����
		- specular : ����
		- shininess : ����(low)
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(-1.25, -3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	/* ���� ��° �� �� ����
		- ambient : ����(���� �� �ֺ���)
		- diffuse : ����
		- specular : ����
		- shininess : ����(high)
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(1.25, -3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	/* ���� ��° �� �� ����
		- ambient : ����(������ �ִ� �ֺ���)
		- diffuse : ����
		- specular : ����
		- shininess : ����
		- emission : ����
	*/
	glPushMatrix();
	glTranslatef(3.75, -3.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glutSolidSphere(1.0, 16,16);
	glPopMatrix();

	glFlush();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);	//����Ʈ ��ü�� ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// ������ ũ�⿡ ���� ���� ����
	if(w <= (h*2))
		glOrtho(-6.0, 6.0, -3.0*((GLfloat)h*2)/(GLfloat)w,3.0*((GLfloat)h*2)/(GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-6.0*(GLfloat)w/((GLfloat)h*2), 6.0*(GLfloat)w/((GLfloat)h*2), -3.0, 3.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void key(unsigned char k, int x, int y)
{
	switch(k)
	{
	case 27:	// Esc
		exit(0);
		break;
	default:
		return;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 450);
	glutCreateWindow("Materail Property");
	
	myinit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutMainLoop();
	return 0;
}