#pragma once
#include "../pclaf/pclaf.h"

struct Pt
{
	int x = 0;
	int y = 0;
};

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int) override;
	void paint() override;

	Pt startPoint, endPoint;
};