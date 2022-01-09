#pragma once
#include "pclaf.h"
#include <fstream>

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int) override;
	void paint() override;
	int distance();

	std::ofstream outStream;

	int firstX = 0;
	int firstY = 0;
	int secondX = 0;
	int secondY = 0;
};