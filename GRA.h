#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class GRA
{
public:
	GRA(float szer, float wys);

	sf::Sprite gracz, bot;
	sf::Texture textura_gracza, textura_bota;

	float v=0.1; // PREDKOSC 
	void draw(sf::RenderWindow &window);
	void ruchgracza(int i); //RUCH GRACZA
	void ruchbota(); //RUCH BOTA
	bool lewo = 0;


private:
	sf::Vector2f pozycjabota;
	sf::Vector2f pozycjagracza;

};

