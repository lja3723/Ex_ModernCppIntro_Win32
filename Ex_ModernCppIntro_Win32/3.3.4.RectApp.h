#pragma once
#include "pclaf.h"
#include <vector>
#include "Rect.h"
using namespace RectSpace;

const auto MAX_RECTS = 5;

class RectApp : public Application
{
public:
	RectApp(const TCHAR* appName, int width, int height, int x, int y);
	void mouseDown(int x, int y) override;
	void mouseRDown(int x, int y) override;
	void paint() override;

	//data field
	std::vector<Rect> rects;
	int rectCount = 0;
	bool isMouseRDown = false;
};