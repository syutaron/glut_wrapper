#include "Figure.h"

#define CIRCLE_VERTEX 100
#define TRUE 1
#define FALSE 0

int g_width;
int g_height;
float g_rotation_angle;
float g_lines_width;

void linesWidth(float w)
{
	if (w <= 0.0f) { return; }
	g_lines_width = w <= 10.0f ? w : 10.0f;	// 幅は10まで
	glLineWidth(g_lines_width);
}

void ratateRad(float radian)
{
	g_rotation_angle = radian;
}

void rotate(float degree)
{
	g_rotation_angle = degree / 180.0f * (float)M_PI;
}

void point(float x, float y)
{
	glPointSize(2.0f);
	glColor4ub(g_point_color.r, g_point_color.g, g_point_color.b, g_point_color_a);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void line(float x0, float y0, float x1, float y1)
{
	glColor4ub(g_lines_color.r, g_lines_color.g, g_lines_color.b, g_lines_color_a);
	glBegin(GL_LINES);
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glEnd();
}

void triangle(float x0, float y0, float x1, float y1, float x2, float y2)
{
	// 描画
	glColor4ub(g_shape_color.r, g_shape_color.g, g_shape_color.b, g_shape_color_a);
	glBegin(GL_TRIANGLES);
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void rect(float x, float y, float width, float height)
{
	float cx[] = { x,	x,				x + width,		x + width };
	float cy[] = { y,	y + height,		y + height,		y };
	translateAlign(cx, cy, 4, rect_align);
	rotateVertex(cx, cy, 4, x, y, g_rotation_angle);

	// 描画
	glColor4ub(g_shape_color.r, g_shape_color.g, g_shape_color.b, g_shape_color_a);
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++)
	{
		glVertex2f(cx[i], cy[i]);
	}
	glEnd();
}

void circle(float x, float y, float r)
{
	float cx[CIRCLE_VERTEX];
	float cy[CIRCLE_VERTEX];

	float delta_theta = (float)M_PI / (float)CIRCLE_VERTEX * 2.0f;
	float theta = 0;

	// 頂点の座標作成
	for (int i = 0; i < CIRCLE_VERTEX; i++)
	{
		theta += delta_theta;
		cx[i] = cosf(theta) * r + x + r;
		cy[i] = sinf(theta) * r + y + r;
	}

	translateAlign(cx, cy, CIRCLE_VERTEX, circle_align);
	rotateVertex(cx, cy, CIRCLE_VERTEX, x, y, g_rotation_angle);

	// ポリゴン描画
	glColor4ub(g_shape_color.r, g_shape_color.g, g_shape_color.b, g_shape_color_a);
	glBegin(GL_POLYGON);
	for (int i = 0; i < CIRCLE_VERTEX; i++)
	{
		glVertex2f(cx[i], cy[i]);
	}
	glEnd();
}

void polygone(float* x, float* y, int n)
{
	glColor4ub(g_lines_color.r, g_lines_color.g, g_lines_color.b, g_lines_color_a);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(x[i], y[i]);
	}
	glEnd();
}