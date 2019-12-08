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
}typedef ColorCode;

enum AppType
{
	TYPE_SHAPE,
	TYPE_LINE,
	TYPE_POINT,
	TYPE_CLEAR
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
extern RGB g_clear_color;
extern GLbyte g_shape_color_a;
extern GLbyte g_lines_color_a;
extern GLbyte g_point_color_a;

inline void applyClearColor()
{
	float clear_r = (float)((unsigned char)g_clear_color.r) / 255.0f;
	float clear_g = (float)((unsigned char)g_clear_color.g) / 255.0f;
	float clear_b = (float)((unsigned char)g_clear_color.b) / 255.0f;
	glClearColor(clear_r, clear_g, clear_b, 1.0f);
}

RGB codeToRGB(ColorCode);
void setColor(AType, ColorCode);
void setColorRGB(AType, GLbyte, GLbyte, GLbyte);
void setAlpha(AType, GLbyte);