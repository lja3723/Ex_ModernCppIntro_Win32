#pragma once
#include "pclaf.h"
#include "Card.h"
#include <vector>

class CardApp : public Application
{
public:
	CardApp(const TCHAR* appName);
	CardApp(const TCHAR* appName, int width, int height, int x, int y);
	void mouseDown(int x, int y) override;
	void mouseRDown(int x, int y) override;
	void paint() override;

	std::vector<Card> card_vec;
	std::vector<Circle> circle_vec;
};