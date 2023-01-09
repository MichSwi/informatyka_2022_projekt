#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ANIMACJA
{
public:

	ANIMACJA(sf::Texture *teksturaanimacji, sf::Vector2u licznikobrazu, float czaszmiany);

	sf::IntRect poleobrazu;

	void update(int row, float deltatime);

private:
	sf::Vector2u licznikobrazu; //ktory wycinek obrazu
	sf::Vector2u wybranyobraz;

	float calyczas;
	float czaszmiany;
};

