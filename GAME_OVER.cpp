#include "GAME_OVER.h"


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

extern int nowe_punkty;
extern int rekord;


GAME_OVER::GAME_OVER(float szer, float wys, int wprowadz_nowe_punkty, int wprowadz_rekord) {
	rekord = wprowadz_rekord;
	nowe_punkty = wprowadz_nowe_punkty;
	czcionka.loadFromFile("czcionka.ttf");
	napis.setFont(czcionka);
	napis.setPosition(400, 400);
	napis.setFillColor(sf::Color::Black);
	napis.setCharacterSize(80);


}

void GAME_OVER::update() {

	punkty_string = std::to_string(nowe_punkty);



	napis.setString("Twoj samolot zostal zestrzelony.\n     Twoj wynik: " + punkty_string + "\nNacisnij enter aby kontynuowac.");

}

void GAME_OVER::draw(sf::RenderWindow& window) {
	window.draw(napis);
}

void GAME_OVER::petlaglowna(sf::RenderWindow& window) {
	while (window.isOpen()) {
		window.clear(sf::Color::White);
		update();
		if (rekord < nowe_punkty) {
			std::ofstream zapis;
			zapis.open("dane.txt");
			zapis << nowe_punkty;
			zapis.close();
		}
		draw(window);
		window.display();
		sf::Event evn;
		while (window.pollEvent(evn)) {
			switch (evn.type) {
			case sf::Event::KeyReleased:
				if (evn.key.code == sf::Keyboard::Return)
					window.close();
				//powrot do glownego menu
				break;
			case sf::Event::Closed:
				window.close();
			}
		}
	}
}