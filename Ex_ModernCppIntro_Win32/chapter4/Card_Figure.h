#ifndef CARD_H
#define CARD_H

#include "Figure.h"
#include <memory>

class Card : public Rect
{
public:
	Card(int, int, int, int);

	virtual void draw(Application&) override;
	void flip();

	static const int CardWidth = 75;
	static const int CardHeight = 100;

	int suit;
	int rank;
	bool faceUp;
};

using CardPtr = std::shared_ptr<Card>;

#endif