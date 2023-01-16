#pragma once

#include "GRA.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class GAME_OVER
{
public:
	GAME_OVER(float szer, float wys, int wprowadz_nowe_punkty, int wprowadz_rekord);
	void draw(sf::RenderWindow& window);
	void update();
	std::string punkty_string;

	int nowe_punkty,
		rekord;
	void petlaglowna(sf::RenderWindow& window);
private:
	sf::Text napis;
	sf::Font czcionka;

};
