#include "Wrapper.h"

void Setup()
{
	setTitle("test");
	setWindowPos(500, 500);
	setWindowSize(450, 450);
	setColor(TYPE_CLEAR, SKY_BLUE);
}

void Update()
{
	static float theta = 0;
	setPointSize(5);
	rotate(theta);
	theta += 4;

	setAlign(TYPE_RECT, CENTER);
	setColor(TYPE_POINT, GREEN);
	drawRect(200, 200, 50, 50);
	drawPoint(100, 100);
	for (int i = 0; i < 9; i++)
	{
		setAlign(TYPE_RECT, i);
		drawRect((i % 3) * 100 + 100, (i / 3) * 100 + 100, 50, 50);
		drawPoint((i % 3) * 100 + 100, (i / 3) * 100 + 100);
	}
}