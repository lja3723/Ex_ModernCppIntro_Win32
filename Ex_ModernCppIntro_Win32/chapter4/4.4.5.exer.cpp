#include "4.4.5.exer.h"

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

MyChild::MyChild(const TCHAR* appName, int width, int height, int x, int y)
	: ChildWindow(appName, width, height, x, y)
{
}

void MyChild::mouseDown(int x, int y)
{
	childX = x;
	childY = y;
	clearAndUpdate();
}

void MyChild::paint()
{
	circle(childX, childY, 30);
}

int mainLAF()
{
	PenApp app(TEXT("Pens"), 500, 500, 150, 150);
	MyChild child(TEXT("Child"), 200, 200, 700, 500);
	app.run();

	return 0;
}