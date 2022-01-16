#include "PenApp.h"

PenApp::PenApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{
}

void PenApp::mouseDown(int x, int y)
{
	newx = x;
	newy = y;
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
	PenApp app(TEXT("Pens"), 500, 500, 150, 150);
	app.run();

	return 0;
}
