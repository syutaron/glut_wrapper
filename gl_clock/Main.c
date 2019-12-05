#define _USE_MATH_DEFINES

#pragma once
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "Colors.h"

#define TRUE 1
#define FALSE 0

int window_width;
int window_height;

// 必要なグローバル変数
// プリミティブの回転角度
float rotation;
float lines_width;
// プリミティブの輪郭の描画有無 (0 : 描画しない、 !0 : 描画)
int is_draw_outline;

// ポリゴンの描画色
GLbyte surface_color_r;
GLbyte surface_color_g;
GLbyte surface_color_b;
GLbyte surface_color_a;
// 線の描画色
GLbyte lines_color_r;
GLbyte lines_color_g;
GLbyte lines_color_b;
GLbyte lines_color_a;
// 点の描画色
GLbyte point_color_r;
GLbyte point_color_g;
GLbyte point_color_b;
GLbyte point_color_a;

void circle(float x, float y, float r);
void rect(float x, float y, float width, float height);
void triangle(float x0, float y0, float x1, float y1, float x2, float y2);
void point(float x, float y);
void line(float x0, float y0, float x1, float y1);

void surfaceAlpha(GLbyte a);
void lineAlpha(GLbyte a);
void setAA(int b);
void setOutlineWidth(float w);

void surfaceColorRGB(GLbyte r, GLbyte g, GLbyte b)
{
	surface_color_r = r;
	surface_color_g = g;
	surface_color_b = b;
}

void surfaceColor(COLOR_CODE code)
{
	RGB col = refColor(code);
	surfaceColorRGB(col.r, col.g, col.b);
}

void outlineColorRGB(GLbyte r, GLbyte g, GLbyte b)
{
	lines_color_r = r;
	lines_color_g = g;
	lines_color_b = b;
}

void outlineColor(COLOR_CODE code)
{
	RGB col = refColor(code);
	outlineColorRGB(col.r, col.g, col.b);
}

void pointColorRGB(GLbyte r, GLbyte g, GLbyte b)
{
	point_color_r = r;
	point_color_g = g;
	point_color_b = b;
}

void pointColor(COLOR_CODE code)
{
	RGB col = refColor(code);
	pointColorRGB(col.r, col.g, col.b);
}

void surfaceAlpha(GLbyte a)
{
	surface_color_a = a;
}

void lineAlpha(GLbyte a)
{
	lines_color_a = a;
}

void pointAlpha(GLbyte a)
{
	point_color_a = a;
}

void setAA(int b)
{
	if (b == TRUE)
	{
		glHint(GL_POLYGON_SMOOTH_HINT, GL_FASTEST);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		// glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
		// glEnable(GL_BLEND);
		// glEnable(GL_POLYGON_SMOOTH);
		glEnable(GL_LINE_SMOOTH);
		glEnable(GL_POINT_SMOOTH);
	}
	else
	{
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glEnable(GL_LINE_SMOOTH);
		glDisable(GL_POLYGON_SMOOTH);
		glDisable(GL_POINT_SMOOTH);
	}
}

void setOutlineWidth(float w)
{
	lines_width = w <= 10.0f ? w : 10.0f;	// 幅は10まで
	glLineWidth(lines_width);
}

void circle(float x, float y, float r)
{
	if (r <= 0.0f) { return; }

	int vertex_count = 100;		// 頂点数
	double delta_theta = M_PI / (double)vertex_count * 2.0;
	double theta = 0;

	// ポリゴン描画
	glColor4ub(surface_color_r, surface_color_g, surface_color_b, surface_color_a);
	glBegin(GL_POLYGON);
	for (int i = 0; i < vertex_count; i++)
	{
		theta += delta_theta;
		glVertex2f(cosf(theta) * (float)r + x, sinf(theta) * (float)r + y);
	}
	glEnd();

	theta = delta_theta;
	double pre_theta = 0;
	for (int i = 0; i < vertex_count; i++)
	{
		theta += delta_theta;
		pre_theta += delta_theta;
		line(cosf(theta) * r + x, sinf(theta) * r + y, cosf(pre_theta) * r + x, sinf(pre_theta) * r + y);
	}
}

void rect(float x, float y, float width, float height)
{
	// 描画
	glColor4ub(surface_color_r, surface_color_g, surface_color_b, surface_color_a);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y);
	glEnd();

	// 輪郭
	line(x, y, x + width, y);
	line(x + width, y, x + width, y + height);
	line(x + width, y + height, x, y + height);
	line(x, y + height, x, y);
}

void triangle(float x0, float y0, float x1, float y1, float x2, float y2)
{
	// 描画
	glColor4ub(surface_color_r, surface_color_g, surface_color_b, surface_color_a);
	glBegin(GL_TRIANGLES);
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();

	// 輪郭
	line(x0, y0, x1, y1);
	line(x1, y1, x2, y2);
	line(x2, y2, x0, y0);
}

void point(float x, float y)
{
	glColor4ub(surface_color_r, surface_color_g, surface_color_b, surface_color_a);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void line_cap(float x, float y, float r)
{
	glPointSize(r * 2.0f);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glPointSize(1.0f);
}

void line(float x0, float y0, float x1, float y1)
{
	glColor4ub(lines_color_r, lines_color_g, lines_color_b, lines_color_a);
	glBegin(GL_LINES);
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glEnd();

	if (lines_width >= 3.0f)
	{
//		line_cap(x0, y0, lines_width / 2.0f);
//		line_cap(x1, y1, lines_width / 2.0f);
	}
}

void Disp();
void Reshape(int, int);
void Timer(int);

void AppInit()
{
	rotation			= 0;
	is_draw_outline		= TRUE;
	lines_width			= 1.0f;
	surface_color_r		= 0xff;
	surface_color_g		= 0xff;
	surface_color_b		= 0xff;
	surface_color_a		= 0xff;
	lines_color_r		= 0x00;
	lines_color_g		= 0x00;
	lines_color_b		= 0x00;
	lines_color_a		= 0xff;

	window_width = glutGet(GLUT_WINDOW_WIDTH);
	window_height = glutGet(GLUT_WINDOW_HEIGHT);
	glutReshapeWindow(600, 320);
}

void AppUpdate()
{
	setAA(TRUE);
	setOutlineWidth(6.0f);
	surfaceColor(SKY_BLUE);
	circle(window_width / 2, window_height / 2, 200);
	surfaceColor(ORANGE);
	rect(50, 50, 200, 200);
	surfaceColor(LIGHT_GRAY);
	triangle(450, 50, 470, 200, 550, 40);
	line(300, 200, 500, 230);
}

void Disp() 
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
	glutTimerFunc(32, Timer, 0);
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

	glutTimerFunc(200, Timer, 0);
	glutMainLoop();
	return 0;
}