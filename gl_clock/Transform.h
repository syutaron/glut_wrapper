#define _USE_MATH_DEFINES

#pragma once
#include <math.h>

enum Align
{
	LEFT_TOP,		CENTER_TOP,		RIGHT_TOP,
	LEFT_CENTER,	CENTER,			RIGHT_CENTER,
	LEFT_BOTTOM,	CENTER_BOTTOM,	RIGHT_BOTTOM
}typedef Align;

enum PlimitiveType
{
	TRECT, TCIRCLE, TTRIANGLE, TPOLYGON
}typedef PType;

extern float g_rotation_angle;
extern Align g_rect_align;
extern Align g_circle_align;

inline void ratateRad(float radian)
{
	g_rotation_angle = radian;
}

inline void rotate(float degree)
{
	g_rotation_angle = degree / 180.0f * (float)M_PI;
}

float search_max(const float*, int);
float search_min(const float*, int);
void setAlign(PType, Align);
void rotateVertex(float*, float*, int, float, float, float);
void translateAlign(float*, float*, int, Align);