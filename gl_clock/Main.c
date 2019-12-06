#define _USE_MATH_DEFINES

#include <stdio.h>
#include "Primitive.h"

void Disp(void);
void Reshape(int, int);
void Timer(int);

void AppInit()
{
	rotation_angle		= 0;
	is_draw_outline		= TRUE;
	lines_width			= 1.0f;
	rect_align			= LEFT_TOP;
	circle_align		= CENTER;
	surface_color_r		= 0x00;
	surface_color_g		= 0x00;
	surface_color_b		= 0x00;
	surface_color_a		= 0xff;
	lines_color_r		= 0x00;
	lines_color_g		= 0x00;
	lines_color_b		= 0x00;
	lines_color_a		= 0xff;
	point_color_r		= 0x00;
	point_color_g		= 0x00;
	point_color_b		= 0x00;
	point_color_a		= 0xff;

	window_width = glutGet(GLUT_WINDOW_WIDTH);
	window_height = glutGet(GLUT_WINDOW_HEIGHT);
	glutReshapeWindow(800, 800);
}

int a = 0;
void AppUpdate()
{
	for (int i = 0; i < 9; i++)
	{
		setAlign(TRECT, (Align)i);
		rect((i % 3) * 150 + 100, (i / 3) * 150 + 100, 50, 50);
	}
	rotation_angle += 0.1f;
}

void Disp(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	AppUpdate();
	glutSwapBuffers();
	glFlush();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glScaled(1, -1, 1);
	glTranslated(0, -h, 0);
	window_width = glutGet(GLUT_WINDOW_WIDTH);
	window_height = glutGet(GLUT_WINDOW_HEIGHT);
}

void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(16, Timer, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize(300, 300);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Hello GLUT!!");
	glutDisplayFunc(Disp);
	glutReshapeFunc(Reshape);
	AppInit();
	glClearColor(255, 255, 255, 255);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutTimerFunc(16, Timer, 0);
	glutMainLoop();
	return 0;
}