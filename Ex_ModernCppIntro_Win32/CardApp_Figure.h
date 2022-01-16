#pragma once
#include "pclaf.h"
#include "Card_Figure.h"

class CardApp : public Application
{
public:
	CardApp(const TCHAR* appName);
	CardApp(const TCHAR* appName, int width, int height, int x, int y);
	void mouseDown(int x, int y) override;
	void paint() override;

	Rect a{ 50, 100, 100, 100 };
	Card b{ 200, 100, 2, 7 };
	std::shared_ptr<Rect> c = std::make_shared<Card>(300, 100, 3, 5);
};