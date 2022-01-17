#pragma once
#include "Card.h"
#include <array>

const int MAX_CARDS = 52;
class CardPile
{
public:
	CardPile(int x, int y);

	virtual void addCard(const CardPtr& c);
	virtual CardPtr topCard();
	bool includes(int x, int y);
	virtual void display(Application& app);
	virtual void select();

	int upperLeftX;
	int upperLeftY;
	int count;
	std::array<CardPtr, MAX_CARDS> theCards;
};

class DeckPile : public CardPile
{
public:
	DeckPile(int x, int y);
	virtual void addCard(const CardPtr& c);
};

using CardPilePtr = std::shared_ptr<CardPile>;