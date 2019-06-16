/*
	�ۼ��� : ������
	�ۼ��� : 2019-06-15
	���α׷��� : �¾�� �׸���
*/

#include <glut.h>
#include <GL/GLU.h>
#include <gl/GL.h>
#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"
#include <vector>

int year=10;	// ���� ������ ���߱� ���� ���� ����
static int Time = 0;	// Ÿ�̸� �ݹ��� �̿��Ͽ� ������ ǥ���ϱ� ���� ��������
static float Day=0, Day1=0, Day2=0, Day3=0, Day4=0, Day5=0, Day6=0, Day7=0; //����
GLUquadricObj *sun, *mercury, *venus, *earth, *mars, *jupiter, *saturn,*saturn_ring, *uranus, *neptune, *moon;
GLuint TextureObj[11];	// �ؽ��ĸ� �����ϴ� �迭
float zangle = 0.0, xangle = 0.0 , yangle=0.0;

std::vector<unsigned char> image2;

void loadTexture(GLuint* texture, char* path)
{
	std::vector<unsigned char> image;
	unsigned width, height;
	unsigned error = lodepng::decode(image, width, height, path);
	if (!error)
		printf("Error : %s / %s\n", error, lodepng_error_text(error));
	size_t u2 = 1; while (u2 < width) u2 *= 2;
	size_t v2 = 1; while (v2 < height) v2 *= 2;
	image2 = std::vector<unsigned char>(u2 * v2 * 4);
	for (size_t y = 0; y < height; y++)
		for (size_t x = 0; x < width; x++)
			for (size_t c = 0; c < 4; c++)
			{
				image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
			}
	glGenTextures(1, texture);
	glBindTexture(GL_TEXTURE_2D, *texture);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image2[0]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	// ���� ����
	float lightPosition[4] = { 0.0, 1.0, 1.0, 1.0 };
	float ambient[4] = { 4.0, 4.0, 4.0, 4.0 };
	float specular[4] = {1.0, 1.0, 1.0, 1.0 };
	float diffuse[4] = {1.0, 1.0, 1.0, 1.0};

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// �ؽ��� �о����
	loadTexture(&TextureObj[0], "sun.png");
	loadTexture(&TextureObj[1], "mercury.png");
	loadTexture(&TextureObj[2], "venus.png");
	loadTexture(&TextureObj[3], "earth.png");
	loadTexture(&TextureObj[4], "moon.png");
	loadTexture(&TextureObj[5], "mars.png");
	loadTexture(&TextureObj[6], "jupiter.png");
	loadTexture(&TextureObj[7], "saturn.png");
	loadTexture(&TextureObj[8], "saturn_ring.png");
	loadTexture(&TextureObj[9], "uranus.png");
	loadTexture(&TextureObj[10], "neptune.png");
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(8.0, 8.0, 8.0, 0.0, 0.0, 0.0, 2.0, 1.0, 0.0);
	
	glEnable(GL_DEPTH_TEST);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	// �ٸ� �̺�Ʈ�� ���� ���� �ʵ��� ��� �ʱ�ȭ
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glTranslatef(xangle,yangle,zangle);	// ���� �ܾƿ�, ī�޶� �̵�
	sun = gluNewQuadric();
    mercury = gluNewQuadric();
    venus = gluNewQuadric();
    earth = gluNewQuadric();
    mars = gluNewQuadric();
    jupiter = gluNewQuadric();
    saturn = gluNewQuadric();
    saturn_ring = gluNewQuadric();
    uranus = gluNewQuadric();
    neptune = gluNewQuadric();
    moon = gluNewQuadric();
   
	// �ؽ��� ���� ���
    gluQuadricTexture(sun, GL_TRUE);
    gluQuadricTexture(mercury, GL_TRUE);
    gluQuadricTexture(venus, GL_TRUE);
    gluQuadricTexture(earth, GL_TRUE);
    gluQuadricTexture(mars, GL_TRUE);
    gluQuadricTexture(jupiter, GL_TRUE);
    gluQuadricTexture(saturn, GL_TRUE);
    gluQuadricTexture(saturn_ring, GL_TRUE);
    gluQuadricTexture(uranus, GL_TRUE);
    gluQuadricTexture(neptune, GL_TRUE);
    gluQuadricTexture(moon, GL_TRUE);

	glEnable(GL_TEXTURE_2D);

	// �¾�
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[0]);
	// TextureObj�� ����� �ؽ��ĸ� ����
	gluSphere(sun,1.0, 20, 16);
	
	
	// ����
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(Day, 0.0, 0.0, 1.0);
	glTranslatef(1.5, 0.0, 0.0);	//�¾����� ���� 1.3
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[1]);
	gluSphere(mercury, 0.1, 10, 8);
	glPopMatrix();

	// �ݼ�
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(Day1, 0.0, 0.0, 1.0);
	glTranslatef(2.0, 0.0, 0.0);	//�¾����� ���� 0.5
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[2]);
	gluSphere(venus, 0.25, 10, 8);
	glPopMatrix();
	
	// ����
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glRotatef(Day2, 0.0, 0.0, 1.0);
	glTranslatef(2.5, 0.0, 0.0);	//�¾����� ���� 0.7
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[3]);
	gluSphere(earth, 0.25, 10, 8);

	// ���� ���� ������ �����ϱ� ������ ������ ��ǥ�� �̿� ���� ���� glPopMatrix() ��������
	// ��
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glTranslatef(0.4, 0.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[4]);
	gluSphere(moon, 0.06, 10, 8);
	glPopMatrix();	// ������ ��ǥ�� ��
	glPopMatrix();	// ������ glPopMatrix()

	//ȭ������ �ٽ� �¾��� �������� �� ��ǥ
	//ȭ��
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(Day3, 0.0, 0.0, 1.0);
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[5]);
	gluSphere(mars, 0.125, 10, 8);
	glPopMatrix();

	//��
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glRotatef(Day4, 0.0, 0.0, 1.0);
	glTranslatef(4.3, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[6]);
	gluSphere(jupiter, 0.225, 10, 8);
	glPopMatrix();

	//�伺
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.0);
	glRotatef(Day5, 0.0, 0.0, 1.0);
	glTranslatef(5.5, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[7]);
	gluSphere(saturn, 0.125, 10, 8);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, TextureObj[8]);
	gluDisk(saturn_ring,0.1,0.17,15,8);
	glPopMatrix();
	glPopMatrix();

	//õ�ռ�
	glPushMatrix();
	glColor3f(0.0, 0.5, 0.5);
	glRotatef(Day6, 0.0, 0.0, 1.0);
	glTranslatef(6.3, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[9]);
	gluSphere(uranus, 0.125, 10, 8);
	glPopMatrix();
	
	//�ؿռ�
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(Day7, 0.0, 0.0, 1.0);
	glTranslatef(7.2, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[10]);
	gluSphere(neptune, 0.125, 10, 8);
	glPopMatrix();

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
		xangle += 0.1;
		yangle += 0.1;
		zangle += 0.1;
		break;

	case '-':	// �� �ƿ�
		xangle -= 0.1;
		yangle -= 0.1;
		zangle -= 0.1;
		break;

	default:
		break;
	}
	glutPostRedisplay();
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

	glutInitWindowSize(1000, 800);		// ������ ũ�� ����
	glutInitWindowPosition(0, 0);		// ������ ��ġ ����

	glutCreateWindow("20174016 ������");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);			// Ű���� �̺�Ʈ
	glutSpecialFunc(specialkeyboard);	// ����Ű�� �̿��Ͽ� ī�޶��� ���� �ܾƿ�
	glutTimerFunc(40, timerProcess, 1);	// ������ ������ ���� Ÿ�̸� �ݹ�
	glutMainLoop();

	return 0;
}