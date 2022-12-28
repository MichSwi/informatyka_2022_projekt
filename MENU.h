#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


class MENU
{
public:
	MENU(float szerokosc, float wysokosc);

	void draw(sf::RenderWindow& window);
	void wGore();
	void wDol();

	int menuNacisniete() {
		return menuWybrane;
	}
	~MENU();

private:
	int menuWybrane;
	sf::Font czcionka;
	sf::Text pozycjeMenu[4];

};

