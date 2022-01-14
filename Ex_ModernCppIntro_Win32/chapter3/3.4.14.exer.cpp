#include "3.4.14.exer.h"
#include <cmath>

template <typename T>
T getDistance(int x1, int y1, int x2, int y2)
{
	return static_cast<T>(sqrt(
		pow(static_cast<long double>(x2 - x1), 2.0) +
		pow(static_cast<long double>(y2 - y1), 2.0)));
}

Circle::Circle(int x, int y, int r)
	: centerX(x), centerY(y), radius(r)
{}
void Circle::moveTo(int x, int y)
{
	centerX = x;
	centerY = y;
}
bool Circle::includes(int x, int y)
{
	return getDistance<long double>(centerX, centerY, x, y) < static_cast<long double>(radius);
}
int Circle::area()
{
	double PI = 3.14159265358979324;
	return static_cast<int>(PI * radius * radius);
}
void Circle::draw(Application& app)
{
	app.circle(centerX, centerY, radius);
	app.wout << setpos(centerX, centerY) << area();
}

CircleApp::CircleApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{}

void CircleApp::mouseDown(int x, int y)
{
	static int cx, cy;
	static bool isCenterPoint = true;

	if (isCenterPoint)
	{
		cx = x;
		cy = y;
		isCenterPoint = false;
	}
	else
	{
		circlePtrVector.push_back(std::make_shared<Circle>(cx, cy, getDistance<int>(cx, cy, x, y)));
		numCircle++;
		isCenterPoint = true;

		clearAndUpdate();
	}
}

void CircleApp::paint()
{
	for (int i = 0; i < numCircle; i++)
		circlePtrVector[i]->draw(*this);
}

int mainLAF()
{
	CircleApp app(TEXT("Circles"), 750, 500, 150, 150);
	app.run();

	return 0;
}