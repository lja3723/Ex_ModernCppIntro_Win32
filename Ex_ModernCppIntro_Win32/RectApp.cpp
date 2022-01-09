#include "RectApp.h"
#include "Rect.h"


RectApp::RectApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y) 
{}

void RectApp::mouseDown(int x, int y) 
{
	if (theRectPtr != nullptr) {
		if (theRectPtr->includes(x, y))
			theRectPtr->moveTo(x, y);
	}
	else
	{
		theRectPtr = new Rect(x, y, x + 70, y + 50);
	}
	clearAndUpdate();
}

void RectApp::paint()
{
	if (theRectPtr != nullptr)
		theRectPtr->draw(*this);
}

int mainLAF()
{
	RectApp app(TEXT("rectangles"), 750, 500, 150, 150);
	app.run();

	delete app.theRectPtr;
	app.theRectPtr = nullptr;

	return 0;
}