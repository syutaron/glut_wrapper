#pragma once
#include <GL/gl.h>

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
		RGB col = { 0x00, 0x00, 0x00 };
		return col;
	}
	}
}