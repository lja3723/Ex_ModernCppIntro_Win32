#include "3.3.3.RectApp.h"
#include "Rect.h"


RectApp::RectApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y) 
{}

void RectApp::mouseDown(int x, int y) 
{
	if (rectCount >= MAX_RECTS)
		return;

	else if (rectCount > 0)
	{
		bool isInclude = false;
		for (int i = 0; i < rectCount; i++)
			if (rects[i]->includes(x, y))
			{
				isInclude = true;
				break;
			}

		if (!isInclude)
		{
			clearAndUpdate();
			return;
		}
	}

	rects[rectCount++] = std::make_unique<Rect>(x, y, x + 70, y + 50);
	clearAndUpdate();
}

void RectApp::paint()
{
	for (int i = 0; i < rectCount; i++)
		rects[i]->draw(*this);
}

int mainLAF()
{
	RectApp app(TEXT("rectangles"), 750, 500, 150, 150);
	app.run();

	return 0;
}