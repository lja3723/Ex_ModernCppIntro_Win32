#pragma once
#include "../pclaf/pclaf.h"
#include <fstream>

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int) override;
	void paint() override;

	std::ofstream outStream;

	int oldx = 0;
	int oldy = 0;
	int newx = 0;
	int newy = 0;
};