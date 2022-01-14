#pragma once
#include "pclaf.h"
#include <vector>

class Line
{
public:
	Line(int x1, int y1, int x2, int y2);
	void moveTo(int x, int y);
	void draw(Application&);

	int startX; int startY;
	int endX; int endY;
};

class LineApp : public Application
{
public:
	LineApp(const TCHAR*, int, int, int, int);
	void mouseDown(int x, int y) override;
	void mouseRDown(int x, int y) override;
	void paint() override;

private:
	std::vector<Line> lineVector;
};