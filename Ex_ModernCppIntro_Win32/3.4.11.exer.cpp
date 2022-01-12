#include "3.4.11.exer.h"
#include "pclaf.h"

Line::Line(int x1, int y1, int x2, int y2)
	: startX(x1), startY(y1), endX(x2), endY(y2)
{}

void Line::moveTo(int x, int y)
{
	int diffX = endX - startX;
	int diffY = endY - startY;
	startX = x; startY = y;
	endX = startX + diffX;
	endY = startY + diffY;
}

void Line::draw(Application& app)
{
	app.line(startX, startY, endX, endY);
}

LineApp::LineApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{}

void LineApp::mouseDown(int x, int y)
{
	static bool isFirst = true;
	static int x1, y1;

	if (isFirst)
	{
		x1 = x, y1 = y;
		isFirst = false;
	}
	else
	{
		lineVector.push_back(Line(x1, y1, x, y));
		isFirst = true;
	}

	clearAndUpdate();
}

void LineApp::paint()
{
	setPen(green);
	for (auto& line : lineVector)
		line.draw(*this);
}

int mainLAF()
{
	LineApp app(TEXT("Lines"), 1280, 720, 200, 150);
	app.run();

	return 0;
}