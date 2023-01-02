#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class trudnosc
{
public:

	trudnosc(float szer, float wys);

	void Enter();
	void wPrawo();
	void wLewo();
	void draw(sf::RenderWindow& window);
	int licznik = 0;
	int wybranygracz = 1;
	int wybranysamolot = 1;
	int pow = 0;

	int stan() {
		return pow;
	}

private:
	sf::Font czcionka;
	sf::Text text1;
	sf::Text text2;
	sf::Text gracz[2];
	sf::Text samolot[3];
	sf::Text zatw;
	sf::Text powr;
};

