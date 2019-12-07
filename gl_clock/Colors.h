#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

enum ColorCode
{
	WHITE,
	BLACK,
	GRAY,
	LIGHT_GRAY,
	RED,
	ORANGE,
	BLUE,
	SKY_BLUE,
	GREEN,
	LIME,
	YELLOW,
	PURPLE,
	BROWN
}typedef COLOR_CODE;

enum AppType
{
	TYPE_SHAPE,
	TYPE_LINE,
	TYPE_POINT
}typedef AType;

struct color_rgb
{
	GLbyte r;
	GLbyte g;
	GLbyte b;
}typedef RGB;

extern RGB g_shape_color;
extern RGB g_lines_color;
extern RGB g_point_color;
extern GLbyte g_shape_color_a;
extern GLbyte g_lines_color_a;
extern GLbyte g_point_color_a;

RGB codeToRGB(COLOR_CODE);
void setColor(COLOR_CODE, AType);
void setColorRGB(GLbyte, GLbyte, GLbyte, AType);
void setAlpha(GLbyte, AType);