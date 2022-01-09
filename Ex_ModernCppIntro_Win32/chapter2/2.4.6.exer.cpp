#include "2.4.6.exer.h"
#include <memory>
PenApp::PenApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y), index(0)
{
}

void PenApp::mouseDown(int x, int y)
{
	if (index < MAX_LINES)
	{
		Points[index].x = x;
		Points[index].y = y;
		index++;
	}
	clearAndUpdate();
}

void PenApp::paint()
{
	Pt start = { 0, 0 };
	for (int i = 0; i < index; i++)
	{
		line(start.x, start.y, Points[i].x, Points[i].y);
		start = Points[i];
	}
}

int mainLAF()
{
	auto sptr = std::make_shared<PenApp>(TEXT("Pens"), 500, 500, 100, 100);
	sptr->run();
	return 0;
}