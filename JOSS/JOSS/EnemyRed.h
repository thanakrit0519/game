#pragma once
#include <SFML/Graphics.hpp>

class EnemyRed
{
public:
	EnemyRed(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~EnemyRed();

	void Update(int row, float deltaTime);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

