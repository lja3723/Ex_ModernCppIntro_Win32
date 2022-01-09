#pragma once

class Application;

class Rect
{
public:
	//constructor
	Rect(int topleft_x, int topleft_y, int bottomright_x, int bottomright_y);

	//operations
	void moveTo(int x, int y);
	bool includes(int x, int y);
	virtual void draw(Application& app);
	int getWidth();
	int getHeight();

	//data fields
	int upperLeftX;
	int upperLeftY;
	int lowerRightX;
	int lowerRightY;

};