#ifndef FIGURE_H
#define FIGURE_H
#include <memory>

class Application;

class Figure
{
public:
	Figure(int _x, int _y);
	void moveTo(int x, int y);
	virtual void draw(Application& app) = 0;

	int x;
	int y;
};

class Circle : public Figure
{
public:
	Circle(int _x, int _y, int _r)
		: Figure(_x, _y), r(_r)
	{}

	virtual void draw(Application& app) override;
	int r;
};

class Rect : public Figure
{
public:
	//constructor
	Rect(int _x, int _y, int _width, int _height);

	//operations
	bool includes(int x, int y);
	virtual void draw(Application& app) override;

	//data fields
	int width;
	int height;
};

using FigurePtr = std::shared_ptr<Figure>;

#endif