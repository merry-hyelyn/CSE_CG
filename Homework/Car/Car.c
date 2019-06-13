/*
	작성자 : 김혜린
	프로그램명 : 자동차 그리기
	작성일 : 2019-05-12
*/

#include <glut.h>
#include <math.h>
#include <stdlib.h>

GLfloat xangle=0.0, yangle = 0.0, zangle = 0.0;
// 회전을 위한 변수
GLfloat xt =0.0;
// 자동차가 나아가는 이동을 위한 변수
int wheel_angle=0;
// 바퀴 회전 변수

int count =0;

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// 화면 색 초기화
}

void reshape(int new_w, int new_h)
{
	float widthfactor = (float)new_w/250.0;
	float heightfactor = (float)new_h/250.0;

	glViewport(0, 0, new_w, new_h);
	// 뷰포트를 전체로 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0 * widthfactor, 1.0 * widthfactor, -1.0 * heightfactor, 1.0 * heightfactor);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

// 자동차 그리는 함수
void draw_car()
{
	//*****차 아랫부분에서 앞부분*****//
	glBegin(GL_QUADS);
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.8, 0.0);
	glVertex3f(-2.0, 0.8, 0.0);

	//*****오른쪽 부분*****//
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.8, 0.0);
	glVertex3f(2.0, 0.8, -0.8);
	glVertex3f(2.0, 0.0, -0.8);
	
	//*****왼쪽 부분*****//
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(-2.0, 0.8, 0.0);
	glVertex3f(-2.0, 0.8, -0.8);
	glVertex3f(-2.0, 0.0, -0.8);

	//*****뒷부분*****//
	glVertex3f(-2.0, 0.0, -0.8);
	glVertex3f(2.0, 0.0, -0.8);
	glVertex3f(2.0, 0.8, -0.8);
	glVertex3f(-2.0, 0.8, -0.8);

	//*****아랫부분*****//
	glVertex3f(-2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, -0.8);
	glVertex3f(-2.0, 0.0, -0.8);

	glEnd();

	//*****차 윗부분에서 앞부분******//
	glBegin(GL_QUADS);
	glVertex3f(-1.0, 0.8, 0.0);
	glVertex3f(1.15, 0.8, 0.0);
	glVertex3f(1.15, 1.3, 0.0);
	glVertex3f(-1.0, 1.3, 0.0);

	//*****왼쪽*****//
	glVertex3f(-1.0, 0.8, 0.0);
	glVertex3f(-1.0, 1.3, 0.0);
	glVertex3f(-1.0, 1.3, -0.4);
	glVertex3f(-1.0, 0.8, -0.4);

	//*****오른쪽*****//
	glVertex3f(1.15, 0.8, 0.0);
	glVertex3f(1.15, 1.3, 0.0);
	glVertex3f(1.15, 1.3, -0.4);
	glVertex3f(1.15, 0.8, -0.4);

	//*****뒷부분*****//
	glVertex3f(1.15, 0.8, -0.4);
	glVertex3f(1.15, 1.3, -0.4);
	glVertex3f(-1.0, 1.3, -0.4);
	glVertex3f(-1.0, 0.8, -0.4);
	glEnd();

	//****라이트*****//
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-2.0, 0.2, 0.0);
	glVertex3f(-2.0, 0.5, 0.0);
	glVertex3f(-2.15, 0.5, 0.0);
	glVertex3f(-2.15, 0.2, 0.0);
	glEnd();
	
	//*****바퀴*****//
	glColor3f(0.0, 0.0, 0.0);
	
	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef(wheel_angle, 0.0, 1.0, 0.0);
	glutSolidTorus(0.07,0.2,10,25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(wheel_angle, 0.0, 1.0, 0.0);
	glutSolidTorus(0.07,0.2,10,25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 0.0, -0.8);
	glRotatef(wheel_angle, 0.0, 1.0, 0.0);
	glutSolidTorus(0.07,0.2,10,25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 0.0, -0.8);
	glRotatef(wheel_angle, 0.0, 1.0, 0.0);
	glutSolidTorus(0.07,0.2,10,25);
	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable(GL_DEPTH_TEST);
	
	glPushMatrix();
	glColor3f(0.0, 0.5, 0.0);
	glTranslatef(xt, 0.0, 0.0);
	// 앞뒤로 나아가는 이동
	glRotatef(xangle, 1.0, 0.0, 0.0);
	// x축 회전
	glRotatef(yangle, 0.0, 1.0, 0.0);
	// y축 회전
	glRotatef(zangle, 0.0, 0.0, 1.0);
	// z축 회전
	
	draw_car();
	glPopMatrix();

	glutSwapBuffers();
}

void popupMenu(int value)
{
	if(value == 1)
	{

		GLfloat light_position[] = {1.0, 2.0, 3.0, 1.0 };
		GLfloat light_ambient[] = {0.5, 0.5, 0.5, 0.7 };
		GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 0.0 };
		GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0 };

		glClearColor(0.0, 0.0, 0.0, 0.0);

		glLightfv(GL_LIGHT0, GL_POSITION,light_position);
		glLightfv(GL_LIGHT0, GL_AMBIENT,light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE,light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR,light_specular);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);
		
		 

		glutPostRedisplay();
	}
}



// 키보드를 눌렀을 때 발생하는 이벤트
void NormalKey(unsigned char key, int x, int y)
{
    switch ( key )    {
    
	  // y축으로 회전
      case 'y':
        yangle += 1;
        glutPostRedisplay();
        break;

     case 'Y':
        yangle -= 1;
        glutPostRedisplay();
        break;
	  // x 축으로 회전
		case 'x':
        xangle += 1;
        glutPostRedisplay();
        break;

     case 'X':
        xangle -= 1;
        glutPostRedisplay();
        break;
	  // z 축으로 회전
		case 'z':
        zangle += 1;
        glutPostRedisplay();
        break;

     case 'Z':
        zangle -= 1;
        glutPostRedisplay();
        break;
	 case 27 : 
		 exit(1);
		 break;
    }

}

static void SpecialKeyFunc(int key, int x, int y)
{
	switch(key)
	{
	// 윗 키를 눌렀을 때 앞으로 이동
	case GLUT_KEY_UP:
		xt -= 0.01;
		glutPostRedisplay();
		break;
	
	// 아래키를 눌렀을 때 뒤로 이동
	case GLUT_KEY_DOWN:
		xt += 0.01;
		glutPostRedisplay();
		break;

	// 오른쪽, 왼쪽 키보드를 눌렀을 때 바퀴 회전
	case GLUT_KEY_RIGHT:
		count++;
		wheel_angle = (wheel_angle + 5) % 360;
		glutPostRedisplay();
		break;

	case GLUT_KEY_LEFT:
		count--;
		wheel_angle = (wheel_angle - 5) % 360;
		glutPostRedisplay();
		break;
	}
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(900, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("자동차 그리기");

   init();
   glutCreateMenu(popupMenu);
   glutAddMenuEntry("Night",1);
   glutAttachMenu(GLUT_RIGHT_BUTTON);

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(SpecialKeyFunc);
   glutKeyboardFunc(NormalKey);
   
   glutMainLoop();
   return 0;
}