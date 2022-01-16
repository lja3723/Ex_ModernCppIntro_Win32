#include "Card_4.4.7.exer.h"
#include "pclaf.h"
Card::Card(int posX, int posY, int _suit, int _rank)
	: CRect(posX, posY, posX + CardWidth, posY + CardHeight),
	suit(_suit), rank(_rank), faceUp(false)
{}

void Card::draw(Application& app)
{
	CPoint rect[] = { 
		{left, top }, { right, top }, 
		{ right, bottom }, { left, bottom } 
	};
	app.polygon(rect, 4);

	if (faceUp)
	{
		if (suit == 1 || suit == 4)
			app.setTextColor(brightRed);
		else
			app.setTextColor(black);

		app.wout << setpos(left + 5, top + 5);
		if (suit == 1)
			app.wout << TEXT("heart");
		else if (suit == 2)
			app.wout << TEXT("club");
		else if (suit == 3)
			app.wout << TEXT("spade");
		else if (suit == 4)
			app.wout << TEXT("diamond");

		app.wout << setpos(left + 5, top + 20);
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
		app.setTextColor(black);
		app.wout << setpos(left + 30, top + 38);
		app.wout << TEXT("Back");
		app.line(left, top, right, bottom);
		app.line(right, top, left, bottom);
	}
}

void Card::flip()
{
	faceUp = !faceUp;
}