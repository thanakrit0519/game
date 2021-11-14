#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "map.h"
sf::CircleShape coin(3.0f);

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
        if ((tilemap[i].x < x + 36.0) && (tilemap[i].x + 18.0> x) && (tilemap[i].y < y + 36.0) && (tilemap[i].y +18.0> y))
        {
            return true;
        }

    }
    return false;
}

int Map::UpdateScore()
{
    return score;
}

std::vector <sf::Vector2f> Map::checkCoin(std::vector <sf::Vector2f> Coin,float x, float y)
{
    for (int i = 0; i < Coin.size(); i++)
    {//           Right                     Left                      Down                  Top
        if ((Coin[i].x < x +24) && (Coin[i].x + 3 > x) && (Coin[i].y < y + 24) && (Coin[i].y + 3 > y))
        {
            Coin.erase(Coin.begin() + i);
            score = 100;
            break;
        }
        else score = 0;
    }
    return Coin;
}

std::vector<sf::Vector2f> Map::Loadcoin()
{
    std::vector <sf::Vector2f> coinpos;
    std::ifstream openfile("Map.txt");
    if (openfile.is_open())
    {
        std::string line;
        int lineCount = 0;
        while (std::getline(openfile, line))
        {

            for (int column = 0; column < line.length(); column++)
            {
                if (line[column] == '2')
                {
                    coinpos.push_back({ 18.0f * (column)+15,18.0f * (lineCount)+15 });
                }
            }
            lineCount++;
        }
    }
    return coinpos;
}

void Map::generatecoin(sf::RenderWindow& window, std::vector<sf::Vector2f> Coin)
{
    for (int i = 0; i < Coin.size(); i++)
    {
        coin.setPosition(Coin[i].x, Coin[i].y);
        window.draw(coin);
    }
}
