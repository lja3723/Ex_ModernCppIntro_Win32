#include "Figure.h"
#include "pclaf.h"

Figure::Figure(int _x, int _y)
	: x(_x), y(_y)
{}

void Figure::moveTo(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Circle::includes(int x, int y) const
{
	int distance;
	distance = (int)sqrt(
		pow((long double)(x - this->x), 2) + 
		pow((long double)(y - this->y), 2)
	);

	return distance < r;
}

void Circle::draw(Application& app)
{
	app.circle(x, y, r);
}

Rect::Rect(int _x, int _y, int _width, int _height)
	: Figure(_x, _y), width(_width), height(_height)
{}

void Rect::draw(Application& app)
{
	//first make sure the pen is correct
	//app.setPen(brightBlue);
	app.rectangle(x, y, width, height);
}

bool Rect::includes(int x, int y) const
{
	if ((this->x < x) && (x < this->x + width))
		if ((this->y < y) && (y < this->y + height))
			return true;
	return false;
}