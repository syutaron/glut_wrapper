enum Align
{
	LEFT_TOP, CENTER_TOP, RIGHT_TOP,
	LEFT_CENTER, CENTER, RIGHT_CENTER,
	LEFT_BOTTOM, CENTER_BOTTOM, RIGHT_BOTTOM
}typedef Align;

Align rect_align;
Align circle_align;


enum Plimitive_type
{
	TRECT, TCIRCLE, TTRIANGLE, TPOLYGON
}typedef Type;

// 配列から最大値を探す
float search_max(float* a, int size)
{
	float value = a[0];
	for (int i = 1; i < size; i++)
	{
		value = a[i] > value ? a[i] : value;
	}
	return value;
}

// 配列から最小値を探す
float search_min(float* a, int size)
{
	float value = a[0];
	for (int i = 1; i < size; i++)
	{
		value = a[i] < value ? a[i] : value;
	}
	return value;
}

void rotateVertex(float* x_coord, float* y_coord, int n, float origin_x, float origin_y, float theta)
{
	for (int i = 0; i < n; i++)
	{
		float x = x_coord[i] - origin_x;
		float y = y_coord[i] - origin_y;
		x_coord[i] = x * cosf(theta) - y * sinf(theta);
		y_coord[i] = x * sinf(theta) + y * cosf(theta);
		x_coord[i] = x_coord[i] + origin_x;
		y_coord[i] = y_coord[i] + origin_y;
	}
}

// 任意の数の頂点の座標をAlignに従って移動させます
// ポリゴンを囲む矩形を基準とします
void translateAlign(float* x_coord, float* y_coord, int size, Align align)
{
	// 矩形範囲を調べる
	float area_width  = search_max(x_coord, size) - search_min(x_coord, size);
	float area_height = search_max(y_coord, size) - search_min(y_coord, size);

	float move_distance_x = 0;
	float move_distance_y = 0;

	if (align == CENTER_TOP || align == CENTER || align == CENTER_BOTTOM)
	{
		move_distance_x = -area_width / 2.0f;
	}

	if (align == RIGHT_TOP || align == RIGHT_CENTER || align == RIGHT_BOTTOM)
	{
		move_distance_x = -area_width;
	}

	if (align == LEFT_CENTER || align == CENTER || align == RIGHT_CENTER)
	{
		move_distance_y = -area_height / 2.0f;
	}

	if (align == LEFT_BOTTOM || align == CENTER_BOTTOM || align == RIGHT_BOTTOM)
	{
		move_distance_y = -area_height;
	}

	for (int i = 0; i < size; i++)
	{
		x_coord[i] = x_coord[i] + move_distance_x;
		y_coord[i] = y_coord[i] + move_distance_y;

	}
}

void setAlign(Type primitive_type, Align align)
{
	switch (primitive_type)
	{
	case TRECT:
		rect_align = align;
		break;

	case TCIRCLE:
		circle_align = align;
		break;
	}
}