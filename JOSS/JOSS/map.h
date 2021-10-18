#pragma once
#include <SFML/Graphics.hpp>

class Map
{

    std::vector <sf::Vector2f> tilemap;

public:
    void generate(sf::RenderWindow& window); 
    bool checkWall(float x, float y);
    std::vector <sf::Vector2f> getTilemap();
};

