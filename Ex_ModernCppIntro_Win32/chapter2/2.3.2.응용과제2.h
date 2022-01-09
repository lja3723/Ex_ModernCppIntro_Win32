#pragma once
#include "../pclaf/pclaf.h"

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int) override;
	void mouseRDown(int, int) override;
	void paint() override;

	int oldx = 0;
	int oldy = 0;
	int newx = 0;
	int newy = 0;
};