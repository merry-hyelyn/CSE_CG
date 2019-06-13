#include <glut.h>
#include <GL/GLU.h>
#include <gl/GL.h>

int year=0;
GLuint TextureObj[11];
static int Time = 0;	//자전
static float Day=0, Day1=0, Day2=0, Day3=0, Day4=0, Day5=0, Day6=0, Day7=0; //공전
GLUquadricObj *sun, *mercury, *venus, *earth, *mars, *jupiter, *saturn, *uranus, *neptune, *moon;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	//glOrtho(-5.0, 5.0, 5.0, 5.0, -5.0, 5.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TextureObj[0]);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	// 다른 이벤트에 영향 받지 않도록 행렬 초기화

	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	// 태양
	glColor3f(1.0, 0.0, 0.0);
	glutWireSphere(1.0, 20, 16);
	
	
	// 수성
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(Day, 0.0, 0.0, 1.0);
	glTranslatef(1.5, 0.0, 0.0);	//태양으로 부터 1.3
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.1, 10, 8);
	glPopMatrix();

	// 금성
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(Day1, 0.0, 0.0, 1.0);
	glTranslatef(2.0, 0.0, 0.0);	//태양으로 부터 0.5
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.25, 10, 8);
	glPopMatrix();
	
	// 지구
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glRotatef(Day2, 0.0, 0.0, 1.0);
	glTranslatef(2.5, 0.0, 0.0);	//태양으로 부터 0.7
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.25, 10, 8);

	// 달은 지구 주위를 공전하기 때문에 지구의 좌표계 이용 따라서 지구 glPopMatrix() 쓰지않음
	// 달
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glTranslatef(0.4, 0.0, 0.0);
	glutWireSphere(0.06, 10, 8);
	glPopMatrix();
	glPopMatrix();	// 지구의 glPopMatrix()

	//화성부터 다시 태양을 기준으로 한 좌표
	//화성
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(Day3, 0.0, 0.0, 1.0);
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.125, 10, 8);
	glPopMatrix();

	//목성
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glRotatef(Day4, 0.0, 0.0, 1.0);
	glTranslatef(4.3, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.125, 10, 8);
	glPopMatrix();

	//토성
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

	//천왕성
	glPushMatrix();
	glColor3f(0.0, 0.5, 0.5);
	glRotatef(Day6, 0.0, 0.0, 1.0);
	glTranslatef(6.3, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.125, 10, 8);
	glPopMatrix();
	
	//해왕성
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(Day7, 0.0, 0.0, 1.0);
	glTranslatef(7.2, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 0.0, 1.0);
	glutWireSphere(0.125, 10, 8);
	glPopMatrix();
	glutSwapBuffers();
}

void timerProcess(int value)
{
	Day = Day + (47.26/10);			//수성
	Day1 = Day1 + (35.02/10);		//금성
	Day2 = Day2 + (29.78/10);		//지구
	Day3 = Day3 + (24.08/10);		//화성
	Day4 = Day4 + (13.06/10);		//목성
	Day5 = Day5 + (9.65/10);		//토성
	Day6 = Day6 + (6.81/10);		//천왕성
	Day7 = Day7 + (5.44/10);		//해

	Time = (Time + 2) % 360;
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)new_w / (GLfloat)new_h,1.0, 20.0);

	gluLookAt(8.0, 8.0, 8.0, 0.0, 0.0, 0.0, 2.0, 1.0, 0.0);

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	/*case 'd':
		day = (day+10)%360;
		break;

	case 'D':
		day = (day-10)%360;
		break;*/

	case 'y':
		year = (year+5)%360;
		break;

	case 'Y':
		year = (year-5)%360;
		break;

	default:
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// 어떠한 버퍼를 쓸 것인지 명시

	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("planet");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(40, timerProcess, 1);
	glutMainLoop();

	return 0;
}