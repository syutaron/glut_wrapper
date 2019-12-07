#include "Colors.h"

RGB g_shape_color;
RGB g_lines_color;
RGB g_point_color;
RGB g_clear_color;
GLbyte g_shape_color_a;
GLbyte g_lines_color_a;
GLbyte g_point_color_a;

RGB codeToRGB(ColorCode code)
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

void color(ColorCode code, AType type)
{
	switch (type)
	{
	case TYPE_SHAPE:
		g_shape_color = codeToRGB(code);
		break;
	case TYPE_LINE:
		g_lines_color = codeToRGB(code);
		break;
	case TYPE_POINT:
		g_point_color = codeToRGB(code);
		break;
	case TYPE_CLEAR:
		g_clear_color = codeToRGB(code);
		break;
	default:
		g_shape_color = codeToRGB(code);
		break;
	}
}

void colorRGB(GLbyte r, GLbyte g, GLbyte b, AType type)
{
	RGB col = { r, g, b };

	switch (type)
	{
	case TYPE_SHAPE:
		g_shape_color = col;
		break;

	case TYPE_LINE:
		g_lines_color = col;
		break;

	case TYPE_POINT:
		g_point_color = col;
		break;

	case TYPE_CLEAR:
		g_clear_color = col;
		break;

	default:
		g_shape_color = col;
		break;
	}
}

void setAlpha(GLbyte a, AType type)
{
	switch (type)
	{
	case TYPE_SHAPE:
		g_shape_color_a = a;
		break;
	case TYPE_LINE:
		g_lines_color_a = a;
		break;
	case TYPE_POINT:
		g_point_color_a = a;
		break;
	default:
		g_shape_color_a = a;
		break;
	}
}