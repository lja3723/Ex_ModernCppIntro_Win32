#include "PileApp.h"

PileApp::PileApp(const TCHAR* appName)
	: Application(appName)
{
}

PileApp::PileApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{
}

void PileApp::mouseDown(int x, int y)
{
	if (theDeck.includes(x, y)) 
	{
		CardPtr deckTop = theDeck.topCard();
		theDiscard.addCard(deckTop);
	}

	if (theDiscard.includes(x, y)) 
	{
		CardPtr discardTop = theDiscard.topCard();
		discardTop->flip();
		theDiscard.addCard(discardTop);
	}

	clearAndUpdate();
}

void PileApp::paint()
{
	theDeck.display(*this);
	theDiscard.display(*this);
}

int mainLAF()
{
	PileApp app(TEXT("Piles"));
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j < 13; j++)
			app.theDeck.addCard(std::make_shared<Card>(0, 0, i, j));
	app.run();

	return 0;
}