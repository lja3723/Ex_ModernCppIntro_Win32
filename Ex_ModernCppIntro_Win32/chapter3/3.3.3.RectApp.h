#pragma once
#include "pclaf.h"
#include <array>
#include <memory>
#include "Rect.h"
using namespace RectSpace;

const auto MAX_RECTS = 20;

class RectApp : public Application
{
public:
	RectApp(const TCHAR* appName, int width, int height, int x, int y);
	void mouseDown(int x, int y) override;
	void paint() override;

	//data field
	std::array<std::unique_ptr<Rect>, MAX_RECTS> rects;
	int rectCount = 0;
};