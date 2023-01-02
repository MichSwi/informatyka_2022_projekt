#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class GRA
{
public:
	GRA(float szer, float wys);

	sf::Sprite sprite, sprite2;
	sf::Texture texture, texture2;

	float v=6;
	void draw(sf::RenderWindow &window);
	void ruch1(int i);
	void ruch2(int i);

private:
	sf::RectangleShape gracz1;
	sf::RectangleShape gracz2;

};

