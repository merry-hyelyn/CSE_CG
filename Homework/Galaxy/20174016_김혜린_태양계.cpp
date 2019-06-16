/*
	작성자 : 김혜린
	작성일 : 2019-06-15
	프로그램명 : 태양계 그리기
*/

#include <glut.h>
#include <GL/GLU.h>
#include <gl/GL.h>
#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"
#include <vector>

int year=10;	// 공전 비율을 맞추기 위한 전역 변수
static int Time = 0;	// 타이머 콜백을 이용하여 자전을 표현하기 위한 전역변수
static float Day=0, Day1=0, Day2=0, Day3=0, Day4=0, Day5=0, Day6=0, Day7=0; //공전
GLUquadricObj *sun, *mercury, *venus, *earth, *mars, *jupiter, *saturn,*saturn_ring, *uranus, *neptune, *moon;
GLuint TextureObj[11];	// 텍스쳐를 저장하는 배열
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
	
	// 조명 설정
	float lightPosition[4] = { 0.0, 1.0, 1.0, 1.0 };
	float ambient[4] = { 4.0, 4.0, 4.0, 4.0 };
	float specular[4] = {1.0, 1.0, 1.0, 1.0 };
	float diffuse[4] = {1.0, 1.0, 1.0, 1.0};

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// 텍스쳐 읽어오기
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
	glLoadIdentity();	// 다른 이벤트에 영향 받지 않도록 행렬 초기화
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glTranslatef(xangle,yangle,zangle);	// 줌인 줌아웃, 카메라 이동
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
   
	// 텍스쳐 매핑 사용
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

	// 태양
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[0]);
	// TextureObj에 저장된 텍스쳐를 매핑
	gluSphere(sun,1.0, 20, 16);
	
	
	// 수성
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(Day, 0.0, 0.0, 1.0);
	glTranslatef(1.5, 0.0, 0.0);	//태양으로 부터 1.3
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[1]);
	gluSphere(mercury, 0.1, 10, 8);
	glPopMatrix();

	// 금성
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(Day1, 0.0, 0.0, 1.0);
	glTranslatef(2.0, 0.0, 0.0);	//태양으로 부터 0.5
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[2]);
	gluSphere(venus, 0.25, 10, 8);
	glPopMatrix();
	
	// 지구
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glRotatef(Day2, 0.0, 0.0, 1.0);
	glTranslatef(2.5, 0.0, 0.0);	//태양으로 부터 0.7
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[3]);
	gluSphere(earth, 0.25, 10, 8);

	// 달은 지구 주위를 공전하기 때문에 지구의 좌표계 이용 따라서 지구 glPopMatrix() 쓰지않음
	// 달
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glTranslatef(0.4, 0.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[4]);
	gluSphere(moon, 0.06, 10, 8);
	glPopMatrix();	// 지구의 좌표계 끝
	glPopMatrix();	// 지구의 glPopMatrix()

	//화성부터 다시 태양을 기준으로 한 좌표
	//화성
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(Day3, 0.0, 0.0, 1.0);
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[5]);
	gluSphere(mars, 0.125, 10, 8);
	glPopMatrix();

	//목성
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glRotatef(Day4, 0.0, 0.0, 1.0);
	glTranslatef(4.3, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[6]);
	gluSphere(jupiter, 0.225, 10, 8);
	glPopMatrix();

	//토성
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

	//천왕성
	glPushMatrix();
	glColor3f(0.0, 0.5, 0.5);
	glRotatef(Day6, 0.0, 0.0, 1.0);
	glTranslatef(6.3, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, TextureObj[9]);
	gluSphere(uranus, 0.125, 10, 8);
	glPopMatrix();
	
	//해왕성
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

// 타이머 콜백을 이용하여 자전과 공전을 구현
void timerProcess(int value)
{
	// 각 행성별 자전
	Day = Day + (47.26/year);			//수성
	Day1 = Day1 + (35.02/year);			//금성
	Day2 = Day2 + (29.78/year);			//지구
	Day3 = Day3 + (24.08/year);			//화성
	Day4 = Day4 + (13.06/year);			//목성
	Day5 = Day5 + (9.65/year);			//토성
	Day6 = Day6 + (6.81/year);			//천왕성
	Day7 = Day7 + (5.44/year);			//해왕성/

	// 공전
	Time = (Time + 2) % 360;
	
	// 자전의 회전각을 나타내는 변수가 360보다 크면 360을 빼주므로써 회전각을 설정한다
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
	// 뷰포트 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)new_w / (GLfloat)new_h,1.0, 20.0);

	glutPostRedisplay();
}

//카메라 줌 아웃을 translate를 이용하여 구현
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case '+':	// 줌인
		xangle += 0.1;
		yangle += 0.1;
		zangle += 0.1;
		break;

	case '-':	// 줌 아웃
		xangle -= 0.1;
		yangle -= 0.1;
		zangle -= 0.1;
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

// 공전 속도 조절
// 전역변수 year 값은 실제 공전 값이 빨라 일정 비율로 나누어주는 값일
void specialkeyboard(int key, int x, int y)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		year +=10;	// 공전속도 느려짐
		break;
	case GLUT_KEY_DOWN:
		year -= 10;		// 공전 속도 빨라짐
		if(year==0)		// 나누는 값이 0이면 
			year = 10;	// 원래 값인 10으로 나눔
		break;
	case GLUT_KEY_RIGHT:	// 카메라 이동
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
	// 어떠한 버퍼를 쓸 것인지 명시

	glutInitWindowSize(1000, 800);		// 윈도우 크기 설정
	glutInitWindowPosition(0, 0);		// 윈도우 위치 설정

	glutCreateWindow("20174016 김혜린");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);			// 키보드 이벤트
	glutSpecialFunc(specialkeyboard);	// 방향키를 이용하여 카메라의 줌인 줌아웃
	glutTimerFunc(40, timerProcess, 1);	// 공전과 자전을 위한 타이머 콜백
	glutMainLoop();

	return 0;
}