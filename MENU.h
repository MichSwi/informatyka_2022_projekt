#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TRUDNOSC.h"


class MENU
{
public:
	MENU();

	void draw(sf::RenderWindow& window);
	void wGore();
	void wDol();
	int petlaglowna(sf::RenderWindow& window);

	int menuNacisniete() {
		return menuWybrane;
	}

private:
	int menuWybrane;
	sf::Font czcionka;
	sf::Text pozycjeMenu[3];
	sf::Text obecny_rekord;
};