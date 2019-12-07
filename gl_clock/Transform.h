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

extern Align rect_align;
extern Align circle_align;

// 配列から最大値を探す
float search_max(const float*, int);
// 配列から最小値を探す
float search_min(const float*, int);
void setAlign(PType, Align);
void rotateVertex(float*, float*, int, float, float, float);
void translateAlign(float*, float*, int, Align);