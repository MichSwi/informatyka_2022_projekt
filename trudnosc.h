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
	int licznik = 0;//mowi w jakim wierszu aktualnie jestesmy
	int wybranygracz = 1;// 0 -niezdefiniowane  1-1gracz   2-2graczy
	int wybranysamolot = 1;
	int pow = 0;// 0-niezdefiniowane   1-powrot   2-zatwierdz

	int stan() {
		return pow;
	}

private:
	sf::Font czcionka;
	sf::Text text1;//"wybierz ilosc graczy"
	sf::Text text2;//"wybierz samolot"
	sf::Text gracz[2];//"1gracz  2graczy"
	sf::Text samolot[3];
	sf::Text zatw;
	sf::Text powr;
};

