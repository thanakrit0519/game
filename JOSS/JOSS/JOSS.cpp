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
void Show_Text(int score,float cd)
{
    sf::Text Score;
    sf::Text CD;
    sf::Text Life;
    sf::Font font;
    string showscore = "SCORE : ";
    string showcd;
    string showlife = "Life : ";
    showcd += int(cd) + '0';
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
    Score.setCharacterSize(35);
    Score.setFillColor(sf::Color::White);
    Score.setString(showscore);
    Score.setPosition(50, 660);
    window.draw(Score);
    Life.setFont(font);
    Life.setCharacterSize(35);
    Life.setFillColor(sf::Color::White);
    Life.setString(showlife);
    Life.setPosition(50, 600);
    window.draw(Life);
    if (cd>0)
    {
        CD.setFont(font);
        CD.setCharacterSize(50);
        CD.setFillColor(sf::Color::Black);
        CD.setString(showcd);
        CD.setPosition(600, 620);
        window.draw(CD);
    }
    
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

    sf::RectangleShape DeathRed(sf::Vector2f(playersize * 1.5, playersize * 1.5));
    sf::RectangleShape DeathGreen(sf::Vector2f(playersize * 1.5, playersize * 1.5));
    sf::RectangleShape DeathPink(sf::Vector2f(playersize * 1.5, playersize * 1.5));

    sf::RectangleShape GreenDown(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape GreenLeft(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape GreenRight(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape GreenUp(sf::Vector2f(Enemysize, Enemysize));

    sf::RectangleShape Dash_Effect_A(sf::Vector2f(playersize * 2, playersize * 2));
    sf::RectangleShape Dash_Effect_S(sf::Vector2f(playersize * 2, playersize * 2));
    sf::RectangleShape Dash_Effect_W(sf::Vector2f(playersize * 2, playersize * 2));
    sf::RectangleShape Dash_Effect_D(sf::Vector2f(playersize * 2, playersize * 2));

    sf::RectangleShape PinkDown(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape PinkLeft(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape PinkRight(sf::Vector2f(Enemysize, Enemysize));
    sf::RectangleShape PinkUp(sf::Vector2f(Enemysize, Enemysize));

    sf::RectangleShape playerLife1(sf::Vector2f(playersize, playersize));
    sf::RectangleShape playerLife2(sf::Vector2f(playersize, playersize));
    sf::RectangleShape Skill(sf::Vector2f(playersize * 2.5, playersize * 2.5));
    sf::CircleShape BgSkill(50);
    sf::CircleShape BgSkill2(44);
    BgSkill.setFillColor(sf::Color(0, 0, 0));
    sf::Texture playerTextureLife1;
    playerTextureLife1.loadFromFile("slime/icon/1.png");
    playerLife1.setTexture(&playerTextureLife1);
    playerLife2.setTexture(&playerTextureLife1);
    sf::Texture playerTextureSkill;
    playerTextureSkill.loadFromFile("slime/icon/2.png");
    Skill.setTexture(&playerTextureSkill);
    
    
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Texture Death_Texture;
    Death_Texture.loadFromFile("slime/Effect/boom.png");
    DeathRed.setTexture(&Death_Texture);
    Animation animationDeathRed(&Death_Texture, sf::Vector2u(5, 2), 0.1f);
    DeathGreen.setTexture(&Death_Texture);
    Animation animationDeathGreen(&Death_Texture, sf::Vector2u(5, 2), 0.1f);
    DeathPink.setTexture(&Death_Texture);
    Animation animationDeathPink(&Death_Texture, sf::Vector2u(5, 2), 0.1f);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    sf::Texture Dash_Texture_A;
    Dash_Texture_A.loadFromFile("slime/Effect/Fire_ball_A.png");
    Dash_Effect_A.setTexture(&Dash_Texture_A);
    Animation animationDash_A(&Dash_Texture_A, sf::Vector2u(6, 1), 0.1f);

    sf::Texture Dash_Texture_S;
    Dash_Texture_S.loadFromFile("slime/Effect/Fire_ball_S.png");
    Dash_Effect_S.setTexture(&Dash_Texture_S);
    Animation animationDash_S(&Dash_Texture_S, sf::Vector2u(1, 6), 0.1f);

    sf::Texture Dash_Texture_W;
    Dash_Texture_W.loadFromFile("slime/Effect/Fire_ball_W.png");
    Dash_Effect_W.setTexture(&Dash_Texture_W);
    Animation animationDash_W(&Dash_Texture_W, sf::Vector2u(1, 6), 0.1f);

    sf::Texture Dash_Texture_D;
    Dash_Texture_D.loadFromFile("slime/Effect/Fire_ball_D.png");
    Dash_Effect_D.setTexture(&Dash_Texture_D);
    Animation animationDash_D(&Dash_Texture_D, sf::Vector2u(6, 1), 0.1f);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Texture PinkTextureDown;
    PinkTextureDown.loadFromFile("slime/Down/2.png");
    PinkDown.setTexture(&PinkTextureDown);
    PinkDown.setFillColor(sf::Color(255, 20, 147));
    Animation animationPinkDown(&PinkTextureDown, sf::Vector2u(4, 1), 0.2f);

    sf::Texture PinkTextureLeft;
    PinkTextureLeft.loadFromFile("slime/Left/2.png");
    PinkLeft.setTexture(&PinkTextureLeft);
    PinkLeft.setFillColor(sf::Color(255, 20, 147));
    Animation animationPinkLeft(&PinkTextureLeft, sf::Vector2u(2, 1), 0.2f);

    sf::Texture PinkTextureRight;
    PinkTextureRight.loadFromFile("slime/Right/2.png");
    PinkRight.setTexture(&PinkTextureRight);
    PinkRight.setFillColor(sf::Color(255, 20, 147));
    Animation animationPinkRight(&PinkTextureRight, sf::Vector2u(2, 1), 0.2f);

    sf::Texture PinkTextureUp;
    PinkTextureUp.loadFromFile("slime/UP/4.png");
    PinkUp.setTexture(&PinkTextureUp);
    PinkUp.setFillColor(sf::Color(255, 20, 147));
    Animation animationPinkUp(&PinkTextureUp, sf::Vector2u(7, 1), 0.1f);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    int Hp = 2;
    static long long score = 0;
    Map map;
    vector<sf::Vector2f> Coin = map.Loadcoin();
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
            float x = 18.0f;
            float y = 18.0f;
            float moveSpeed = 4.5f;
            float EnemymoveSpeed = 4.5f;
            float moveX = 0.0f;
            float moveY = moveSpeed;
            char moveChar = 's';
            char nextmoveChar = 's';
            

            bool Dash = false;
            int Dash_Count = 0;
            float Dash_cd = 0;

            float RedposX = 18.0f * 14 ;
            float RedposY = (18.0f * 11) ;
            char Redwalk = 'w';
            bool RedDeath = false;
            bool RedDeathAnimation = false;
            float RedDeathposX;
            float RedDeathposY;
            float RedDeathTime=0;

            float GreenposX = 18.0f * 16;
            float GreenposY = (18.0f * 11);
            char Greenwalk = 'a';
            bool GreenDeath = false;
            bool GreenDeathAnimation = false;
            float GreenDeathposX;
            float GreenDeathposY;
            float GreenDeathTime = 0;

            float PinkposX = 18.0f * 20;
            float PinkposY = (18.0f * 11);
            char Pinkwalk = 'a';
            bool PinkDeath = false;
            bool PinkDeathAnimation = false;
            float PinkDeathposX;
            float PinkDeathposY;
            float PinkDeathTime = 0;
            
            float distanceEnemyX, distanceEnemyY;
            float Red_Death_cd=0;
            float Green_Death_cd = 0;
            float Pink_Death_cd = 0;

            
            if (!PLAY && Hp > 0)
            {
                PLAY = true;
                Hp--;
                Sleep(2000);
            }
            else if(Hp==0)stage = 1;
            while (PLAY)
            {
                deltaTime = clock.restart().asSeconds();
                deltaTimered = deltaTime;
                float waitTime = 0.1;
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
                        else if (event.text.unicode == ' ' && Dash_cd <= 0)
                        {
                            Dash = true;
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
                if (Dash && int(x * 10) % 180 == 0 && int(y * 10) % 180 == 0)
                {
                    if (moveX > 0)moveX = 18.0;
                    else if(moveX < 0)moveX = -18.0;
                    else if (moveY > 0)moveY = 18.0;
                    else if (moveY < 0)moveY = -18.0;
                    Dash_Count++;
                    if (Dash_Count == 8)
                    {
                        Dash = false; 
                        Dash_Count = 0;
                        Dash_cd = 9.99;
                    }
                }
                else
                {
                    if (moveX > 0)moveX = 4.5;
                    else if (moveX < 0)moveX = -4.5;
                    else if (moveY > 0)moveY = 4.5;
                    else if (moveY < 0)moveY = -4.5;
                }
                BgSkill2.setFillColor(sf::Color(170, 170, 170));
                if (Dash_cd > 0)
                {
                    BgSkill2.setFillColor(sf::Color(100, 100, 100));
                    Dash_cd -= deltaTimered;
                    //cout << Dash_cd << endl;
                }
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
                
                //cout << score << endl;
                if (moveChar == 's')
                {
                    if (Dash)
                    {
                        Dash_Effect_S.setPosition(x-18, y - 18);
                        animationDash_S.Update(0, deltaTime);
                        Dash_Effect_S.setTextureRect(animationDash_S.uvRect);
                        window.draw(Dash_Effect_S);
                    }
                    else 
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
                }
                else if (moveChar == 'a')
                {
                    if (Dash)
                    {
                        Dash_Effect_A.setPosition(x-10, y - 18);
                        animationDash_A.Update(0, deltaTime);
                        Dash_Effect_A.setTextureRect(animationDash_A.uvRect);
                        window.draw(Dash_Effect_A);
                    }
                    else
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
                }
                else if (moveChar == 'd')
                {
                    if (Dash)
                    {
                        Dash_Effect_D.setPosition(x-20, y - 15);
                        animationDash_D.Update(0, deltaTime);
                        Dash_Effect_D.setTextureRect(animationDash_D.uvRect);
                        window.draw(Dash_Effect_D);
                    }
                    else
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
                }
                else if (moveChar == 'w')
                {
                    if (Dash)
                    {
                        Dash_Effect_W.setPosition(x-18, y - 6);
                        animationDash_W.Update(0, deltaTime);
                        Dash_Effect_W.setTextureRect(animationDash_W.uvRect);
                        window.draw(Dash_Effect_W);
                    }
                    else
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
                }
                distanceEnemyX = x - RedposX;
                distanceEnemyY = y - RedposY;
                if (Redwalk == 'a' || Redwalk == 'd')
                {
                   if (distanceEnemyY >= 0)
                   {
                        if (!map.checkWall(RedposX, RedposY + 18)) Redwalk = 's';
                        else if (!map.checkWall(RedposX, RedposY - 18)) Redwalk = 'w';
                        else if (map.checkWall(RedposX, RedposY))
                        {
                            if (Redwalk == 'd') Redwalk = 'a';
                            else Redwalk = 'd';
                        }
                   }
                   else if (distanceEnemyY < 0)
                   {
                        if(!map.checkWall(RedposX, RedposY - 18)) Redwalk = 'w';
                        else if (!map.checkWall(RedposX, RedposY + 18)) Redwalk = 's';
                        else if (map.checkWall(RedposX, RedposY))
                        {
                            if (Redwalk == 'd') Redwalk = 'a';
                            else Redwalk = 'd';
                        }
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
                if (Greenwalk == 'a' && int(GreenposX * 10) % 180 == 0 && int(GreenposY * 10) % 180 == 0)
                {
                    if (distanceEnemyX > 0)
                    {
                        if (distanceEnemyY >= 0)
                        {
                            if (!map.checkWall(GreenposX, GreenposY + 18)) Greenwalk = 's';
                            else if (!map.checkWall(GreenposX, GreenposY - 18)) Greenwalk = 'w';
                            //else Greenwalk = 'd';
                        }
                        else if (distanceEnemyY < 0)
                        {
                            if (!map.checkWall(GreenposX, GreenposY - 18)) Greenwalk = 'w';
                            else if (!map.checkWall(GreenposX, GreenposY + 18)) Greenwalk = 's';
                            //else Greenwalk = 'd';
                        }
                    }
                    else
                    {
                        if (!map.checkWall(GreenposX-4.5 , GreenposY)) Greenwalk = 'a';
                        else if (distanceEnemyY >= 0)
                        {
                            if (!map.checkWall(GreenposX, GreenposY + 18)) Greenwalk = 's';
                            else if (!map.checkWall(GreenposX, GreenposY - 18)) Greenwalk = 'w';
                            else Greenwalk = 'd';
                        }
                        else if (distanceEnemyY < 0)
                        {
                            if (!map.checkWall(GreenposX, GreenposY - 18)) Greenwalk = 'w';
                            else if (!map.checkWall(GreenposX, GreenposY + 18)) Greenwalk = 's';
                            else Greenwalk = 'd';
                        }
                    }
                }
                else if (Greenwalk == 'd' && int(GreenposX *10)%180 == 0 && int(GreenposY * 10) % 180 == 0)
                {
                    if (distanceEnemyX > 0)
                    {
                        if (!map.checkWall(GreenposX + 4.0, GreenposY)) Greenwalk = 'd';
                        else if (distanceEnemyY >= 0)
                        {
                            if (!map.checkWall(GreenposX, GreenposY + 18)) Greenwalk = 's';
                            else if (!map.checkWall(GreenposX, GreenposY - 18)) Greenwalk = 'w';
                            else Greenwalk = 'a';
                        }
                        else if (distanceEnemyY < 0)
                        {
                            if (!map.checkWall(GreenposX, GreenposY - 18)) Greenwalk = 'w';
                            else if (!map.checkWall(GreenposX, GreenposY + 18)) Greenwalk = 's';
                            else Greenwalk = 'a';
                        }
                    }
                    else
                    {
                        if (distanceEnemyY >= 0)
                        {
                            if (!map.checkWall(GreenposX, GreenposY + 18.0)) Greenwalk = 's';
                            else if (!map.checkWall(GreenposX, GreenposY - 18.0)) Greenwalk = 'w';
                            else if (map.checkWall(GreenposX+18.0, GreenposY)) Greenwalk = 'a';
                            else Greenwalk = 'd';
                        }
                        else if (distanceEnemyY < 0)
                        {
                            if (!map.checkWall(GreenposX, GreenposY - 18.0)) Greenwalk = 'w';
                            else if (!map.checkWall(GreenposX, GreenposY + 18.0)) Greenwalk = 's';
                            else if (map.checkWall(GreenposX + 18.0, GreenposY)) Greenwalk = 'a';
                            else Greenwalk = 'd';
                        }
                    }
                }
                else if (Greenwalk == 's' && int(GreenposX * 10) % 180 == 0 && int(GreenposY * 10) % 180 == 0)
                {
                    if (distanceEnemyY > 0)
                    {
                        if(!map.checkWall(GreenposX, GreenposY + 18)) Greenwalk = 's';
                        else if (distanceEnemyX >= 0)
                        {
                            if (!map.checkWall(GreenposX+18, GreenposY)) Greenwalk = 'd';
                            else if (!map.checkWall(GreenposX-18, GreenposY)) Greenwalk = 'a';
                            //else Greenwalk = 'w';
                        }
                        else if (distanceEnemyX < 0)
                        {
                            if (!map.checkWall(GreenposX-18, GreenposY)) Greenwalk = 'a';
                            else if (!map.checkWall(GreenposX+18, GreenposY)) Greenwalk = 'd';
                            //else Greenwalk = 'w';
                        }
                    }
                    else
                    {
                        if (distanceEnemyX >= 0)
                        {
                            if (!map.checkWall(GreenposX + 18, GreenposY)) Greenwalk = 'd';
                            else if (!map.checkWall(GreenposX - 18, GreenposY)) Greenwalk = 'a';
                            //else Greenwalk = 's';
                        }
                        else if (distanceEnemyX < 0)
                        {
                            if (!map.checkWall(GreenposX - 18, GreenposY)) Greenwalk = 'a';
                            else if (!map.checkWall(GreenposX + 18, GreenposY)) Greenwalk = 'd';
                            //else Greenwalk = 's';
                        }
                    }
                }
                else if (Greenwalk == 'w' && int(GreenposX * 10) % 180 == 0 && int(GreenposY * 10) % 180 == 0)
                {
                    if (distanceEnemyY < 0)
                    {
                        if (!map.checkWall(GreenposX, GreenposY - 18)) Greenwalk = 'w';
                        else if (distanceEnemyX >= 0)
                        {
                            if (!map.checkWall(GreenposX + 18, GreenposY)) Greenwalk = 'd';
                            else if (!map.checkWall(GreenposX - 18, GreenposY)) Greenwalk = 'a';
                            //else Greenwalk = 's';
                        }
                        else if (distanceEnemyX < 0)
                        {
                            if (!map.checkWall(GreenposX - 18, GreenposY)) Greenwalk = 'a';
                            else if (!map.checkWall(GreenposX + 18, GreenposY)) Greenwalk = 'd';
                            //else Greenwalk = 's';
                        }
                    }
                    else
                    {
                        if (distanceEnemyX >= 0)
                        {
                            if (!map.checkWall(GreenposX + 18, GreenposY)) Greenwalk = 'd';
                            else if (!map.checkWall(GreenposX - 18, GreenposY)) Greenwalk = 'a';
                            //else Greenwalk = 'w';
                        }
                        else if (distanceEnemyX < 0)
                        {
                            if (!map.checkWall(GreenposX - 18, GreenposY)) Greenwalk = 'a';
                            else if (!map.checkWall(GreenposX + 18, GreenposY)) Greenwalk = 'd';
                            //else Greenwalk = 'w';
                        }
                    }
                }
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                float PinkTargetX=x;
                float PinkTargetY=y;
                /*while (!map.checkWall(PinkTargetX, PinkTargetY))
                {

                }*/
                distanceEnemyX = x - PinkposX;
                distanceEnemyY = y - PinkposY;
                if (Pinkwalk == 'a' && int(PinkposX * 10) % 180 == 0 && int(PinkposY * 10) % 180 == 0)
                {
                    if (distanceEnemyX > 0)
                    {
                        if (distanceEnemyY >= 0)
                        {
                            if (!map.checkWall(PinkposX, PinkposY + 18)) Pinkwalk = 's';
                            else if (!map.checkWall(PinkposX, PinkposY - 18)) Pinkwalk = 'w';
                            //else Greenwalk = 'd';
                        }
                        else if (distanceEnemyY < 0)
                        {
                            if (!map.checkWall(PinkposX, PinkposY - 18)) Pinkwalk = 'w';
                            else if (!map.checkWall(PinkposX, PinkposY + 18)) Pinkwalk = 's';
                            //else Greenwalk = 'd';
                        }
                    }
                    else
                    {
                        if (!map.checkWall(PinkposX - 4.5, PinkposY)) Pinkwalk = 'a';
                        else if (distanceEnemyY >= 0)
                        {
                            if (!map.checkWall(PinkposX, PinkposY + 18)) Pinkwalk = 's';
                            else if (!map.checkWall(PinkposX, PinkposY - 18)) Pinkwalk = 'w';
                            else Pinkwalk = 'd';
                        }
                        else if (distanceEnemyY < 0)
                        {
                            if (!map.checkWall(PinkposX, PinkposY - 18)) Pinkwalk = 'w';
                            else if (!map.checkWall(PinkposX, PinkposY + 18)) Pinkwalk = 's';
                            else Pinkwalk = 'd';
                        }
                    }
                }
                else if (Pinkwalk == 'd' && int(PinkposX * 10) % 180 == 0 && int(PinkposY * 10) % 180 == 0)
                {
                    if (distanceEnemyX > 0)
                    {
                        if (!map.checkWall(PinkposX + 4.0, PinkposY)) Pinkwalk = 'd';
                        else if (distanceEnemyY >= 0)
                        {
                            if (!map.checkWall(PinkposX, PinkposY + 18)) Pinkwalk = 's';
                            else if (!map.checkWall(PinkposX, PinkposY - 18)) Pinkwalk = 'w';
                            else Pinkwalk = 'a';
                        }
                        else if (distanceEnemyY < 0)
                        {
                            if (!map.checkWall(PinkposX, PinkposY - 18)) Pinkwalk = 'w';
                            else if (!map.checkWall(PinkposX, PinkposY + 18)) Pinkwalk = 's';
                            else Pinkwalk = 'a';
                        }
                    }
                    else
                    {
                        if (distanceEnemyY >= 0)
                        {
                            if (!map.checkWall(PinkposX, PinkposY + 18.0)) Pinkwalk = 's';
                            else if (!map.checkWall(PinkposX, PinkposY - 18.0)) Pinkwalk = 'w';
                            else if (map.checkWall(PinkposX + 18.0, PinkposY)) Pinkwalk = 'a';
                            else Pinkwalk = 'd';
                        }
                        else if (distanceEnemyY < 0)
                        {
                            if (!map.checkWall(PinkposX, PinkposY - 18.0)) Pinkwalk = 'w';
                            else if (!map.checkWall(PinkposX, PinkposY + 18.0)) Pinkwalk = 's';
                            else if (map.checkWall(PinkposX + 18.0, PinkposY)) Pinkwalk = 'a';
                            else Pinkwalk = 'd';
                        }
                    }
                }
                else if (Pinkwalk == 's' && int(PinkposX * 10) % 180 == 0 && int(PinkposY * 10) % 180 == 0)
                {
                    if (distanceEnemyY > 0)
                    {
                        if (!map.checkWall(PinkposX, PinkposY + 18)) Pinkwalk = 's';
                        else if (distanceEnemyX >= 0)
                        {
                            if (!map.checkWall(PinkposX + 18, PinkposY)) Pinkwalk = 'd';
                            else if (!map.checkWall(PinkposX - 18, PinkposY)) Pinkwalk = 'a';
                            //else Greenwalk = 'w';
                        }
                        else if (distanceEnemyX < 0)
                        {
                            if (!map.checkWall(PinkposX - 18, PinkposY)) Pinkwalk = 'a';
                            else if (!map.checkWall(PinkposX + 18, PinkposY)) Pinkwalk = 'd';
                            //else Greenwalk = 'w';
                        }
                    }
                    else
                    {
                        if (distanceEnemyX >= 0)
                        {
                            if (!map.checkWall(PinkposX + 18, PinkposY)) Pinkwalk = 'd';
                            else if (!map.checkWall(PinkposX - 18, PinkposY)) Pinkwalk = 'a';
                            //else Greenwalk = 's';
                        }
                        else if (distanceEnemyX < 0)
                        {
                            if (!map.checkWall(PinkposX - 18, PinkposY)) Pinkwalk = 'a';
                            else if (!map.checkWall(PinkposX + 18, PinkposY)) Pinkwalk = 'd';
                            //else Greenwalk = 's';
                        }
                    }
                }
                else if (Pinkwalk == 'w' && int(PinkposX * 10) % 180 == 0 && int(PinkposY * 10) % 180 == 0)
                {
                    if (distanceEnemyY < 0)
                    {
                        if (!map.checkWall(PinkposX, PinkposY - 18)) Pinkwalk = 'w';
                        else if (distanceEnemyX >= 0)
                        {
                            if (!map.checkWall(PinkposX + 18, PinkposY)) Pinkwalk = 'd';
                            else if (!map.checkWall(PinkposX - 18, PinkposY)) Pinkwalk = 'a';
                            //else Greenwalk = 's';
                        }
                        else if (distanceEnemyX < 0)
                        {
                            if (!map.checkWall(PinkposX - 18, PinkposY)) Pinkwalk = 'a';
                            else if (!map.checkWall(PinkposX + 18, PinkposY)) Pinkwalk = 'd';
                            //else Greenwalk = 's';
                        }
                    }
                    else
                    {
                        if (distanceEnemyX >= 0)
                        {
                            if (!map.checkWall(PinkposX + 18, PinkposY)) Pinkwalk = 'd';
                            else if (!map.checkWall(PinkposX - 18, PinkposY)) Pinkwalk = 'a';
                            //else Greenwalk = 'w';
                        }
                        else if (distanceEnemyX < 0)
                        {
                            if (!map.checkWall(PinkposX - 18, PinkposY)) Pinkwalk = 'a';
                            else if (!map.checkWall(PinkposX + 18, PinkposY)) Pinkwalk = 'd';
                            //else Greenwalk = 'w';
                        }
                    }
                }
                //cout << Redwalk << endl;
                map.generatecoin(window, Coin);
      
                if (RedDeath)
                {
                    RedposX = 18.0f * 14;
                    RedposY = (18.0f * 11);
                    Redwalk = 'd';
                    Red_Death_cd += deltaTimered;
                    if (Red_Death_cd >= 2.0f)
                    {
                        RedDeath = false;
                        Red_Death_cd = 0;
                    }
                }
                if (RedDeathAnimation)
                {
                    DeathRed.setPosition(RedDeathposX -12, RedDeathposY - 12);
                    animationDeathRed.Update(0, deltaTimered);
                    DeathRed.setTextureRect(animationDeathRed.uvRect);
                    window.draw(DeathRed);
                    RedDeathTime += deltaTimered;
                    if (RedDeathTime >= 0.8f) RedDeathAnimation = false , RedDeathTime = 0;
                }

                if (GreenDeath)
                {
                    GreenposX = 18.0f * 16;
                    GreenposY = (18.0f * 11);
                    Greenwalk = 'd';
                    Green_Death_cd += deltaTimered;
                    if (Green_Death_cd >= 2.0f)
                    {
                        GreenDeath = false;
                        Green_Death_cd = 0;
                    }
                }
                if (GreenDeathAnimation)
                {
                    DeathGreen.setPosition(GreenDeathposX - 12, GreenDeathposY - 12);
                    animationDeathGreen.Update(0, deltaTimered);
                    DeathGreen.setTextureRect(animationDeathGreen.uvRect);
                    window.draw(DeathGreen);
                    GreenDeathTime += deltaTimered;
                    if (GreenDeathTime >= 0.8f) GreenDeathAnimation = false, GreenDeathTime = 0;
                }

                if (PinkDeath)
                {
                    PinkposX = 18.0f * 20;
                    PinkposY = (18.0f * 11);
                    Pinkwalk = 'd';
                    Pink_Death_cd += deltaTimered;
                    if (Pink_Death_cd >= 2.0f)
                    {
                        PinkDeath = false;
                        Pink_Death_cd = 0;
                    }
                }
                if (PinkDeathAnimation)
                {
                    DeathPink.setPosition(PinkDeathposX - 12, PinkDeathposY - 12);
                    animationDeathPink.Update(0, deltaTimered);
                    DeathPink.setTextureRect(animationDeathPink.uvRect);
                    window.draw(DeathPink);
                    PinkDeathTime += deltaTimered;
                    if (PinkDeathTime >= 0.8f) PinkDeathAnimation = false, PinkDeathTime = 0;
                }

                if (Redwalk == 'a')
                {
                    RedposX -= EnemymoveSpeed;
                    RedLeft.setPosition(RedposX-3, RedposY - 12);
                    animationRedLeft.Update(0, deltaTimered);
                    RedLeft.setTextureRect(animationRedLeft.uvRect);
                    window.draw(RedLeft);
                }
                else if (Redwalk == 'd')
                {
                    RedposX += EnemymoveSpeed;
                    RedRight.setPosition(RedposX-3, RedposY - 12);
                    animationRedRight.Update(0, deltaTimered);
                    RedRight.setTextureRect(animationRedRight.uvRect);
                    window.draw(RedRight);
                }
                else if (Redwalk == 'w')
                {
                    RedposY -= EnemymoveSpeed;
                    RedUp.setPosition(RedposX-3, RedposY - 12);
                    animationRedUp.Update(0, deltaTimered);
                    RedUp.setTextureRect(animationRedUp.uvRect);
                    window.draw(RedUp);
                }
                else if (Redwalk == 's')
                {
                    RedposY += EnemymoveSpeed;
                    RedDown.setPosition(RedposX-3, RedposY - 12);
                    animationRedDown.Update(0, deltaTimered);
                    RedDown.setTextureRect(animationRedDown.uvRect);
                    window.draw(RedDown);
                }

                if (Greenwalk == 'a')
                {
                    GreenposX -= EnemymoveSpeed;
                    GreenLeft.setPosition(GreenposX - 3, GreenposY - 12);
                    animationGreenLeft.Update(0, deltaTimered);
                    GreenLeft.setTextureRect(animationGreenLeft.uvRect);
                    window.draw(GreenLeft);
                }
                else if (Greenwalk == 'd')
                {
                    GreenposX += EnemymoveSpeed;
                    GreenRight.setPosition(GreenposX - 3, GreenposY - 12);
                    animationGreenRight.Update(0, deltaTimered);
                    GreenRight.setTextureRect(animationGreenRight.uvRect);
                    window.draw(GreenRight);
                }
                else if (Greenwalk == 'w')
                {
                    GreenposY -= EnemymoveSpeed;
                    GreenUp.setPosition(GreenposX - 3, GreenposY - 12);
                    animationGreenUp.Update(0, deltaTimered);
                    GreenUp.setTextureRect(animationGreenUp.uvRect);
                    window.draw(GreenUp);
                }
                else if (Greenwalk == 's')
                {
                    GreenposY += EnemymoveSpeed;
                    GreenDown.setPosition(GreenposX - 3, GreenposY - 12);
                    animationGreenDown.Update(0, deltaTimered);
                    GreenDown.setTextureRect(animationGreenDown.uvRect);
                    window.draw(GreenDown);
                }

                if (Pinkwalk == 'a')
                {
                    PinkposX -= EnemymoveSpeed;
                    PinkLeft.setPosition(PinkposX - 3, PinkposY - 12);
                    animationPinkLeft.Update(0, deltaTimered);
                    PinkLeft.setTextureRect(animationPinkLeft.uvRect);
                    window.draw(PinkLeft);
                }
                else if (Pinkwalk == 'd')
                {
                    PinkposX += EnemymoveSpeed;
                    PinkRight.setPosition(PinkposX - 3, PinkposY - 12);
                    animationPinkRight.Update(0, deltaTimered);
                    PinkRight.setTextureRect(animationPinkRight.uvRect);
                    window.draw(PinkRight);
                }
                else if (Pinkwalk == 'w')
                {
                    PinkposY -= EnemymoveSpeed;
                    PinkUp.setPosition(PinkposX - 3, PinkposY - 12);
                    animationPinkUp.Update(0, deltaTimered);
                    PinkUp.setTextureRect(animationPinkUp.uvRect);
                    window.draw(PinkUp);
                }
                else if (Pinkwalk == 's')
                {
                    PinkposY += EnemymoveSpeed;
                    PinkDown.setPosition(PinkposX - 3, PinkposY - 12);
                    animationPinkDown.Update(0, deltaTimered);
                    PinkDown.setTextureRect(animationPinkDown.uvRect);
                    window.draw(PinkDown);
                }
                //                                                                                                                         P                                            E
                // |                   P E                    |                         E P                        |                       E                    |                       P                  |
                if ((((x + 39.0 >= RedposX) && (x -3<= RedposX)) || ((RedposX + 39.0 >= x) && (RedposX  -3<= x))) && (((y + 24.0 >= RedposY) && (y <= RedposY)) || ((RedposY + 24.0 >= y) && (RedposY <= y))))
                {
                    if (Dash)
                    {
                        RedDeath = true; 
                        RedDeathAnimation = true;
                        RedDeathposX = RedposX;
                        RedDeathposY = RedposY;
                        score += 3000;
                    }
                    else PLAY = false;
                }
                if ((((x + 39.0 >= GreenposX) && (x - 3 <= GreenposX)) || ((GreenposX + 39.0 >= x) && (GreenposX - 3 <= x))) && (((y + 24.0 >= GreenposY) && (y <= GreenposY)) || ((GreenposY + 24.0 >= y) && (GreenposY <= y))))
                {
                    if (Dash)
                    {
                        GreenDeath = true;
                        GreenDeathAnimation = true;
                        GreenDeathposX = GreenposX;
                        GreenDeathposY = GreenposY;
                        score += 3000;
                    }
                    else PLAY = false;
                }
                if ((((x + 39.0 >= PinkposX) && (x - 3 <= PinkposX)) || ((PinkposX + 39.0 >= x) && (PinkposX - 3 <= x))) && (((y + 24.0 >= PinkposY) && (y <= PinkposY)) || ((PinkposY + 24.0 >= y) && (PinkposY <= y))))
                {
                    if (Dash)
                    {
                        PinkDeath = true;
                        PinkDeathAnimation = true;
                        PinkDeathposX = PinkposX;
                        PinkDeathposY = PinkposY;
                        score += 3000;
                    }
                    else PLAY = false;
                }

                if (Hp > 0)
                {
                    playerLife1.setPosition(170, 600);
                    window.draw(playerLife1);
                    if (Hp > 1)
                    {
                        playerLife2.setPosition(215, 600);
                        window.draw(playerLife2);
                    }
                }
                BgSkill.setPosition(560, 605);
                window.draw(BgSkill);
                BgSkill2.setPosition(566, 611);
                window.draw(BgSkill2);
                Skill.setPosition(565, 614);
                window.draw(Skill);
                Show_Text(score, Dash_cd);
                map.generate(window);
                window.setView(view);
                window.display();
                while (waitTime>0)
                {
                    waitTime -= deltaTimered;
                }
                
                //Sleep(50);
            }
        }
    }
    return 0;
}