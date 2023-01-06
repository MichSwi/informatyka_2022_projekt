//RYSOWANIE SAMOLOTU GRACZA, PRZECIWNIKOW, POCISKOW ITD

#include "GRA.h"

extern int wybranastrona; //   wyciagniecie zmiennej z Main.cpp


//================================================
//potrzebne do zatrzymania przeciwnikow i pociskow                          <---------------------------
//================================================

GRA::GRA(float szer,float wys) {

	textura_gracza.loadFromFile("test1.png");

	gracz.setTexture(textura_gracza);
	gracz.setTextureRect(sf::IntRect(0, 0, 60, 90));
	gracz.setPosition(100, 100);

	textura_bota.loadFromFile("test2.png");

	bot.setTexture(textura_bota);
	bot.setTextureRect(sf::IntRect(0, 0, 60, 90));
	bot.setPosition(1000, 500);

}

void GRA::draw(sf::RenderWindow& window) {
	window.draw(gracz);
	window.draw(bot);
}
void GRA::ruchgracza(int i) {
		if (i == 0) {
			gracz.move(-v, 0);
		}
		if (i == 1) {
			gracz.move(v, 0);
		}
 }

void GRA::ruchbota() {

	int lewa_krawedz = 1200.0;
	int prawa_krawedz = 800.0;

	pozycjabota = bot.getPosition();

	if (lewo==1) {
		std::cout << "\nruszam sie w lewo";
		bot.move(-3, 0);
		pozycjabota = bot.getPosition();
		if (pozycjabota.x < 500) {
			std::cout << "przekroczono";
			lewo = 0;
		}
	}

	if (lewo==0) {
		std::cout << "\nruszam sie w prawo";
		bot.move(3, 0);
		pozycjabota = bot.getPosition();
		if (pozycjabota.x > 1500) {
			std::cout << "przekroczono";
			lewo = 1;
		}
	}

	std::cout << "\nlewo="<< lewo << "\n" << pozycjabota.x;

}