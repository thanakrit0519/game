#pragma once

#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 4
class menu
{
public:
	menu(float width, float height);
	~menu();

	void draw(sf::RenderWindow& window);
	void leftClick(int button);
	void mouseup(int button);
	void mousedown(int button);
	int GetPressedItem() { return button; };

private:
	int button;
	sf::Font font;
	//sf::Text Menu[MAX_NUMBER_OF_ITEMS];
	sf::Sprite Menu[MAX_NUMBER_OF_ITEMS];

};