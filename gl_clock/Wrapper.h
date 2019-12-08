#pragma once
#include <stdio.h>
#include "Figure.h"

void Setup(void);
void Update(void);

void disp(void);
void reshape(int, int);
void timer(int);

int g_window_initial_pos_x = 0;
int g_window_initial_pos_y = 0;
int g_window_initial_width = 480;
int g_window_initial_height = 240;
char* g_application_title = "GLUT application";

inline void setTitle(char* title)
{
	g_application_title = title;
}

inline void setWindowSize(int width, int height)
{
	g_window_initial_width = width;
	g_window_initial_height = height;
}

inline void setWindowPos(int x, int y)
{
	g_window_initial_pos_x = x;
	g_window_initial_pos_y = y;
}

void initParams()
{
	setColor(TYPE_SHAPE, BLACK);
	setColor(TYPE_LINE,  BLACK);
	setColor(TYPE_POINT, BLACK);
	setColor(TYPE_CLEAR, BLUE);

	setAlpha(TYPE_SHAPE, 0xff);
	setAlpha(TYPE_LINE,  0xff);
	setAlpha(TYPE_POINT, 0xff);

	rotate(0.0f);
	setLineWidth(1.0f);
	setPointSize(1.0f);

	setAlign(TYPE_RECT, LEFT_TOP);
	setAlign(TYPE_CIRCLE, CENTER);
}

void disp(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	Update();
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glScaled(1, -1, 1);
	glTranslated(0, -h, 0);
	g_width = glutGet(GLUT_WINDOW_WIDTH);
	g_height = glutGet(GLUT_WINDOW_HEIGHT);
}

void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}

void initSystem(int* argc, char** argv)
{
	initParams();
	Setup();
	glutInit(argc, argv);
	glutInitWindowPosition(g_window_initial_pos_x, g_window_initial_pos_y);
	glutInitWindowSize(g_window_initial_width, g_window_initial_height);
	glutCreateWindow(g_application_title);
	glutDisplayFunc(disp);
	glutReshapeFunc(reshape);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	applyClearColor();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutReshapeWindow(g_window_initial_width, g_window_initial_height);
}

int main(int argc, char** argv)
{
	initSystem(&argc, argv);

	glutTimerFunc(16, timer, 0);
	glutMainLoop();
	return 0;
}