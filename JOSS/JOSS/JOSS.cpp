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
void Show_score(int score)
{
    sf::Text Score;
    sf::Font font;
    string showscore = "SCORE : ";
    int count = 0;
    int check = score;
    while (check>=10)
    {
        check /= 10;
        count++;
    }
    for (int i = count; i >= 0; i--)
    {
        showscore += ((score / pow(10, i))+'0');
        int x = pow(10, i);
        score %= x;
    }
    font.loadFromFile("FreePixel.ttf");
    Score.setFont(font);
    Score.setCharacterSize(50);
    Score.setFillColor(sf::Color::White);
    Score.setString(showscore);
    Score.setPosition(100, 600);
    window.draw(Score);
}
int main()
{
    float deltaTime = 0.0f;
    float deltaTimered = 0.0f;
    bool PLAY = true;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    float playersize = 36.0f;
    float Enemysize = playersize * 1.2f;
    sf::RectangleShape playerDown1(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerDown2(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerLeft1(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerLeft2(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerRight1(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerRight2(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerUp1(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerUp2(sf::Vector2f(playersize, playersize));

    sf::RectangleShape RedDown(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape RedLeft(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape RedRight(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape RedUp(sf::Vector2f(Enemysize, Enemysize));

    sf::RectangleShape GreenDown(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape GreenLeft(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape GreenRight(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape GreenUp(sf::Vector2f(Enemysize, Enemysize));
    
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
    sf::Texture RedTextureDown;
    RedTextureDown.loadFromFile("slime/Down/2.png");
    RedDown.setTexture(&RedTextureDown);
    RedDown.setFillColor(sf::Color(255, 35, 45));
    Animation animationRedDown(&RedTextureDown, sf::Vector2u(4, 1), 0.2f);

    sf::Texture RedTextureLeft;
    RedTextureLeft.loadFromFile("slime/Left/2.png");
    RedLeft.setTexture(&RedTextureLeft);
    RedLeft.setFillColor(sf::Color(255, 35, 45));
    Animation animationRedLeft(&RedTextureLeft, sf::Vector2u(2, 1), 0.2f);

    sf::Texture RedTextureRight;
    RedTextureRight.loadFromFile("slime/Right/2.png");
    RedRight.setTexture(&RedTextureRight);
    RedRight.setFillColor(sf::Color(255, 35, 45));
    Animation animationRedRight(&RedTextureRight, sf::Vector2u(2, 1), 0.2f);

    sf::Texture RedTextureUp;
    RedTextureUp.loadFromFile("slime/UP/4.png");
    RedUp.setTexture(&RedTextureUp);
    RedUp.setFillColor(sf::Color(255, 35, 45));
    Animation animationRedUp(&RedTextureUp, sf::Vector2u(7, 1), 0.1f);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Texture GreenTextureDown;
    GreenTextureDown.loadFromFile("slime/Down/2.png");
    GreenDown.setTexture(&GreenTextureDown);
    GreenDown.setFillColor(sf::Color(50, 255, 50));
    Animation animationGreenDown(&GreenTextureDown, sf::Vector2u(4, 1), 0.2f);

    sf::Texture GreenTextureLeft;
    GreenTextureLeft.loadFromFile("slime/Left/2.png");
    GreenLeft.setTexture(&GreenTextureLeft);
    GreenLeft.setFillColor(sf::Color(50, 255, 50));
    Animation animationGreenLeft(&GreenTextureLeft, sf::Vector2u(2, 1), 0.2f);

    sf::Texture GreenTextureRight;
    GreenTextureRight.loadFromFile("slime/Right/2.png");
    GreenRight.setTexture(&GreenTextureRight);
    GreenRight.setFillColor(sf::Color(50, 255, 50));
    Animation animationGreenRight(&GreenTextureRight, sf::Vector2u(2, 1), 0.2f);

    sf::Texture GreenTextureUp;
    GreenTextureUp.loadFromFile("slime/UP/4.png");
    GreenUp.setTexture(&GreenTextureUp);
    GreenUp.setFillColor(sf::Color(50, 255, 50));
    Animation animationGreenUp(&GreenTextureUp, sf::Vector2u(7, 1), 0.1f);

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
            Map map;
            static long long score = 0;
            float x = 18.0f;
            float y = 18.0f;
            float moveSpeed = 6.0f;
            float EnemymoveSpeed = 4.5f;
            float moveX = 0.0f;
            float moveY = moveSpeed;
            vector<sf::Vector2f> Coin = map.Loadcoin();
            char moveChar = 's';
            char nextmoveChar = 's';

            float RedposX = 18.0f * 14 ;
            float RedposY = (18.0f * 11) ;
            char Redwalk = 'w';
            float GreenposX = 18.0f * 16;
            float GreenposY = (18.0f * 11);
            char Greenwalk = 'w';

            float distanceEnemyX, distanceEnemyY;
            int totalWay = 0;
            if (!PLAY)
            {
                PLAY = true;
                Sleep(3000);
            }
            while (PLAY)
            {
                deltaTime = clock.restart().asSeconds();
                deltaTimered = deltaTime;
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
                    if (!(map.checkWall(x - 18, y)))
                    {
                        moveX = -moveSpeed;
                        moveY = 0;
                        moveChar = 'a';
                    }
                }
                else if (nextmoveChar == 'd')
                {
                    if (!(map.checkWall(x + 18, y)))
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
                Coin = map.checkCoin(Coin, x, y);
                if (Coin.empty())
                {
                    PLAY = false;
                }
                score = map.UpdateScore();
                Show_score(score);
                //cout << score << endl;
                if (moveChar == 's')
                {
                    playerDown1.setPosition(x, y - 6);
                    animationDown1.Update(0, deltaTime);
                    playerDown1.setTextureRect(animationDown1.uvRect);
                    window.draw(playerDown1);
                    playerDown2.setPosition(x, y - 6);
                    animationDown2.Update(0, deltaTime);
                    playerDown2.setTextureRect(animationDown2.uvRect);
                    window.draw(playerDown2);
                }
                else if (moveChar == 'a')
                {
                    playerLeft1.setPosition(x, y - 6);
                    animationLeft1.Update(0, deltaTime);
                    playerLeft1.setTextureRect(animationLeft1.uvRect);
                    window.draw(playerLeft1);
                    playerLeft2.setPosition(x, y - 6);
                    animationLeft2.Update(0, deltaTime);
                    playerLeft2.setTextureRect(animationLeft2.uvRect);
                    window.draw(playerLeft2);
                }
                else if (moveChar == 'd')
                {
                    playerRight1.setPosition(x, y - 6);
                    animationRight1.Update(0, deltaTime);
                    playerRight1.setTextureRect(animationRight1.uvRect);
                    window.draw(playerRight1);
                    playerRight2.setPosition(x, y - 6);
                    animationRight2.Update(0, deltaTime);
                    playerRight2.setTextureRect(animationRight2.uvRect);
                    window.draw(playerRight2);
                }
                else if (moveChar == 'w')
                {
                    playerUp1.setPosition(x, y - 6);
                    animationUp1.Update(0, deltaTime);
                    playerUp1.setTextureRect(animationUp1.uvRect);
                    window.draw(playerUp1);
                    playerUp2.setPosition(x, y - 6);
                    animationUp2.Update(0, deltaTime);
                    playerUp2.setTextureRect(animationUp2.uvRect);
                    window.draw(playerUp2);
                }
                distanceEnemyX = x - RedposX;
                distanceEnemyY = y - RedposY;
                if (Redwalk == 'a' || Redwalk == 'd')
                {
                   if (distanceEnemyY >= 0)
                   {
                            if (!map.checkWall(RedposX, RedposY + 18)) Redwalk = 's';
                            else if (!map.checkWall(RedposX, RedposY - 18)) Redwalk = 'w';
                            else if(map.checkWall(RedposX , RedposY)) Redwalk = 'a';
                   }
                   else if (distanceEnemyY < 0)
                   {
                            if(!map.checkWall(RedposX, RedposY - 18)) Redwalk = 'w';
                            else if (!map.checkWall(RedposX, RedposY + 18)) Redwalk = 's';
                            else if (map.checkWall(RedposX , RedposY)) Redwalk = 'd';
                   }
                }
                    else if (Redwalk == 'w' || Redwalk == 's')
                    {
                        if (distanceEnemyX >= 0)
                        {
                            if(!map.checkWall(RedposX + 18, RedposY)) Redwalk = 'd';
                            else if (!map.checkWall(RedposX - 18, RedposY)) Redwalk = 'a';
                        }
                        else if (distanceEnemyX < 0)
                        {
                            if (!map.checkWall(RedposX - 18, RedposY)) Redwalk = 'a';
                            else if (!map.checkWall(RedposX + 18, RedposY)) Redwalk = 'd';
                        }
                    }
                distanceEnemyX = x - GreenposX;
                distanceEnemyY = y - GreenposY;

                    //cout << Redwalk << endl;
                    map.generatecoin(window, Coin);

                    GreenDown.setPosition(GreenposX - 3, GreenposY - 9);
                    animationGreenDown.Update(0, deltaTimered);
                    GreenDown.setTextureRect(animationGreenDown.uvRect);
                    window.draw(GreenDown);
                if (Redwalk == 'a')
                {
                    RedposX -= EnemymoveSpeed;
                    RedLeft.setPosition(RedposX-3, RedposY - 9);
                    animationRedLeft.Update(0, deltaTimered);
                    RedLeft.setTextureRect(animationRedLeft.uvRect);
                    window.draw(RedLeft);
                }
                else if (Redwalk == 'd')
                {
                    RedposX += EnemymoveSpeed;
                    RedRight.setPosition(RedposX-3, RedposY - 9);
                    animationRedRight.Update(0, deltaTimered);
                    RedRight.setTextureRect(animationRedRight.uvRect);
                    window.draw(RedRight);
                }
                else if (Redwalk == 'w')
                {
                    RedposY -= EnemymoveSpeed;
                    RedUp.setPosition(RedposX-3, RedposY - 9);
                    animationRedUp.Update(0, deltaTimered);
                    RedUp.setTextureRect(animationRedUp.uvRect);
                    window.draw(RedUp);
                }
                else if (Redwalk == 's')
                {
                    RedposY += EnemymoveSpeed;
                    RedDown.setPosition(RedposX-3, RedposY - 9);
                    animationRedDown.Update(0, deltaTimered);
                    RedDown.setTextureRect(animationRedDown.uvRect);
                    window.draw(RedDown);
                }
                //                                                                                                                         P                                            E
                // |                   P E                    |                         E P                        |                       E                    |                       P                  |
                if ((((x + 39.0 >= RedposX) && (x <= RedposX)) || ((RedposX + 36.0 >= x) && (RedposX - 3.0 <= x))) && (((y + 23.0 >= RedposY) && (y <= RedposY)) || ((RedposY + 24.0 >= y) && (RedposY <= y))))
                {
                    PLAY = false;
                }
                map.generate(window);
                window.setView(view);
                window.display();
                Sleep(50);
            }
        }
    }
    return 0;
}