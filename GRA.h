#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#define ilosc_pociskow 20
#define ilosc_wrogow 1

class GRA
{
public:
	GRA(float wys, float szer);

	sf::Sprite gracz, bot, pocisk[ilosc_pociskow];
	sf::Texture textura_gracza[3], textura_bota, textura_pocisku;

	sf::Sprite wrog[ilosc_wrogow];
	sf::Texture textura_wroga;

	float v=5.0f; // PREDKOSC 
	void draw(sf::RenderWindow &window);
	void draw_bot(sf::RenderWindow& window);

	int sprawdz_kolizje();
	void ruchgracza(int i); //RUCH GRACZA
	void ruchbota(); //RUCH BOTA
	void ruchpociskow();
	void strzal();
	bool lewo[ilosc_wrogow] = { 0 };//zmienna odpowidadjaca za zmiane predkosci po odbiciu od sciany
	bool lewo_bota = 0;
	void wybierzsamolot(int wybranysamolot);
	int n = 0;
	int test = 2;

private:
	sf::Vector2f pozycjabota;
	sf::Vector2f pozycjagracza;
	sf::Vector2f pozycjawroga[ilosc_pociskow];
};

