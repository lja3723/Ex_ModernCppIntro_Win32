#pragma once
#include "pclaf.h"
#include "Card_4.4.7.exer.h"
#include <memory>

class CardApp : public Application
{
public:
	CardApp(const TCHAR* appName);
	CardApp(const TCHAR* appName, int width, int height, int x, int y);
	void mouseDown(int x, int y) override;
	void paint() override;

	//Rect a{ 50, 100, 150, 200 };
	Card b{ 200, 100, 2, 7 };
	std::unique_ptr<Card> c = std::make_unique<Card>(300, 100, 1, 5);
};