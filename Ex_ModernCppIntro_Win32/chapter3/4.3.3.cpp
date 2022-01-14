#include "4.3.3.h"
#include <random>
#include <ctime>

FigureApp::FigureApp(const TCHAR* appName)
	: Application(appName)
{
}

FigureApp::FigureApp(const TCHAR* appName, int width, int height, int x, int y)
	: Application(appName, width, height, x, y)
{}

void FigureApp::mouseDown(int x, int y)
{
	static std::mt19937 engine(static_cast<unsigned long>(time(nullptr)));
	static std::uniform_int_distribution<int> distSuit(1, 4);
	static std::uniform_int_distribution<int> distRank(1, 13);

	if (figures.size() < 10)
	{
		figures.push_back(std::make_shared<Card>(x, y, distSuit(engine), distRank(engine)));
		std::static_pointer_cast<Card>(figures.back())->flip();
	}
	clearAndUpdate();
}

void FigureApp::mouseRDown(int x, int y)
{
	if (figures.size() < 10)
		figures.push_back(std::make_shared<Circle>(x, y, 40));
	clearAndUpdate();
}

void FigureApp::doubleClick(int x, int y)
{
	for (auto f = figures.rbegin(); f < figures.rend(); ++f)
	{
		if ((*f)->includes(x, y))
		{
			(*f)->selected = true;
			break;
		}
	}
	clearAndUpdate();
}

void FigureApp::paint()
{
	for (auto& i : figures)
	{
		if (i->selected)
			setPen(green, solidLine, 3);
		i->draw(*this);
		setPen(black);
	}
}

int mainLAF()
{
	FigureApp app(TEXT("Cards"));

	app.run();

	return 0;
}
