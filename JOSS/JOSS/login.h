#pragma once

#include <SFML/Graphics.hpp>

class login
{
public:
	login(float width, float height);
	~login();

	void draw(sf::RenderWindow& window);
	void leftClick(int button);
	void mouseup(int button);
	void mousedown(int button);
	int GetPressedItem() { return button; }

private:
	int button;
	sf::Font font;
	//sf::Text Menu[MAX_NUMBER_OF_ITEMS];
	sf::Sprite Login[2];

};