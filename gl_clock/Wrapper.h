#pragma once
#include "Figure.h"

void setup(void);
void update(void);

void Disp(void);
void Reshape(int, int);
void Timer(int);

int g_window_initial_pos_x = 0;
int g_window_initial_pos_y = 0;
int g_window_initial_width = 480;
int g_window_initial_height = 240;

char* g_application_title = "GLUT application";

inline void setTitle(const char* title)
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
	g_shape_color = codeToRGB(BLACK);
	g_lines_color = codeToRGB(BLACK);
	g_point_color = codeToRGB(BLACK);
	g_clear_color = codeToRGB(WHITE);
	g_shape_color_a = 0xff;
	g_lines_color_a = 0xff;
	g_point_color_a = 0xff;
	g_rotation_angle = 0;
	g_lines_width = 1.0f;
	g_point_size = 1.0f;
	g_rect_align = LEFT_TOP;
	g_circle_align = CENTER;
}

void Disp(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	update();
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
	g_width = glutGet(GLUT_WINDOW_WIDTH);
	g_height = glutGet(GLUT_WINDOW_HEIGHT);
}

void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(16, Timer, 0);
}

void wrapperSystem(int* argc, char** argv)
{
	initParams();
	setup();
	glutInit(argc, argv);
	glutInitWindowPosition(g_window_initial_pos_x, g_window_initial_pos_y);
	glutInitWindowSize(g_window_initial_width, g_window_initial_height);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow(g_application_title);
	glutDisplayFunc(Disp);
	glutReshapeFunc(Reshape);
	glClearColor((unsigned char)g_clear_color.r, (unsigned char)g_clear_color.g, (unsigned char)g_clear_color.b, 255);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutReshapeWindow(g_window_initial_width, g_window_initial_height);

	glutTimerFunc(16, Timer, 0);
	glutMainLoop();
}