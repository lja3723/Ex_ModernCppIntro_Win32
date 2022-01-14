#include "Card.h"
#include "pclaf.h"
Card::Card(int posX, int posY, int _suit, int _rank)
	: Rect(posX, posY, CardWidth, CardHeight),
	suit(_suit), rank(_rank), faceUp(false)
{}

void Card::draw(Application& app)
{
	Rect::draw(app);

	if (faceUp)
	{
		if (suit == 1 || suit == 4)
			app.setTextColor(brightRed);
		else
			app.setTextColor(black);

		app.wout << setpos(x + 5, y + 5);
		if (suit == 1)
			app.wout << TEXT("heart");
		else if (suit == 2)
			app.wout << TEXT("club");
		else if (suit == 3)
			app.wout << TEXT("spade");
		else if (suit == 4)
			app.wout << TEXT("diamond");

		app.wout << setpos(x + 5, y + 20);
		if (rank == 1)
			app.wout << TEXT("ace");
		else if (rank == 11)
			app.wout << TEXT("jack");
		else if (rank == 12)
			app.wout << TEXT("queen");
		else if (rank == 13)
			app.wout << TEXT("king");
		else
			app.wout << rank;
	}
	else
	{
		app.wout << setpos(x + 30, y + 38);
		app.wout << TEXT("Back");
		app.line(x, y, x + width, y + height);
		app.line(x + width, y, x, y + height);
	}
}

void Card::flip()
{
	faceUp = !faceUp;
}