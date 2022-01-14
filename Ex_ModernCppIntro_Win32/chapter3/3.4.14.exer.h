#pragma once
#include "pclaf.h"
#include <vector>
#include <memory>

class Circle
{
public:
	Circle(int x, int y, int r);

	void moveTo(int x, int y);
	bool includes(int x, int y);
	int area();
	void draw(Application&);

	int centerX, centerY, radius;
};

class CircleApp : public Application
{
public:
	CircleApp(const TCHAR* appName, int width, int height, int x, int y);
	void mouseDown(int x, int y) override;
	void paint() override;

	//data field
	typedef std::shared_ptr<Circle> CirclePtr;
	std::vector<CirclePtr> circlePtrVector;
	int numCircle = 0;
};