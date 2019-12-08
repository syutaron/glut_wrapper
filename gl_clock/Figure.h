#pragma once
#include "Colors.h"
#include "Transform.h"

#define CIRCLE_VERTEX 100

extern int g_width;
extern int g_height;
extern float g_lines_width;
extern float g_point_size;

void drawCircle(float, float, float);
void drawRect(float, float, float, float);
void drawTriangle(float, float, float, float, float, float);
void drawPoint(float, float);
void drawLine(float, float, float, float);
void drawPolygone(float*, float*, int);

inline void setLineWidth(float w)
{
	if (w <= 0.0f) { return; }
	g_lines_width = w <= 10.0f ? w : 10.0f;	// 幅は10まで
	glLineWidth(g_lines_width);
}

inline void setPointSize(float s)
{
	g_point_size = s <= 10.0f ? s : 10.0f;
	glPointSize(g_point_size);
}