#pragma once
#include "pclaf.h"

class Rect;

class RectApp : public Application
{
public:
	RectApp(const TCHAR* appName, int width, int height, int x, int y);
	void mouseDown(int x, int y) override;
	void paint() override;

	//data field
	Rect* theRectPtr = nullptr;
};