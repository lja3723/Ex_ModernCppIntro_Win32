#pragma once
#include <memory>

class Application;

class Figure
{
public:
	Figure(int _x, int _y);
	void moveTo(int x, int y);
	virtual bool includes(int x, int y) const = 0;
	virtual void draw(Application& app) = 0;

	int x;
	int y;
	//Color col;
	bool selected = false;
};

class Circle : public Figure
{
public:
	Circle(int _x, int _y, int _r)
		: Figure(_x, _y), r(_r)
	{}

	bool includes(int x, int y) const override;
	void draw(Application& app) override;
	int r;
};

class Rect : public Figure
{
public:
	//constructor
	Rect(int _x, int _y, int _width, int _height);

	//operations
	bool includes(int x, int y) const override;
	virtual void draw(Application& app) override;

	//data fields
	int width;
	int height;
};

using FigurePtr = std::shared_ptr<Figure>;

//4.4.6.exer
class Triangle : public Figure {
public:
	Triangle(int, int);
	virtual void draw(Application&);

	int length;
};