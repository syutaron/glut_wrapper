#pragma once
#include <GL/gl.h>

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

enum COLOR_CODE
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
	BROWN,
}typedef COLOR_CODE;

struct color_rgb
{
	GLbyte r;
	GLbyte g;
	GLbyte b;

}typedef RGB;

RGB refColor(COLOR_CODE code)
{
	switch (code)
	{
	case WHITE:
	{
		RGB col = { 0xff, 0xff, 0xff };
		return col;
	}
	case BLACK:
	{
		RGB col = { 0x00, 0x00, 0x00 };
		return col;
	}
	case GRAY:
	{
		RGB col = { 0x80, 0x80, 0x80 };
		return col;
	}
	case LIGHT_GRAY:
	{
		RGB col = { 0xd3, 0xd3, 0xd3 };
		return col;
	}
	case RED:
	{
		RGB col = { 0xff, 0x00, 0x00 };
		return col;
	}
	case ORANGE:
	{
		RGB col = { 0xff, 0x45, 0x00 };
		return col;
	}
	case BLUE:
	{
		RGB col = { 0x00, 0x00, 0xff };
		return col;
	}
	case SKY_BLUE:
	{
		RGB col = { 0x87, 0xce, 0xeb };
		return col;
	}
	case GREEN:
	{
		RGB col = { 0x00, 0x80, 0x00 };
		return col;
	}
	case LIME:
	{
		RGB col = { 0x00, 0xff, 0x00 };
		return col;
	}
	case YELLOW:
	{
		RGB col = { 0xff, 0xff, 0x00 };
		return col;
	}
	case PURPLE:
	{
		RGB col = { 0x80, 0x00, 0x80 };
		return col;
	}
	case BROWN:
	{
		RGB col = { 0x73, 0x42, 0x29 };
		return col;
	}
	default:
	{
		RGB col = { 0xff, 0xff, 0xff };
		return col;
	}
	}
}

// ↓↓ color setters

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