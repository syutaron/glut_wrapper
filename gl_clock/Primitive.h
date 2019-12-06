#pragma once
#include <math.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "Colors.h"
#include "Constants.h"

#define CIRCLE_VERTEX 100

#define TRUE 1
#define FALSE 0

int window_width;
int window_height;

// 必要なグローバル変数
// プリミティブの回転角度(ラジアン)
float rotation_angle;
float lines_width;
// プリミティブの輪郭の描画有無 (0 : 描画しない、 !0 : 描画)
int is_draw_outline;

void linesWidth(float w)
{
	if (w <= 0.0f) { return; }
	lines_width = w <= 10.0f ? w : 10.0f;	// 幅は10まで
	glLineWidth(lines_width);
}

void ratateRad(float radian)
{
	rotation_angle = radian;
}

void rotate(float degree)
{
	rotation_angle = degree / 180.0f * (float)M_PI;
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

	// ポリゴン描画
	glColor4ub(surface_color_r, surface_color_g, surface_color_b, surface_color_a);
	glBegin(GL_POLYGON);
	for (int i = 0; i < CIRCLE_VERTEX; i++)
	{
		glVertex2f(cx[i], cy[i]);
	}
	glEnd();
}

void rect(float x, float y, float width, float height)
{
	float cx[] = { x,	x,				x + width,		x + width };
	float cy[] = { y,	y + height,		y + height,		y };

	translateAlign(cx, cy, 4, rect_align);
	rotateVertex(cx, cy, 4, x, y, rotation_angle);
	
	// 描画
	glColor4ub(surface_color_r, surface_color_g, surface_color_b, surface_color_a);
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++)
	{
		glVertex2f(cx[i], cy[i]);
	}
	glEnd();
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
}

void point(float x, float y)
{
	glPointSize(2.0f);
	glColor4ub(point_color_r, point_color_g, point_color_b, point_color_a);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void line(float x0, float y0, float x1, float y1)
{
	glColor4ub(lines_color_r, lines_color_g, lines_color_b, lines_color_a);
	glBegin(GL_LINES);
	glVertex2f(x0, y0);
	glVertex2f(x1, y1);
	glEnd();
}