#include "2.4.5.exer.h"
#include <memory>
PenApp::PenApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{
}

void PenApp::mouseDown(int x, int y)
{
	static bool sw = true;
	if (sw)
	{
		startPoint.x = x;
		startPoint.y = y;
	}
	else
	{
		endPoint.x = x;
		endPoint.y = y;
		clearAndUpdate();
	}
	sw = !sw;
}

void PenApp::paint()
{
	line(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
}

int mainLAF()
{
	auto sptr = std::make_shared<PenApp>(TEXT("Pens"), 500, 500, 100, 100);
	sptr->run();
	return 0;
}