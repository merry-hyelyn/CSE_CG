#include <glut.h>
#include <stdlib.h>

void  myinit()
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };	 //주변 반사광 : 검정색
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };	 // 확산 반사 입사광 : 흰색
	GLfloat position[] = { 0.0 , 3.0, 2.0, 0.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };	
	GLfloat local_view[] = { 0.0 };

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// 조명의 색, 위치, 방향에 관련된 값들 설정
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0 , GL_POSITION, position);

	// 전역 주변광 설정
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glEnable(GL_LIGHTING);	// 조명 기능 활성화
	glEnable(GL_LIGHT0);	// 광원의 활성화

	glClearColor(0.0, 0.1, 0.1, 0.0);
}

void display()
{
	// 물체의 빛에 대한 정보
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

	/* 첫 번째 구 빛 정보
		- ambient : 없음
		- diffuse : 있음
		- specular : 없음
		- shininess : 없음
		- emission : 없음
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
	
	/* 두 번째 구 빛 정보
		- ambient : 없음
		- diffuse : 있음
		- specular : 있음
		- shininess : 있음(low)
		- emission : 없음
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

	/* 세 번째 구 빛 정보
		- ambient : 없음
		- diffuse : 있음
		- specular : 있음
		- shininess : 있음(high)
		- emission : 없음
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

	/* 네 번째 구 빛 정보
		- ambient : 없음
		- diffuse : 있음
		- specular : 없음
		- shininess : 없음
		- emission : 있음
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

	/* 다섯 번째 구 빛 정보
		- ambient : 있음
		- diffuse : 있음
		- specular : 없음
		- shininess : 없음
		- emission : 없음
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

	/* 여섯 번째 구 빛 정보
		- ambient : 있음
		- diffuse : 있음
		- specular : 있음
		- shininess : 있음(low)
		- emission : 없음
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

	/* 일곱 번째 구 빛 정보
		- ambient : 있음
		- diffuse : 있음
		- specular : 있음
		- shininess : 있음(high)
		- emission : 없음
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

	/* 여덟 번째 구 빛 정보
		- ambient : 있음
		- diffuse : 있음
		- specular : 없음
		- shininess : 없음
		- emission : 있음
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

	/* 아홉 번째 구 빛 정보
		- ambient : 있음(색이 들어간 주변광)
		- diffuse : 있음
		- specular : 없음
		- shininess : 없음
		- emission : 없음
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

	/* 열 번째 구 빛 정보
		- ambient : 있음(색이 있는 주변광)
		- diffuse : 있음
		- specular : 있음
		- shininess : 있음(low)
		- emission : 없음
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

	/* 열한 번째 구 빛 정보
		- ambient : 있음(색이 들어간 주변광)
		- diffuse : 있음
		- specular : 있음
		- shininess : 있음(high)
		- emission : 없음
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

	/* 열두 번째 구 빛 정보
		- ambient : 있음(색깔이 있는 주변광)
		- diffuse : 있음
		- specular : 없음
		- shininess : 없음
		- emission : 있음
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
	glViewport(0, 0, w, h);	//뷰포트 전체로 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// 윈도우 크기에 따른 투영 설정
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