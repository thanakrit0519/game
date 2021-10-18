#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <bits/stdc++.h>
#include "menu.h"
#include "login.h"
#include "Animation.h"
#include "map.h"

using namespace std;

vector<char> username;
string user_name;
int stage = 3;
float VIEW_SIZE = 720.0f;
float aspectRatio;
void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_SIZE * aspectRatio, VIEW_SIZE);
}
sf::RenderWindow window(sf::VideoMode(720, 720), "JOSS",sf::Style::Close|sf::Style::Resize);
sf::View view(sf::Vector2f(360.0f, 360.0f), sf::Vector2f(VIEW_SIZE, VIEW_SIZE));

menu Menu(window.getSize().x, window.getSize().y);
login Login(window.getSize().x, window.getSize().y);
void draw_username()
{
    sf::Text US_name;
    sf::Font font;
    font.loadFromFile("FreePixel.ttf");
    US_name.setFont(font);

    user_name = "";
    for (int i = 0; i < username.size(); i++)
    {
        user_name += username[i];
    }

    US_name.setCharacterSize(50);
    if (username.empty())
    {
        US_name.setFillColor(sf::Color(0, 0, 0, 128));
        US_name.setString("ENTER YOUR NAME");
    }
    else
    {
        US_name.setString(user_name);
        US_name.setFillColor(sf::Color::Black);
    }

    US_name.setPosition(183, 254);
    window.draw(US_name);
}

int main()
{
    Map map;

    float x = 18.0f;
    float y = 18.0f;
    float moveSpeed = 6.0f;
    float moveX = 0.0f;
    float moveY = moveSpeed;
    float deltaTime = 0.0f;
    
    char moveChar='s';
    char nextmoveChar = 's';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    float playersize = 36.0f;
    sf::RectangleShape playerDown1(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerDown2(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerLeft1(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerLeft2(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerRight1(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerRight2(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerUp1(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerUp2(sf::Vector2f(playersize, playersize));
    

    sf::Texture playerTextureDown1;
    playerTextureDown1.loadFromFile("slime/Down/1.png");
    playerDown1.setTexture(&playerTextureDown1);
    Animation animationDown1(&playerTextureDown1, sf::Vector2u(4, 1), 0.2f);
    sf::Texture playerTextureDown2;
    playerTextureDown2.loadFromFile("slime/Down/2.png");
    playerDown2.setTexture(&playerTextureDown2);
    playerDown2.setFillColor(sf::Color(0, 255, 255));
    Animation animationDown2(&playerTextureDown2, sf::Vector2u(4, 1), 0.2f);

    sf::Texture playerTextureLeft1;
    playerTextureLeft1.loadFromFile("slime/Left/1.png");
    playerLeft1.setTexture(&playerTextureLeft1);
    Animation animationLeft1(&playerTextureLeft1, sf::Vector2u(2, 1), 0.2f);
    sf::Texture playerTextureLeft2;
    playerTextureLeft2.loadFromFile("slime/Left/2.png");
    playerLeft2.setTexture(&playerTextureLeft2);
    playerLeft2.setFillColor(sf::Color(0, 255, 255));
    Animation animationLeft2(&playerTextureLeft2, sf::Vector2u(2, 1), 0.2f);

    sf::Texture playerTextureRight1;
    playerTextureRight1.loadFromFile("slime/Right/1.png");
    playerRight1.setTexture(&playerTextureRight1);
    Animation animationRight1(&playerTextureRight1, sf::Vector2u(2, 1), 0.2f);
    sf::Texture playerTextureRight2;
    playerTextureRight2.loadFromFile("slime/Right/2.png");
    playerRight2.setTexture(&playerTextureRight2);
    playerRight2.setFillColor(sf::Color(0, 255, 255));
    Animation animationRight2(&playerTextureRight2, sf::Vector2u(2, 1), 0.2f);

    sf::Texture playerTextureUp1;
    playerTextureUp1.loadFromFile("slime/UP/3.png");
    playerUp1.setTexture(&playerTextureUp1);
    Animation animationUp1(&playerTextureUp1, sf::Vector2u(7, 1), 0.1f);
    sf::Texture playerTextureUp2;
    playerTextureUp2.loadFromFile("slime/UP/4.png");
    playerUp2.setTexture(&playerTextureUp2);
    playerUp2.setFillColor(sf::Color(0, 255, 255));
    Animation animationUp2(&playerTextureUp2, sf::Vector2u(7, 1), 0.1f);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        if (stage == 1)
        {
            while (window.pollEvent(event))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (mousePos.x >= window.getSize().x / (720.0f / 28.0f) && mousePos.x <= window.getSize().x / (720.0f / 283.0f) && mousePos.y >= window.getSize().y / (720.0f / 458.0f) && mousePos.y <= window.getSize().y / (720.0f / 533.0f))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        cout << "PLAY" << endl;
                        stage = 2;
                    }
                    Menu.mouseup(0);
                }
                else if (mousePos.x >= window.getSize().x / (720.0f / 438.0f) && mousePos.x <= window.getSize().x / (720.0f / 693.0f) && mousePos.y >= window.getSize().y / (720.0f / 458.0f) && mousePos.y <= window.getSize().y / (720.0f / 533.0f))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        cout << "GUIDE" << endl;
                    }
                    Menu.mouseup(1);
                }
                else if (mousePos.x >= window.getSize().x / (720.0f / 28.0f) && mousePos.x <= window.getSize().x / (720.0f / 283.0f) && mousePos.y >= window.getSize().y / (720.0f / 618.0f) && mousePos.y <= window.getSize().y / (720.0f / 693.0f))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        cout << "SCORE" << endl;
                    }
                    Menu.mouseup(2);
                }
                else if (mousePos.x >= window.getSize().x / (720.0f / 438.0f) && mousePos.x <= window.getSize().x / (720.0f / 693.0f) && mousePos.y >= window.getSize().y / (720.0f / 618.0f) && mousePos.y <= window.getSize().y / (720.0f / 693.0f))
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        cout << "EXIT" << endl;
                        window.close();
                    }
                    Menu.mouseup(3);
                }
                else
                {
                    for (int i = 0; i < 4; i++)
                    {
                        Menu.mousedown(i);
                    }
                }
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }  
            }
                window.clear();
                Menu.draw(window);
                window.display(); 
        }
        if (stage == 2)
        {
            while (window.pollEvent(event))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (event.type == sf::Event::TextEntered)
                    username.push_back(event.text.unicode);
                if (!username.empty() && username.back() == 8)
                {
                    username.pop_back();
                    if (!username.empty())
                        username.pop_back();

                }
                if (mousePos.x >= window.getSize().x / (720.0f / 218.0f) && mousePos.x <= window.getSize().x / (720.0f / 528.0f) && mousePos.y >= window.getSize().y / (720.0f / 514.0f) && mousePos.y <= window.getSize().y / (720.0f / 614.0f))
                {
                    if (username.size() != 1 && !username.empty() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        cout << "START" << endl;
                        stage = 3;
                    }
                    Login.mouseup(1);
                }
                else
                {
                    Login.mousedown(0);
                    Login.mousedown(1);
                }
                if (!username.empty() && !((username.back() >= 'a' && username.back() <= 'z') || (username.back() >= 'A' && username.back() <= 'Z') || (username.back() >= '0' && username.back() <= '9') || username.back() == '_'))
                {
                    username.pop_back();
                }
                if (username.size() > 15)
                {
                    username.pop_back();
                }

                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
                window.clear();
                Login.draw(window);
                draw_username();
                window.display();
        }
        if (stage == 3)
        {
            deltaTime = clock.restart().asSeconds();
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == 's')
                    {
                        nextmoveChar = 's';
                    }
                    else if (event.text.unicode == 'w')
                    {
                        nextmoveChar = 'w';
                    }
                    else if (event.text.unicode == 'a')
                    {
                        nextmoveChar = 'a';
                    }
                    else if (event.text.unicode == 'd')
                    {
                        nextmoveChar = 'd';
                    }
                    
                }
                else if (event.type == sf::Event::Closed)
                {
                    window.close();
                    break;
                }
                else if (event.type == sf::Event::Resized)
                {
                    ResizeView(window, view);
                }
            }
            window.clear();
            window.clear(sf::Color(50, 50, 50));
            //cout << "Next: "<<nextmoveChar << endl;
           
            if (nextmoveChar == 's')
            {
                if (!(map.checkWall(x, y + 18)))
                {
                    moveY = moveSpeed;
                    moveX = 0;
                    moveChar = 's';
                }
            }
            else if (nextmoveChar == 'w')
            {
                if (!(map.checkWall(x, y - 18)))
                {
                    moveY = -moveSpeed;
                    moveX = 0;
                    moveChar = 'w';
                }
            }
            else if (nextmoveChar == 'a')
            {
                if (!(map.checkWall(x-18, y)))
                {
                    moveX = -moveSpeed;
                    moveY = 0;
                    moveChar = 'a';
                }
            }
            else if (nextmoveChar == 'd')
            {
                if (!(map.checkWall(x+ 18, y)))
                {
                    moveX = moveSpeed;
                    moveY = 0;
                    moveChar = 'd';
                }
            }
            //cout << "move: " << moveChar << endl;
            x = x + moveX;
            y = y + moveY;
            if (map.checkWall(x, y))
            {
                x = x - moveX;
                y = y - moveY;
            }
            if (moveChar == 's')
            {
                playerDown1.setPosition(x, y);
                animationDown1.Update(0, deltaTime);
                playerDown1.setTextureRect(animationDown1.uvRect);
                window.draw(playerDown1);
                playerDown2.setPosition(x, y);
                animationDown2.Update(0, deltaTime);
                playerDown2.setTextureRect(animationDown2.uvRect);
                window.draw(playerDown2);
            }
            else if (moveChar == 'a' )
            {
                playerLeft1.setPosition(x, y);
                animationLeft1.Update(0, deltaTime);
                playerLeft1.setTextureRect(animationLeft1.uvRect);
                window.draw(playerLeft1);
                playerLeft2.setPosition(x, y);
                animationLeft2.Update(0, deltaTime);
                playerLeft2.setTextureRect(animationLeft2.uvRect);
                window.draw(playerLeft2);
            }
            else if (moveChar == 'd' )
            {
                playerRight1.setPosition(x, y);
                animationRight1.Update(0, deltaTime);
                playerRight1.setTextureRect(animationRight1.uvRect);
                window.draw(playerRight1);
                playerRight2.setPosition(x, y);
                animationRight2.Update(0, deltaTime);
                playerRight2.setTextureRect(animationRight2.uvRect);
                window.draw(playerRight2);
            }
            else if (moveChar == 'w' )
            {
                playerUp1.setPosition(x, y);
                animationUp1.Update(0, deltaTime);
                playerUp1.setTextureRect(animationUp1.uvRect);
                window.draw(playerUp1);
                playerUp2.setPosition(x, y);
                animationUp2.Update(0, deltaTime);
                playerUp2.setTextureRect(animationUp2.uvRect);
                window.draw(playerUp2);
            }
            map.generate(window);
            window.setView(view);
            window.display();
            Sleep(50);
        }
    }
    return 0;
}