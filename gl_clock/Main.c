#include "Figure.h"

void Disp(void);
void Reshape(int, int);
void Timer(int);

void appInit()
{
	g_rotation_angle	= 0;
	g_lines_width		= 1.0f;
	rect_align			= LEFT_TOP;
	circle_align		= CENTER;
	g_shape_color.r		= 0x00;
	g_shape_color.g		= 0x00;
	g_shape_color.b		= 0x00;
	g_shape_color_a		= 0xff;
	g_lines_color.r		= 0x00;
	g_lines_color.g		= 0x00;
	g_lines_color.b		= 0x00;
	g_lines_color_a		= 0xff;
	g_point_color.r		= 0x00;
	g_point_color.g		= 0x00;
	g_point_color.b		= 0x00;
	g_point_color_a		= 0xff;

	g_width = glutGet(GLUT_WINDOW_WIDTH);
	g_height = glutGet(GLUT_WINDOW_HEIGHT);
	glutReshapeWindow(800, 800);
}

void AppUpdate()
{
	setColorRGB(123, 40, 123, TYPE_SHAPE);
	rect(30, 30, 30, 30);
	line(30, 30, 120, 120);
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
	g_width = glutGet(GLUT_WINDOW_WIDTH);
	g_height = glutGet(GLUT_WINDOW_HEIGHT);
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
	glutCreateWindow("GLUT application");
	glutDisplayFunc(Disp);
	glutReshapeFunc(Reshape);
	glClearColor(255, 255, 255, 255);
	appInit();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutTimerFunc(16, Timer, 0);
	glutMainLoop();
	return 0;
}