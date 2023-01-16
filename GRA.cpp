#include <iostream>
#include <string>
#include <fstream>
#include "GRA.h"
#include "TRUDNOSC.h"
#include "GAME_OVER.h"


GRA::GRA(bool czy_sojusznik, int ktory_samolot) {
	//przeniesienie poziomu trudnosci do gry
	wybranysamolot = ktory_samolot;
	sojusznik = czy_sojusznik;
	std::cout << "|w konstruktorze gra: " << wybranysamolot;


	help = 0;
	//POCISKI GRACZA i sojusznika
	textura_pocisku.loadFromFile("bullet.png");
	for (int i = 0; i < ilosc_pociskow_gracza; i++) {
		pocisk[i].setTextureRect(sf::IntRect(0, 0, 9, 41));
		pocisk[i].setTexture(textura_pocisku);
		pocisk[i].setPosition(-200, -200);
	}
	for (int i = 0; i < ilosc_sojuszniczych_pociskow; i++) {
		sojuszniczy_pocisk[i].setTexture(textura_pocisku);
		sojuszniczy_pocisk[i].setPosition(-100, -100);
	}

	textura_szybkiego_pocisku.loadFromFile("bullet-wdol.png");

	gracz.setPosition(980, 900);

	textura_gracza[0].loadFromFile("gracz_szary_idle.png");
	textura_gracza[1].loadFromFile("gracz_nie_pixel.png");
	textura_gracza[2].loadFromFile("gracz_paap.png");

	textura_bota.loadFromFile("bot.png");
	bot.setTexture(textura_bota);
	bot.setPosition(1000, 800);

	textura_wroga[0].loadFromFile("czerwony.png");
	wrog[0].setTexture(textura_wroga[0]);
	wrog[0].setPosition(1045-1000, 300);

	textura_wroga[1].loadFromFile("heli.png");
	wrog[1].setTexture(textura_wroga[1]);
	wrog[1].setPosition(700+2000, 500);

	textura_wroga[2].loadFromFile("heli.png");
	wrog[2].setTexture(textura_wroga[2]);
	wrog[2].setPosition(500+3000, 500);

	textura_wroga[3].loadFromFile("bomber.png");
	wrog[3].setTexture(textura_wroga[3]);
	wrog[3].setPosition(10-400, 20);

	textura_wroga[4].loadFromFile("ziel.png");
	wrog[4].setTexture(textura_wroga[4]);
	wrog[4].setPosition(40-2500, 150);

	textura_wroga[5].loadFromFile("nieb.png");
	wrog[5].setTexture(textura_wroga[5]);
	wrog[5].setPosition(300-3000, 150);


	//RAKIETY
	textura_rakiety.loadFromFile("missle.png");
	for (int i = 0; i < ilosc_rakiet; i++) {
		rakieta[i].setTexture(textura_rakiety);
		rakieta[i].setPosition(4000, -200);
	}

	czcionka.loadFromFile("czcionka.ttf");
	punktacja.setFont(czcionka);
	punktacja.setCharacterSize(60);
	punktacja.setOutlineColor(sf::Color::Black);
	punktacja.setOutlineThickness(5);
	punktacja.setFillColor(sf::Color::Red);
	punktacja.setString("0");
	punktacja.setPosition(1800, 10);


	for (int i = 0; i < ilosc_szybkich_pociskow; i++) {
		wrogi_szybki_pocisk[i].setTexture(textura_szybkiego_pocisku);
		wrogi_szybki_pocisk[i].setTextureRect(sf::IntRect(0, 0, 9, 41));
		wrogi_szybki_pocisk[i].setPosition(400, 2200);
	}

	for (int i = 0; i < 5; i++) {
		rakieta[i].setTexture(textura_rakiety);
	}

	textura_pomocy.loadFromFile("pomoc.png");
	pomoc.setTexture(textura_pomocy);
	pomoc.setPosition(400, 200);



	zaladujustawienia(wybranysamolot);
}

void GRA::draw(sf::RenderWindow& window) {
	window.draw(gracz);
	window.draw(punktacja);
	for (int i = 0; i < ilosc_pociskow_gracza; i++)
		window.draw(pocisk[i]);

	for (int i = 0; i < ilosc_wrogow; i++)
		window.draw(wrog[i]);

	for (int i = 0; i < ilosc_szybkich_pociskow; i++) {
		window.draw(wrogi_szybki_pocisk[i]);
	}
	if (sojusznik == 1) {
		window.draw(bot);
		for (int i = 0; i < ilosc_sojuszniczych_pociskow; i++) {
			window.draw(sojuszniczy_pocisk[i]);
		}
	}
	for (int i = 0; i < ilosc_rakiet; i++) {
		window.draw(rakieta[i]);
	}
}

void GRA::aktualizajca_punktow() {
	punkty_string = std::to_string(punkty);
	punktacja.setString(punkty_string);
}

void GRA::ruchpociskow(float deltatime) {

	//strzelanie wrogich szybkich pociskow
	for (int t = 0; t < ilosc_wrogow; t++) {
		if (t == 3) {
			continue;
		}
		calyczas[t] = calyczas[t] + deltatime;
	}

	//STRZALY PRZECIWNIKOW
	for (int i = 0; i < ilosc_wrogow; i++) {
		if (i == 3)
			continue;//ominiecie bombera
		if (calyczas[i] > przeladowanie[i]) {
			wrogi_szybki_pocisk[licznik_pociskow].setPosition(wrog[i].getPosition().x + wrog[i].getTextureRect().width / 2 - 4, wrog[i].getPosition().y + wrog[i].getTextureRect().height - 41);
			calyczas[i] = 0;
			licznik_pociskow++;
			if (licznik_pociskow == 84) {
				licznik_pociskow = 0;
			}
		}
	}

	//aktualizacja czasu
	for (int t = 0; t < ilosc_wrogow; t++) {
		calyczas[t] = calyczas[t] + deltatime;
	}
	//ruch pociskow gracza
	for (int i = 0; i < ilosc_pociskow_gracza; i++) {
		pocisk[i].move(0, -7);
	}

	//RUCH WROGICH SZYBKICH POCISKOW
	for (int i = 0; i < ilosc_szybkich_pociskow; i++) {
		wrogi_szybki_pocisk[i].move(0, 5);
	}

	//RUCH SOJUSZNICZYCH POCISKOW
	if (sojusznik == 1) {
		for (int i = 0; i < ilosc_sojuszniczych_pociskow; i++) {
			sojuszniczy_pocisk[i].move(0, -5);
		}
	}

	//RUCH RAKIET
	for (int i = 0; i < ilosc_rakiet; i++) {
		rakieta[i].move(0, 2.6f);
	}

	//przeladowanie sojusznika
	calyczas_sojusznika = calyczas_sojusznika + deltatime;
	if (calyczas_sojusznika > przeladowanie_sojusznika) {
		sojuszniczy_pocisk[licznik_sojuszniczych].setPosition(bot.getPosition().x + bot.getTextureRect().width / 2 - 4, bot.getPosition().y - 45);
		calyczas_sojusznika = 0;
		licznik_sojuszniczych++;
		if (licznik_sojuszniczych == ilosc_sojuszniczych_pociskow)
			licznik_sojuszniczych = 0;
	}

	//przeladownie bombera
	if (calyczas[3] > przeladowanie[3]) {
		rakieta[licznik_rakiet].setPosition(wrog[3].getPosition().x + wrog[3].getTextureRect().width / 2 - 10, wrog[3].getPosition().y + wrog[3].getTextureRect().width - 60);
		licznik_rakiet++;
		calyczas[3] = 0;
		if (licznik_rakiet == ilosc_rakiet) {
			licznik_rakiet = 0;
		}
	}
}

void GRA::zaladujustawienia(int wybranysamolot) {

	switch (wybranysamolot)
	{
	case 0:
		v = 15.0f;
		hp_gracza = 20;
		dmg_gracza = 3;
		gracz.setTexture(textura_gracza[wybranysamolot]);
		break;
	case 1:
		v = 7.0f;
		hp_gracza = 8;
		dmg_gracza - 2;
		gracz.setTexture(textura_gracza[wybranysamolot]);
		break;
	case 2:
		v = 3.5f;
		hp_gracza = 1;
		dmg_gracza = 1;
		gracz.setTexture(textura_gracza[2]);
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

void GRA::respawn() {
	for (int i = 0; i < ilosc_wrogow; i++) {
		if (wrog[i].getPosition().x < 0) {
			wrog[i].move(abs(v_wroga[i]), 0);
		}
		if (wrog[i].getPosition().y > 1080 + 50) {
			wrog[i].move(-abs(v_wroga[i]),0);
		}
	}
}


int GRA::sprawdz_kolizje() {
	//KOLIZJE POCISKOW SOJUSZNIKA Z PRZECIWNIKAMI
	for (int i = 0; i < ilosc_sojuszniczych_pociskow; i++) {
		sf::IntRect bullet_sojusz(sojuszniczy_pocisk[i].getPosition().x, sojuszniczy_pocisk[i].getPosition().y, sojuszniczy_pocisk[i].getTextureRect().width, sojuszniczy_pocisk[i].getTextureRect().height);
		for (int j = 0; j < ilosc_wrogow; j++) {
			sf::IntRect enemy(wrog[j].getPosition().x, wrog[j].getPosition().y, wrog[j].getTextureRect().width, wrog[j].getTextureRect().height);
			if (bullet_sojusz.intersects(enemy)) {
				hp_wroga[j]--;
				if (hp_wroga[j] <= 0) {
					hp_wroga[j] = max_hp_wroga[j];
					wrog[j].setPosition(-3000, wrog[j].getPosition().y);
				}
				sojuszniczy_pocisk[i].setPosition(-3000, -3000);
				std::cout << "\nsojusznik trafil wroga " << j << ",zostalo mu hp:" << hp_wroga[j];
			}
		}
	}

	//KOLIZJE SZYBKICH POCISKOW PRZECIWNIKOW Z GRACZEM
	sf::IntRect player(gracz.getPosition().x, gracz.getPosition().y, gracz.getTextureRect().width, gracz.getTextureRect().height);
	for (int i = 0; i < ilosc_szybkich_pociskow; i++) {
		sf::IntRect bullet_wroga(wrogi_szybki_pocisk[i].getPosition().x, wrogi_szybki_pocisk[i].getPosition().y, wrogi_szybki_pocisk[i].getTextureRect().width, wrogi_szybki_pocisk[i].getTextureRect().height);
		if (player.intersects(bullet_wroga)) {
			hp_gracza--;
			std::cout << "\nzostalo ci hp:" << hp_gracza;
			if (hp_gracza <= 0) {
				std::cout << "\nPRZEGRANA";
			}
			wrogi_szybki_pocisk[i].setPosition(-3000, 3000);
		}
	}
	//KOLIZJE RAKIET Z GRACZEM
	for (int i = 0; i < ilosc_rakiet; i++) {
		sf::IntRect missle(rakieta[i].getPosition().x, rakieta[i].getPosition().y, rakieta[i].getTextureRect().width, rakieta[i].getTextureRect().height);
		if (player.intersects(missle)) {
			hp_gracza = 0;
			std::cout << "\n\n--RAKIETA CIE TRAFILA--\n\n";
			rakieta[i].setPosition(-300, 4000);
		}
	}

	//KOLIZJE POCISKOW GRACZA Z PRZECIWNIKAMI
	for (int i = 0; i < ilosc_pociskow_gracza; i++) {
		sf::IntRect bullet_gracza(pocisk[i].getPosition().x, pocisk[i].getPosition().y, pocisk[i].getTextureRect().width, pocisk[i].getTextureRect().height);
		for (int j = 0; j < ilosc_wrogow; j++) {
			sf::IntRect enemy(wrog[j].getPosition().x, wrog[j].getPosition().y, wrog[j].getTextureRect().width, wrog[j].getTextureRect().height);
			if (bullet_gracza.intersects(enemy)) {
				hp_wroga[j]--;
				std::cout << "\nwrogowi" << j << " zostalo: " << hp_wroga[j];
				if (hp_wroga[j] <= 0) {
					hp_wroga[j] = max_hp_wroga[j];
					wrog[j].setPosition(-2500, wrog[j].getPosition().y);
					punkty++;
				}
				pocisk[i].setPosition(-3000, -3000);
				std::cout << "\nKOLIZJA, wrog:" << j << " pocisk" << i << std::endl;
				return 1;
			}
		}
	}
	return 0;
}

void GRA::ruchbota() {
	pozycjabota = bot.getPosition();
	for (int i = 0; i < ilosc_wrogow; i++) {
		pozycjawroga[i] = wrog[i].getPosition();

		if (lewo[i] == 1) {
			wrog[i].move(-v_wroga[i], 0);
			pozycjawroga[i] = wrog[i].getPosition();
			if (pozycjawroga[i].x < 50) {
				lewo[i] = 0;
			}
		}

		if (lewo[i] == 0) {
			wrog[i].move(v_wroga[i], 0);
			pozycjawroga[i] = wrog[i].getPosition();
			if (pozycjawroga[i].x > 1920 - wrog[i].getTextureRect().width - 50) {
				lewo[i] = 1;
			}
		}
	}

	if (lewo_bota == 1) {
		bot.move(-3, 0);
		pozycjabota = bot.getPosition();
		if (pozycjabota.x < 50) {
			lewo_bota = 0;
		}
	}

	if (lewo_bota == 0) {
		bot.move(3, 0);
		pozycjabota = bot.getPosition();
		if (pozycjabota.x > 1920 - bot.getTextureRect().width - 50) {
			lewo_bota = 1;
		}
	}
}

void GRA::strzal() {
	if (licznik_pociskow_gracza == ilosc_pociskow_gracza)
		licznik_pociskow_gracza = 0;
	pocisk[licznik_pociskow_gracza].setPosition(gracz.getPosition());
	pocisk[licznik_pociskow_gracza].move(49, 0);
	licznik_pociskow_gracza++;
}

void GRA::petla_glowna(float deltatime) {
	respawn();
	ruchbota();
	sprawdz_kolizje();
	ruchpociskow(deltatime);
	aktualizajca_punktow();
}

int GRA::petlaglowna(sf::RenderWindow& window) {
	std::ifstream odczyt;
	odczyt.open("dane.txt");
	odczyt >> rekord;
	odczyt.close();
	ANIMACJA czerwony_wrog(&textura_wroga[0], sf::Vector2u(2, 1), 0.6f);
	ANIMACJA heli_wrog1(&textura_wroga[1], sf::Vector2u(2, 1), 0.3f);
	ANIMACJA heli_wrog2(&textura_wroga[2], sf::Vector2u(2, 1), 0.3f);
	ANIMACJA animacja(&textura_gracza[wybranysamolot], sf::Vector2u(2, 1), 0.3f);//animacja gracza



	while (window.isOpen()) {

		deltatime = zegar.restart().asSeconds();

		window.clear(sf::Color::Blue);

		if (hp_gracza == 0) {//PRZEGRANA
			hp_gracza = -10;
			window.clear(sf::Color::White);
			nowe_punkty = punkty;
			std::cout << "nowe punkty to:" << nowe_punkty;
			GAME_OVER game_over(nowe_punkty, rekord);
			if (game_over.petlaglowna(window))
				return 1;
		}
		animacja.update(0, deltatime);

		wrog[0].setTextureRect(czerwony_wrog.poleobrazu);
		czerwony_wrog.update(0, deltatime);
		heli_wrog1.update(0, deltatime);
		heli_wrog2.update(0, deltatime);

		gracz.setTextureRect(animacja.poleobrazu);
		wrog[1].setTextureRect(heli_wrog1.poleobrazu);
		wrog[2].setTextureRect(heli_wrog2.poleobrazu);

		petla_glowna(deltatime);
		draw(window);

		window.display();

		sf::Event evn;

		while (window.pollEvent(evn)) {
			if (evn.type == sf::Event::Closed || evn.key.code == sf::Keyboard::Escape) {
				window.close();
				nowe_punkty = punkty;
				if (rekord < nowe_punkty) {
					std::ofstream zapis;
					zapis.open("dane.txt");
					zapis << nowe_punkty;
					zapis.close();
				}
			}
			if (evn.type == sf::Event::KeyReleased && evn.key.code == sf::Keyboard::Space) {
				strzal();
			}
			if (evn.type == sf::Event::KeyReleased && evn.key.code == sf::Keyboard::Q) {				
				window.draw(pomoc);
				window.display();
				while (1) {
					if (window.waitEvent(evn)&&evn.type==sf::Event::KeyReleased) {
						break;
					}
				}
			}
		}

		switch (evn.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (evn.key.code == sf::Keyboard::Escape)
				window.close();
			if (evn.key.code == sf::Keyboard::Left) {
				ruchgracza(0);
			}
			if (evn.key.code == sf::Keyboard::Right) {
				ruchgracza(1);
			}
			break;
		}

	}
}