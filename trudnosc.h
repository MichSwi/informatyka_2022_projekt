#pragma once

#include <SFML/Graphics.hpp>
#include "ANIMACJA.h"
#include <iostream>

class TRUDNOSC
{
public:

	TRUDNOSC(float szer, float wys);

	int petlaglowna(sf::RenderWindow& window);

	void Enter();
	void wPrawo();
	void wLewo();
	void draw(sf::RenderWindow& window);
	int licznik = 0;//mowi w jakim wierszu aktualnie jestesmy
	int sojusznik = 0;
	int wybranysamolot = 1;
	int pow = 0;//   1-powrot   2-zatwierdz
	int daj_wybranysamolot() {
		return wybranysamolot;
	}

	sf::Texture samolot_textura[3];
	sf::Sprite samolot_sprite[3];

	int rysuj_staty = -1;// -1 czyli ¿adne

	int stan() {
		return pow;
	}


	float deltatime = 0.0f;
	sf::Clock zegar;


private:
	sf::Font czcionka;
	sf::Text text1;//"czy potzrebujesz sojusznika?"
	sf::Text text2;//"wybierz samolot"
	sf::Text gracz[2];//"1gracz / gracz i bot"
	sf::Text samolot[3];
	sf::Text zatw;
	sf::Text powr;
	sf::Text statystyki[3];

};