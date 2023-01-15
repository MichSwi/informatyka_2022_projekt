#pragma once

#include "GRA.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class GAME_OVER
{
public:
	GAME_OVER(float szer, float wys);
	void draw(sf::RenderWindow& window);
	void update();
	std::string punkty_string;

private:
	sf::Text napis;
	sf::Font czcionka;

};

