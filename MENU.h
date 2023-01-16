#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "TRUDNOSC.h"



class MENU
{
public:
	MENU();

	void draw();
	void wGore();
	void wDol();
	int petlaglowna(sf::RenderWindow& window);

	int menuNacisniete() {
		return menuWybrane;
	}
	~MENU();

private:
	int menuWybrane;
	sf::Font czcionka;
	sf::Text pozycjeMenu[4];

};