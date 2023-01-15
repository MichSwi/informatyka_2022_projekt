#include "GAME_OVER.h"


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

extern int nowe_punkty;
extern int rekord;


GAME_OVER::GAME_OVER(float szer, float wys) {
	czcionka.loadFromFile("czcionka.ttf");
	napis.setFont(czcionka);
	napis.setPosition(400, 400);
	napis.setFillColor(sf::Color::Black);
	napis.setCharacterSize(80);
	

}

void GAME_OVER::update() {

	punkty_string = std::to_string(nowe_punkty);

	

	napis.setString( "Twoj samolot zostal zestrzelony.\n     Twoj wynik: " + punkty_string);

}

void GAME_OVER::draw(sf::RenderWindow& window) {
	window.draw(napis);
}