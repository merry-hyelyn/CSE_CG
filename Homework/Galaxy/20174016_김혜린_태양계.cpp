/*
	�ۼ��� : ������
	�ۼ��� : 2019-06-15
	���α׷��� : �¾�� �׸���
*/

#include <glut.h>
#include <GL/GLU.h>
#include <gl/GL.h>
#include <stdio.h>

int year=10;	// ���� ������ ���߱� ���� ���� ����
static int Time = 0;	// Ÿ�̸� �ݹ��� �̿��Ͽ� ������ ǥ���ϱ� ���� ��������
static float Day=0, Day1=0, Day2=0, Day3=0, Day4=0, Day5=0, Day6=0, Day7=0; //����
GLUquadricObj *sun, *mercury, *venus, *earth, *mars, *jupiter, *saturn, *uranus, *neptune, *moon;
GLuint TextureObj[11];	// �ؽ��ĸ� �����ϴ� �迭
float angle = 0.0;	// ī�޶� ��, �ƿ��� �ϴ� ��������
float zangle = 0.0, xangle = 0.0;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
}

void planet()
{
	// �¾�
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glutWireSphere(1.0, 20, 16);
	
	
	// ����
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(Day, 0.0, 0.0, 1.0);
	glTranslatef(1.5, 0.0, 0.0);	//�¾����� ���� 1.3
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.1, 10, 8);
	glPopMatrix();

	// �ݼ�
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(Day1, 0.0, 0.0, 1.0);
	glTranslatef(2.0, 0.0, 0.0);	//�¾����� ���� 0.5
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.25, 10, 8);
	glPopMatrix();
	
	// ����
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glRotatef(Day2, 0.0, 0.0, 1.0);
	glTranslatef(2.5, 0.0, 0.0);	//�¾����� ���� 0.7
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.25, 10, 8);

	// ���� ���� ������ �����ϱ� ������ ������ ��ǥ�� �̿� ���� ���� glPopMatrix() ��������
	// ��
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glTranslatef(0.4, 0.0, 0.0);
	glutWireSphere(0.06, 10, 8);
	glPopMatrix();	// ������ ��ǥ�� ��
	glPopMatrix();	// ������ glPopMatrix()

	//ȭ������ �ٽ� �¾��� �������� �� ��ǥ
	//ȭ��
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(Day3, 0.0, 0.0, 1.0);
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.125, 10, 8);
	glPopMatrix();

	//��
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glRotatef(Day4, 0.0, 0.0, 1.0);
	glTranslatef(4.3, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.125, 10, 8);
	glPopMatrix();

	//�伺
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.0);
	glRotatef(Day5, 0.0, 0.0, 1.0);
	glTranslatef(5.5, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.125, 10, 8);
	glPushMatrix();
	glutWireTorus(0.17,0.1,10,8);
	glPopMatrix();
	glPopMatrix();

	//õ�ռ�
	glPushMatrix();
	glColor3f(0.0, 0.5, 0.5);
	glRotatef(Day6, 0.0, 0.0, 1.0);
	glTranslatef(6.3, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.125, 10, 8);
	glPopMatrix();
	
	//�ؿռ�
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(Day7, 0.0, 0.0, 1.0);
	glTranslatef(7.2, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.125, 10, 8);
	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(8.0, 8.0, 8.0, 0.0, 0.0, 0.0, 2.0, 1.0, 0.0);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureObj[0]);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	// �ٸ� �̺�Ʈ�� ���� ���� �ʵ��� ��� �ʱ�ȭ

	glTranslatef(angle,angle,angle);	// ���� �ܾƿ�
	//glTranslatef(zangle,0.0, 0.0);
	planet();	// �༺���� �׸��� �Լ�
	glutSwapBuffers();
}

// Ÿ�̸� �ݹ��� �̿��Ͽ� ������ ������ ����
void timerProcess(int value)
{
	// �� �༺�� ����
	Day = Day + (47.26/year);			//����
	Day1 = Day1 + (35.02/year);			//�ݼ�
	Day2 = Day2 + (29.78/year);			//����
	Day3 = Day3 + (24.08/year);			//ȭ��
	Day4 = Day4 + (13.06/year);			//��
	Day5 = Day5 + (9.65/year);			//�伺
	Day6 = Day6 + (6.81/year);			//õ�ռ�
	Day7 = Day7 + (5.44/year);			//�ؿռ�/

	// ����
	Time = (Time + 2) % 360;
	
	// ������ ȸ������ ��Ÿ���� ������ 360���� ũ�� 360�� ���ֹǷν� ȸ������ �����Ѵ�
	if(Day > 360) Day -= 360;
	if(Day1 > 360) Day -= 360;
	if(Day2 > 360) Day -= 360;
	if(Day3 > 360) Day -= 360;
	if(Day4 > 360) Day -= 360;
	if(Day5 > 360) Day -= 360;
	if(Day6 > 360) Day -= 360;
	if(Day7 > 360) Day -= 360;

	glutPostRedisplay();
	glutTimerFunc(40,timerProcess,1);
}

void reshape(int new_w, int new_h)
{
	glViewport(0,0,new_w, new_h);
	// ����Ʈ ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)new_w / (GLfloat)new_h,1.0, 20.0);

	glutPostRedisplay();
}

//ī�޶� �� �ƿ��� translate�� �̿��Ͽ� ����
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case '+':	// ����
		angle += 0.1;
		glutPostRedisplay();
		break;

	case '-':	// �� �ƿ�
		angle -= 0.1;
		glutPostRedisplay();
		break;

	default:
		break;
	}
}

// ���� �ӵ� ����
// �������� year ���� ���� ���� ���� ���� ���� ������ �������ִ� ����
void specialkeyboard(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		year +=10;	// �����ӵ� ������
		break;
	case GLUT_KEY_DOWN:
		year -= 10;		// ���� �ӵ� ������
		if(year==0)		// ������ ���� 0�̸� 
			year = 10;	// ���� ���� 10���� ����
		break;
	case GLUT_KEY_RIGHT:	// ī�޶� �̵�
		zangle += 0.1;
		xangle += 0.5;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		zangle -= 0.1;
		xangle -= 0.5;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// ��� ���۸� �� ������ ���

	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("20174016 ������");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeyboard);
	glutTimerFunc(40, timerProcess, 1);
	glutMainLoop();

	return 0;
}