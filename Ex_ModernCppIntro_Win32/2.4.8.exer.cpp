#include "2.4.8.exer.h"

PenApp::PenApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{
}

void PenApp::mouseDown(int x, int y)
{
	static int count = 0;
	if (count == 0)
	{
		firstX = x;
		firstY = y;
		count++;
	}
	else
	{
		secondX = x;
		secondY = y;
		count--;
		clearAndUpdate();
		outStream.open("circle.txt", std::ios::app);
		outStream << firstX << " " << firstY << " " << distance() << std::endl;
		outStream.close();
	}
}

int PenApp::distance()
{
	return static_cast<int>(sqrt(
		pow(long double(secondX - firstX), 2.0) +
		pow(long double(secondY - firstY), 2.0)
	));
}

void PenApp::paint()
{
	circle(firstX, firstY, distance());
}

int mainLAF()
{
	PenApp app(TEXT("Pens"), 500, 500, 100, 100);
	app.run();
	return 0;
}