#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "map.h"

void Map::generate(sf::RenderWindow& window)
{
    std::vector <sf::Vector2f> map;
    sf::RectangleShape block(sf::Vector2f(18.0f, 18.0f));

    std::ifstream openfile("Map.txt");
    if (openfile.is_open())
    {
        std::string line;
        int lineCount = 0;
        while (std::getline(openfile, line))
        {

            for (int column = 0; column < line.length(); column++)
            {
                if (line[column] == '1')
                {
                    sf::Vector2f blockPos = { 18.0f * (column),18.0f * (lineCount) };
                    map.push_back(blockPos);
                }
            }
            lineCount++;
        }
    }
    tilemap = map;
    for (int i = 0; i < map.size(); i++)
    {
        block.setPosition(map[i].x, map[i].y);
        window.draw(block);
    }

}
bool Map::checkWall(float x, float y)
{
    for (int i = 0; i < tilemap.size(); i++)
    {
        if ((tilemap[i].x < x + 36) && (tilemap[i].x + 18> x) && (tilemap[i].y < y + 36) && (tilemap[i].y +18> y))
        {
            return true;
        }

    }
    return false;
}
