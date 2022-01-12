#include "Rect.h"
#include "pclaf.h"

namespace RectSpace
{
	Rect::Rect(int topleft_x, int topleft_y, int bottomright_x, int bottomright_y)
		: upperLeftX(topleft_x), upperLeftY(topleft_y),
		lowerRightX(bottomright_x), lowerRightY(bottomright_y)
	{}

	int Rect::getWidth()
	{
		return lowerRightX - upperLeftX;
	}

	int Rect::getHeight()
	{
		return lowerRightY - upperLeftY;
	}

	void Rect::moveTo(int x, int y)
	{
		int width = getWidth();
		int height = getHeight();
		upperLeftX = x;
		upperLeftY = y;
		lowerRightX = x + width;
		lowerRightY = y + height;
	}

	void Rect::draw(Application& app)
	{
		//first make sure the pen is correct
		app.setPen(brightBlue);
		app.rectangle(upperLeftX, upperLeftY, getWidth(), getHeight());
	}

	bool Rect::includes(int x, int y)
	{
		if ((upperLeftX < x) && (x < lowerRightX))
			if ((upperLeftY < y) && (y < lowerRightY))
				return true;
		return false;
	}
}

