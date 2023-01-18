#pragma once

#include <SFML/Graphics.hpp>
#include "ANIMACJA.h"
#include <iostream>

class TRUDNOSC
{
public:

	TRUDNOSC();

	int petlaglowna(sf::RenderWindow& window);

	
	int wybranysamolot = 1;
	


	

	int stan() {
		return pow;
	}

private:
	int pow = 0;//   1-powrot   2-zatwierdz
	int rysuj_staty = -1;// -1 czyli ¿adne
	sf::Sprite sojusznik_sprite;
	sf::Text sojusznik_staty;
	sf::Texture samolot_textura[3];
	sf::Texture sojusznik_textura;
	sf::Sprite samolot_sprite[3];

	void Enter();
	void wPrawo();
	void wLewo();
	void draw(sf::RenderWindow& window);
	bool sojusznik;

	float deltatime = 0.0f;
	bool rysuj_sojusznika;

	int licznik = 0;//mowi w jakim wierszu aktualnie jestesmy

	sf::Clock zegar;

	sf::Font czcionka;
	sf::Text text1;//"czy potzrebujesz sojusznika?"
	sf::Text text2;//"wybierz samolot"
	sf::Text gracz[2];//"1gracz / gracz i bot"
	sf::Text samolot[3];
	sf::Text zatw;
	sf::Text powr;
	sf::Text statystyki[3];
};