#include "Pile.h"
#include "pclaf.h"
#include <random>
#include <algorithm>

CardPile::CardPile(int x, int y)
	: upperLeftX(x), upperLeftY(y), count(0)
{
}

void CardPile::addCard(const CardPtr& c)
{
	if (count < MAX_CARDS)
	{
		theCards[count++] = c;
		c->moveTo(upperLeftX, upperLeftY);
	}
}

CardPtr CardPile::topCard()
{
	if (count > 0)
		return theCards[--count];
	return nullptr;
}


bool CardPile::includes(int x, int y)
{
	for (int k = count; k > 0; k--)
		if (theCards[k - 1]->includes(x, y))
			return true;
	return false;
}

void CardPile::display(Application& app)
{
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
			theCards[i]->moveTo(upperLeftX, upperLeftY);

		for (int i = 0; i < count; i++)
		{
			theCards[i]->moveTo(upperLeftX, upperLeftY + 10 * i);
			theCards[i]->draw(app);
		}
		//theCards[count - 1]->draw(app);
	}
	else 
	{
		app.setPen(green, solidLine, 3);
		app.rectangle(upperLeftX, upperLeftY, Card::CardWidth, Card::CardHeight);
		app.setPen(black);
	}
}

void CardPile::select()
{
}

DeckPile::DeckPile(int x, int y)
	: CardPile(x, y)
{
}

void DeckPile::addCard(const CardPtr& c)
{
	static std::random_device rd;
	static std::mt19937 eng(rd());
	if (count < MAX_CARDS) {
		CardPile::addCard(c);
		c->moveTo(upperLeftX, upperLeftY); //이거 필요없을거같은데 나중에 주석처리 해보자
		auto it = theCards.begin();
		std::advance(it, count);
		std::shuffle(theCards.begin(), it, eng);
	}
}
