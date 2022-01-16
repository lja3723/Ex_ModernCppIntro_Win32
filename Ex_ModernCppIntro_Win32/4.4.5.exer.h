#pragma once
#include "pclaf.h"

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int) override;
	void paint() override;

	int oldx = 0;
	int oldy = 0;
	int newx = 0;
	int newy = 0;
};

class MyChild : public ChildWindow
{
public:
	MyChild(const TCHAR*, int, int, int, int);
	void mouseDown(int, int) override;
	void paint() override;

	int childX = 50;
	int childY = 50;
};