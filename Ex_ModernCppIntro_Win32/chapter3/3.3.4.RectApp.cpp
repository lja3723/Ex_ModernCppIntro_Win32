#include "3.3.4.RectApp.h"
#include "Rect.h"
#include <algorithm>

bool operator<(const Rect& lhs, const Rect& rhs)
{
	int lhsArea = (lhs.lowerRightX - lhs.upperLeftX) * (lhs.lowerRightY - lhs.upperLeftY);
	int rhsArea = (rhs.lowerRightX - rhs.upperLeftX) * (rhs.lowerRightY - rhs.upperLeftY);
	return lhsArea < rhsArea;
}

bool operator>(const Rect& lhs, const Rect& rhs)
{
	return rhs < lhs;
}

bool operator==(const Rect& lhs, const Rect& rhs)
{
	return !(lhs < rhs) && !(lhs > rhs);
}

RectApp::RectApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{}

void RectApp::mouseDown(int x, int y)
{
	static bool isFirstPoint = true;
	static int firstX = 0;
	static int firstY = 0;

	if (rectCount == MAX_RECTS)
		return;
	
	if (isFirstPoint)
	{
		firstX = x;
		firstY = y;
		isFirstPoint = false;
	}
	else
	{
		rects.emplace_back(firstX, firstY, x, y);
		rectCount++;
		isFirstPoint = true;
	}

	clearAndUpdate();
}

void RectApp::mouseRDown(int x, int y)
{
	isMouseRDown = true;
	clearAndUpdate();
}

void RectApp::paint()
{
	for (int i = 0; i < rectCount; i++)
		rects[i].draw(*this);

	if (isMouseRDown)
	{
		std::sort(rects.begin(), rects.end(), operator<);
		for (int i = 0; i < rectCount; i++)
			wout << setpos(rects[i].upperLeftX, rects[i].upperLeftY) << (i + 1);
		isMouseRDown = false;
	}
}

int mainLAF()
{
	RectApp app(TEXT("rectangles"), 750, 500, 150, 150);
	app.run();

	return 0;
}