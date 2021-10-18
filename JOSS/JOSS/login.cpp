#include "login.h"
#include <bits/stdc++.h>
using namespace std;
float x[2] = { 379.0 / 1257.0,310.0 / 1032.0 };
float y[2] = { 100.0 / 450.0,100.0 / 424.0 };//335
float sizelogin[2][2] = { { 379.0 / 1257.0,310.0 / 1032.0 } , { 100.0 / 450.0,100.0 / 424.0 } };
login::login(float width, float height)
{
	Login[1].setScale(1, 1);
	button = 0;
}

login::~login()
{
}

void login::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("login/loginbg.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	sprite.setScale(720.0f/518.0f, 720.0f / 518.0f);
	window.draw(sprite);
	

	sf::Texture texture2;
	texture2.loadFromFile("login/login1.png");
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);
	//sprite2.setColor(sf::Color(110, 50, 180, 255));
	sprite2.setPosition(254, 7);
	sprite2.setScale(238.0f/228.0f, 170.0f/163.0f);
	window.draw(sprite2);

	sf::Texture texture3;
	texture3.loadFromFile("login/login2.png");
	sf::Sprite sprite3;
	sprite3.setTexture(texture3);
	sprite3.setPosition(134, 170);
	sprite3.setScale(530.0f / 1777.0f, 478.0f / 1605.0f);
	window.draw(sprite3);

	sf::Texture tex[2];
	tex[0].loadFromFile("login/login3.png");
	Login[0].setTexture(tex[0]);
	//Login[0].setColor(sf::Color(110, 50, 180, 255));
	Login[0].setPosition(183, 254);
	
	//Login[0].setScale(379.0f / 1257.0f, 100.0f / 335.0f);

	tex[1].loadFromFile("login/login4.png");
	Login[1].setTexture(tex[1]);
	//Login[1].setColor(sf::Color(110, 50, 180, 255));
	Login[1].setPosition(218, 514);
	
	//Login[1].setScale(310.0f / 1032.0f, 100.0f / 424.0f);

	for (int i = 0; i < 2; i++)
	{
		Login[i].setScale(sizelogin[i][0], sizelogin[i][1]);
		window.draw(Login[i]);
	}
}

void login::leftClick(int button)
{
}

void login::mouseup(int button)
{
	if (button >= 0)
	{
		sizelogin[button][0] = 1.1*x[button];
		sizelogin[button][1] = 1.1*y[button];
	}
}

void login::mousedown(int button)
{
	if (button >= 0)
	{
		sizelogin[button][0] = x[button];
		sizelogin[button][1] = y[button];
	}
}
