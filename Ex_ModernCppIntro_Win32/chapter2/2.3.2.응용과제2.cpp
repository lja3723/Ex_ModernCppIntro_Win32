#include "2.3.2.응용과제2.h"
#include <memory>
PenApp::PenApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{
}

void PenApp::mouseDown(int x, int y)
{
	newx = x;
	newy = y;
	setPen(brightBlue);
	clearAndUpdate();
}

void PenApp::mouseRDown(int x, int y)
{
	newx = x;
	newy = y;
	setPen(brightRed);
	clearAndUpdate();
}

void PenApp::paint()
{
	line(oldx, oldy, newx, newy);
	wout << setpos(newx, newy) << TEXT("hello");
	oldx = newx;
	oldy = newy;
}

int mainLAF()
{
	auto sptr = std::make_shared<PenApp>(TEXT("Pens"), 500, 500, 100, 100);
	sptr->run();
	return 0;
}