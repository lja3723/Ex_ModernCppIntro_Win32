#pragma once
#include "pclaf.h"
#include "Card.h"
#include <vector>

class FigureApp : public Application
{
public:
	FigureApp(const TCHAR* appName);
	FigureApp(const TCHAR* appName, int width, int height, int x, int y);
	void mouseDown(int x, int y) override;
	void mouseRDown(int x, int y) override;
	void doubleClick(int x, int y) override;
	void paint() override;

	static const int Figure_Max = 10;
	std::vector<FigurePtr> figures;
};