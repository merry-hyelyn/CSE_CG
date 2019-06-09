#include "Particle.h"
#include <ctime>

CParticle particle;

float tick = 0.01;	//time step

float mass = 1;
CParticle *p = NULL;
int frameCount;
int particleCount;
int currentTime, previousTime;

vector<CParticle> particles;

int n = 0, m = 0;
int x = 0, y = 0;

void Timer(int value)
{
	glutTimerFunc(1, Timer, 0);
	glutPostRedisplay();
}

void CollisionWithFloor(CParticle *p)
{
	if(p->mPos.y < -24)
	{
		p->mVel.y *= -0.5;
		p->mPos.y = -23.99999999;
	}
}

void DrawParticle(CParticle *p, float r, float g, float b)
{
	glPushMatrix();
	glColor4f(r, g, b, 1.0);
	glPointSize(p->mMass);
	glBegin(GL_POINTS);

	glVertex2f(p->mPos.x, p->mPos.y);
	glEnd();
	glPopMatrix();
}
void MyRender()
{
	for (int i = 0; i < particleCount; i++)
	{				
		DrawParticle(&particles[i], 1, 1, 1);
	}
}

void Render()
{
	//draw particle
	MyRender();		

	glutPostRedisplay();
}

void SetForceZero()
{
	for (int i = 0; i < particleCount; ++i)
	{
		p = &particles[i];
		p->SetForce(vec3(0));
	}
}

void ComputeForce()
{
	for (int i = 0; i < particleCount; ++i)
	{
		p = &particles[i];
		p->SetForce(vec3(0, -9.8 * p->mMass, 0)); // Gravity apply
	}
}

void Update(){
	SetForceZero();
	ComputeForce();

	for (int i = 0; i < particleCount; ++i)
	{
		p = &particles[i];
		p->UpdateState(tick);
		CollisionWithFloor(p);
	}

}

void Display()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//position update
	Update();

	//render particles and lines
	Render();

	glutSwapBuffers();
};

void Init()
{
	srand((unsigned int)time(0));

	n = rand() % 88;

	m = rand() % 77;

	printf("%d 개의 파티클 입자 생성\n", n * m);

	particleCount = n*m;

	//랜덤 갯수의 파티클 생성
	//랜덤 위치로 지정(x : -50 ~ 50 | y : -25 ~ 25)
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x = rand() % 101 - 50;			
			y = rand() % 101 - 50;

			particle.SetMass(rand() % 10 + 1);
			particle.SetPos(vec3(x, y, 0));
			
			particles.push_back(particle);
		}
	}
}

void Reshape(int width, int height)
{	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-50, 50, -25, 25, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(1024, 600);
	glutCreateWindow("Particle System");

	Init();

	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	//glutTimerFunc(1, Timer, 0);

	glutMainLoop();
	return 0;
}

