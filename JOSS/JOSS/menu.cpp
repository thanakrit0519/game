#include "menu.h"

menu::menu(float width, float height)
{
	Menu[1].setScale(1, 1);
	button = 0;
}
menu::~menu()
{

}

void menu::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("home/bghome.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);
	
	sf::Texture texture2;
	texture2.loadFromFile("home/JOSS1.png");
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);
	sprite2.setPosition(120, 61);
	window.draw(sprite2);

	
	sf::Texture tex[MAX_NUMBER_OF_ITEMS];
	tex[0].loadFromFile("home/PLAY.png");
	Menu[0].setTexture(tex[0]);
	Menu[0].setPosition(28, 458);

	tex[1].loadFromFile("home/GUIDE.png");
	Menu[1].setTexture(tex[1]);
	Menu[1].setPosition(438, 458);

	tex[2].loadFromFile("home/SCORE.png");
	Menu[2].setTexture(tex[2]);
	Menu[2].setPosition(28, 618);

	tex[3].loadFromFile("home/EXIT.png");
	Menu[3].setTexture(tex[3]);
	Menu[3].setPosition(438, 618);



	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(Menu[i]);
	}

}
void menu::leftClick(int button)
{
	
}
void menu::mouseup(int button)
{
	if (button >= 0)
	{
		Menu[button].setScale(1.1f, 1.1f);
	}
}
void menu::mousedown(int button)
{
	if (button >= 0)
	{
		Menu[button].setScale(1, 1);
	}
}

