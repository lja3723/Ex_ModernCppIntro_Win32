#include "2.4.7.exer.h"
#include <memory>
PenApp::PenApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{
}

void PenApp::mouseDown(int x, int y)
{
	newx = x;
	newy = y;
	outStream.open("point.txt", std::ios::app);
	outStream << "x:" << newx << " y:" << newy << std::endl;
	outStream.close();
	clearAndUpdate();
}

void PenApp::paint()
{
	line(oldx, oldy, newx, newy);
	oldx = newx;
	oldy = newy;
}

int mainLAF()
{
	auto sptr = std::make_shared<PenApp>(TEXT("Pens"), 500, 500, 100, 100);
	sptr->run();
	return 0;
}