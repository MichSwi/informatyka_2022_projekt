//RYSOWANIE SAMOLOTU GRACZA, PRZECIWNIKOW, POCISKOW ITD

#include "GRA.h"

extern int wybranysamolot;

//================================================
//potrzebne do zatrzymania przeciwnikow i pociskow                          <---------------------------
//================================================

GRA::GRA(float wys, float szer) {
	textura_pocisku.loadFromFile("pociskk.png");
	for (int i = 0; i < ilosc_pociskow; i++) {
		pocisk[i].setTextureRect(sf::IntRect(0, 0, 9, 15));
		pocisk[i].setTexture(textura_pocisku);
		pocisk[i].setPosition((i + 1) * 20,800);
	}
	
	gracz.setPosition(100, 900);
	gracz.setTextureRect(sf::IntRect(0, 0, 216, 205));

	textura_gracza[0].loadFromFile("rdy_szary_idle.png");
	textura_gracza[1].loadFromFile("ten nie pixel.png");
	textura_gracza[2].loadFromFile("paap.png");

	textura_bota.loadFromFile("test2.png");
	bot.setTexture(textura_bota);
	bot.setTextureRect(sf::IntRect(0, 0, 60, 90));
	bot.setPosition(1000, 500);

	textura_wroga.loadFromFile("sss.png");
	wrog[0].setTexture(textura_wroga);
	wrog[0].setTextureRect(sf::IntRect(0, 0, 144, 65));
	wrog[0].rotate(180);
	wrog[0].setPosition(1045, 200);

}


void GRA::draw(sf::RenderWindow& window) {
	window.draw(gracz);
	for (int i = 0; i < ilosc_pociskow; i++)
		window.draw(pocisk[i]);
	window.draw(wrog[0]);
}

void GRA::draw_bot(sf::RenderWindow& window) {
	window.draw(bot);
}

void GRA::ruchpociskow() {
	if (test == 2 || test == 0) {
		for (int i = 0; i < ilosc_pociskow; i++) {
			pocisk[i].move(0, -7);
		}
	}
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

int GRA::sprawdz_kolizje() {
	for (int i = 0; i < ilosc_pociskow; i++) {
		sf::IntRect bullet(pocisk[i].getPosition().x, pocisk[i].getPosition().y+pocisk[i].getTextureRect().height, pocisk[i].getTextureRect().width, pocisk[i].getTextureRect().height);
		for (int j = 0; j < ilosc_wrogow; j++) {
	//	sf::IntRect enemy(wrog[j].getPosition().x - wrog[j].getTextureRect().width, wrog[j].getPosition().y-wrog[j].getTextureRect().height, wrog[j].getTextureRect().width, wrog[j].getTextureRect().width);
			sf::IntRect enemy(wrog[j].getPosition().x-wrog[j].getTextureRect().width, wrog[j].getPosition().y-wrog[j].getTextureRect().height, 120, 81);
			
			if (bullet.intersects(enemy)) {
				std::cout << "KOLIZJA, wrog:" << j << " pocisk" << i << std::endl;
				return 1;
			}
			
		}
	}
	return 0;
}

void GRA::ruchbota() {
	pozycjabota = bot.getPosition();

	for (int i = 0; i < ilosc_wrogow ; i++) {
		pozycjawroga[i] = wrog[i].getPosition();


		if (lewo[i] == 1) {
			wrog[i].move(0, 0);
			pozycjawroga[i] = wrog[i].getPosition();
			if (pozycjawroga[i].x < 500) {
				lewo[i] = 0;
			}
		}

		if (lewo[i] == 0) {
			wrog[i].move(0, 0);
			pozycjawroga[i] = wrog[i].getPosition();
			if (pozycjawroga[i].x > 1500) {
				lewo[i] = 1;
			}
		}
	}


	if (lewo_bota == 1) {
		bot.move(-3, 0);
		pozycjabota = bot.getPosition();
		if (pozycjabota.x < 500) {
			lewo_bota = 0;
		}
	}

	if (lewo_bota == 0) {
		bot.move(3, 0);
		pozycjabota = bot.getPosition();
		if (pozycjabota.x > 1500) {
			lewo_bota = 1;
		}
	}
}

void GRA::strzal() {
		if (n == ilosc_pociskow)
			n = 0;
		pocisk[n].setPosition(gracz.getPosition());
		pocisk[n].move(49, 0);
		n++;
}