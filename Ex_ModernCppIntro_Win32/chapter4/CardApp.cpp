#include "CardApp.h"

CardApp::CardApp(const TCHAR* appName)
	: Application(appName)
{
}

CardApp::CardApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{}

void CardApp::mouseDown(int x, int y)
{
	if (b.includes(x, y))
		b.flip();
	clearAndUpdate();
}

void CardApp::paint()
{
	a.draw(*this);
	b.draw(*this);
	c->draw(*this);
}

int mainLAF()
{
	CardApp app(TEXT("Cards"));

	app.run();

	return 0;
}
