#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class GRA
{
public:
	GRA(float szer, float wys);

	sf::Sprite sprite, sprite2;
	sf::Texture texture, texture2;

	float v=6; // PREDKOSC GRACZA
	void draw(sf::RenderWindow &window);
	void ruch1(int i); //RUCH GRACZA 1
	void ruch2(int i); //RUCH GRACZA 2

private:
	sf::RectangleShape gracz1;
	sf::RectangleShape gracz2;

};

