#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TRUDNOSC.h"


class MENU
{
public:
	MENU();
	int petlaglowna(sf::RenderWindow& window);

private:
	void draw(sf::RenderWindow& window);
	void wGore();
	void wDol();

	int menuNacisniete() {
		return menuWybrane;
	}

	int menuWybrane;
	sf::Font czcionka;
	sf::Text pozycjeMenu[3];
	sf::Text obecny_rekord;
	sf::Sprite pomoc_menu;
	sf::Texture textura_pomoc_menu;
};