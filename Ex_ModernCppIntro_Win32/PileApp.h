#pragma once
#include "pclaf.h"
#include "Pile.h"

class PileApp : public Application
{
public:
	PileApp(const TCHAR* appName);
	PileApp(const TCHAR* appName, int width, int height, int x, int y);
	void mouseDown(int x, int y) override;
	void paint() override;

	DeckPile theDeck{ 100, 100 };
	CardPile theDiscard{ 200, 100 };
};