#ifndef CARD_H
#define CARD_H

//#include "Rect.h"
#include <atltypes.h>
#include "pclaf.h"

class Card : public CRect
{
public:
	Card(int, int, int, int);

	virtual void draw(Application&);
	void flip();

	static const int CardWidth = 75;
	static const int CardHeight = 100;

	int suit;
	int rank;
	bool faceUp;
};

#endif