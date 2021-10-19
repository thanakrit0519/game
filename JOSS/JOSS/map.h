#pragma once
#include <SFML/Graphics.hpp>

class Map
{

    std::vector <sf::Vector2f> tilemap;
    std::vector <sf::Vector2f> tilecoin;
    int score=0;

public:
    void generate(sf::RenderWindow& window); 
    bool checkWall(float x, float y);
    int UpdateScore();
    std::vector <sf::Vector2f> checkCoin(std::vector <sf::Vector2f> tilecoin, float x, float y);
    std::vector <sf::Vector2f> Loadcoin();
    void generatecoin(sf::RenderWindow& window, std::vector <sf::Vector2f> tilecoin);
};

