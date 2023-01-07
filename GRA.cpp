//RYSOWANIE SAMOLOTU GRACZA, PRZECIWNIKOW, POCISKOW ITD

#include "GRA.h"

extern int wybranastrona; //   wyciagniecie zmiennej z Main.cpp
extern int wybranysamolot;

//================================================
//potrzebne do zatrzymania przeciwnikow i pociskow                          <---------------------------
//================================================

GRA::GRA(float wys, float szer) {
	
	gracz.setPosition(100, 100);
	gracz.setTextureRect(sf::IntRect(0, 0, 216, 205));

	textura_gracza[0].loadFromFile("rdy_szary_idle.png");
	textura_gracza[1].loadFromFile("ten nie pixel.png");
	textura_gracza[2].loadFromFile("paap.png");

	textura_bota.loadFromFile("test2.png");
	bot.setTexture(textura_bota);
	bot.setTextureRect(sf::IntRect(0, 0, 60, 90));
	bot.setPosition(1000, 500);

}


void GRA::draw(sf::RenderWindow& window) {
	window.draw(gracz);
}

void GRA::draw_bot(sf::RenderWindow& window) {
	window.draw(bot);
}

void GRA::wybierzsamolot(int wybranysamolot) {
	switch (wybranysamolot)
	{
	case 0:
		gracz.setTexture(textura_gracza[wybranysamolot]);
		break;
	case 1:
		gracz.setTexture(textura_gracza[wybranysamolot]);
		break;
	case 2:
		gracz.setTexture(textura_gracza[wybranysamolot]);
		break;
	}
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
	pozycjabota = bot.getPosition();

	if (lewo==1) {
		bot.move(-3, 0);
		pozycjabota = bot.getPosition();
		if (pozycjabota.x < 500) {
			lewo = 0;
		}
	}

	if (lewo==0) {
		bot.move(3, 0);
		pozycjabota = bot.getPosition();
		if (pozycjabota.x > 1500) {
			lewo = 1;
		}
	}

}