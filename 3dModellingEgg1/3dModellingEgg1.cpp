#include "pch.h";
#include <iostream>
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
static GLfloat theta[] = { 0.0, 0.0, 0.0 };
GLfloat u, v;
const int N = 100;
static GLint model = 1;

struct point
{
	GLdouble x;
	GLdouble y;
	GLdouble z;
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

point pointsTable[N][N];

float randFloat()
{
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

void rotate()
{
	for (int i = 0; i < 3; i++)
	{
		theta[i] = theta[i] - 0.1;
		if (theta[i] > 360.0)
			theta[i] -= 360.0;
	}
	glutPostRedisplay();
}
void generateTable()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			u = (double)i / (N - 1);
			v = (double)j / (N - 1);
			pointsTable[i][j].x = (-(90 * pow(u, 5)) + (225 * pow(u, 4)) - (270 * pow(u, 3)) + (180 * pow(u, 2)) - 45 * u) * cos(3.14 * v);
			pointsTable[i][j].y = (160 * pow(u, 4)) - (320 * pow(u, 3)) + (160 * pow(u, 2));
			pointsTable[i][j].z = (-(90 * pow(u, 5)) + (225 * pow(u, 4)) - (270 * pow(u, 3)) + (180 * pow(u, 2)) - 45 * u) * sin(3.14* v);

			pointsTable[i][j].r = randFloat();
			pointsTable[i][j].b = randFloat();
			pointsTable[i][j].g = randFloat();
		}
	}
};
void drawEgg()
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (model == 1)
			{
				glBegin(GL_POINTS);
				glColor3f(pointsTable[i][j].r, pointsTable[i][j].g, pointsTable[i][j].b);
				glVertex3f((float)pointsTable[i][j].x, (float)pointsTable[i][j].y - 5.0f, (float)pointsTable[i][j].z);
				glColor3f(pointsTable[(i + 1) % N][j].r, pointsTable[(i + 1) % N][j].g, pointsTable[(i + 1) % N][j].b);
				glVertex3f((float)pointsTable[(i + 1) % N][j].x, (float)pointsTable[(i + 1) % N][j].y - 5.0f, (float)pointsTable[(i + 1) % N][j].z);
				glColor3f(pointsTable[(i + 1) % N][j].r, pointsTable[(i + 1) % N][j].g, pointsTable[(i + 1) % N][j].b);
				glVertex3f((float)pointsTable[i][(j + 1) % N].x, (float)pointsTable[i][(j + 1) % N].y - 5.0f, (float)pointsTable[i][(j + 1) % N].z);
				glColor3f(pointsTable[(i + 1) % N][(j + 1) % N].r, pointsTable[(i + 1) % N][(j + 1) % N].g, pointsTable[(i + 1) % N][(j + 1) % N].b);
				glVertex3f((float)pointsTable[(i + 1) % N][(j + 1) % N].x, (float)pointsTable[(i + 1) % N][(j + 1) % N].y - 5.0f, (float)pointsTable[(i + 1) % N][(j + 1) % N].z);
				glEnd();

			}

			if (model == 2)
			{
				glBegin(GL_LINE_STRIP);
				glColor3f(pointsTable[i][j].r, pointsTable[i][j].g, pointsTable[i][j].b);
				glVertex3f((float)pointsTable[i][j].x, (float)pointsTable[i][j].y - 5.0f, (float)pointsTable[i][j].z);
				glColor3f(pointsTable[(i + 1) % N][j].r, pointsTable[(i + 1) % N][j].g, pointsTable[(i + 1) % N][j].b);
				glVertex3f((float)pointsTable[(i + 1) % N][j].x, (float)pointsTable[(i + 1) % N][j].y - 5.0f, (float)pointsTable[(i + 1) % N][j].z);
				glColor3f(pointsTable[(i + 1) % N][(j + 1) % N].r, pointsTable[(i + 1) % N][(j + 1) % N].g, pointsTable[(i + 1) % N][(j + 1) % N].b);
				glVertex3f((float)pointsTable[(i + 1) % N][(j + 1) % N].x, (float)pointsTable[(i + 1) % N][(j + 1) % N].y - 5.0f, (float)pointsTable[(i + 1) % N][(j + 1) % N].z);
				glColor3f(pointsTable[i][(j + 1) % N].r, pointsTable[i][(j + 1) % N].g, pointsTable[i][(j + 1) % N].b);
				glVertex3f((float)pointsTable[i][(j + 1) % N].x, (float)pointsTable[i][(j + 1) % N].y - 5.0f, (float)pointsTable[i][(j + 1) % N].z);
				glEnd();
			}
			if (model == 3)
			{
				glBegin(GL_QUADS);
				glColor3f(pointsTable[i][j].r, pointsTable[i][j].g, pointsTable[i][j].b);
				glVertex3f((float)pointsTable[i][j].x, (float)pointsTable[i][j].y - 5.0f, (float)pointsTable[i][j].z);
				glColor3f(pointsTable[(i + 1) % N][j].r, pointsTable[(i + 1) % N][j].g, pointsTable[(i + 1) % N][j].b);
				glVertex3f((float)pointsTable[(i + 1) % N][j].x, (float)pointsTable[(i + 1) % N][j].y - 5.0f, (float)pointsTable[(i + 1) % N][j].z);
				glColor3f(pointsTable[(i + 1) % N][(j + 1) % N].r, pointsTable[(i + 1) % N][(j + 1) % N].g, pointsTable[(i + 1) % N][(j + 1) % N].b);
				glVertex3f((float)pointsTable[(i + 1) % N][(j + 1) % N].x, (float)pointsTable[(i + 1) % N][(j + 1) % N].y - 5.0f, (float)pointsTable[(i + 1) % N][(j + 1) % N].z);
				glColor3f(pointsTable[i][(j + 1) % N].r, pointsTable[i][(j + 1) % N].g, pointsTable[i][(j + 1) % N].b);
				glVertex3f((float)pointsTable[i][(j + 1) % N].x, (float)pointsTable[i][(j + 1) % N].y - 5.0f, (float)pointsTable[i][(j + 1) % N].z);
				glEnd();
			}
		}
	}
}
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	drawEgg();
	glFlush();
	glutSwapBuffers();
}
void keys(unsigned char key, int x, int y)
{
	if (key == 'p') model = 1;
	if (key == 'w') model = 2;
	if (key == 's') model = 3;
	RenderScene();
}
void ChangeSize(GLsizei horizontal, GLsizei vertical) {
	GLfloat AspectRatio;
	if (vertical == 0)
		vertical = 1;
	glViewport(0, 0, horizontal, vertical);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	AspectRatio = (GLfloat)horizontal / (GLfloat)vertical;
	if (horizontal <= vertical)
	{
		glOrtho(-7.5, 7.5, -7.5 / AspectRatio, 7.5 / AspectRatio, 10.0, -10.0);
	}
	else
	{
		glOrtho(-7.5 * AspectRatio, 7.5 * AspectRatio, -7.5, 7.5, 10.0, -10.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MyInit(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	glutInit(&argc, argv);
	generateTable();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Egg");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutIdleFunc(rotate);
	glutKeyboardFunc(keys);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}