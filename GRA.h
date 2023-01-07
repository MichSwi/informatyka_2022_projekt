#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class GRA
{
public:
	GRA(float wys, float szer);

	sf::Sprite gracz, bot;
	sf::Texture textura_gracza[3], textura_bota;

	float v=5.0f; // PREDKOSC 
	void draw(sf::RenderWindow &window);
	void draw_bot(sf::RenderWindow& window);

	void ruchgracza(int i); //RUCH GRACZA
	void ruchbota(); //RUCH BOTA
	bool lewo = 0;
	void wybierzsamolot(int wybranysamolot);

private:
	sf::Vector2f pozycjabota;
	sf::Vector2f pozycjagracza;

};

