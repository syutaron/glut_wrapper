#pragma once
#include "Colors.h"
#include "Transform.h"

#define CIRCLE_VERTEX 100
#define TRUE 1
#define FALSE 0

extern int g_width;
extern int g_height;
extern float g_rotation_angle;
extern float g_lines_width;

void linesWidth(float);
void ratateRad(float);
void rotate(float);
void circle(float, float, float);
void rect(float, float, float, float);
void triangle(float, float, float, float, float, float);
void point(float, float);
void line(float, float, float, float);
void polygone(float*, float*, int);