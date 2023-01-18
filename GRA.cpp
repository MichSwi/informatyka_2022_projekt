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
	for (int i = 0; i < ilosc_szybkich_pociskow; i++) {
		wrogi_szybki_pocisk[i].setTexture(textura_szybkiego_pocisku);
		wrogi_szybki_pocisk[i].setTextureRect(sf::IntRect(0, 0, 9, 41));
		wrogi_szybki_pocisk[i].setPosition(400, 2200);
	}

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

	//WYBUCHY
	licznik_expl = -1;
	for (int i=0; i < ilosc_explozji; i++) {
		textura_expl[i].loadFromFile("expl.png");
		expl[i].setTexture(textura_expl[i]);
		expl[i].setPosition(-200, -200);
	}

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
	punktacja.setFillColor(sf::Color::White);
	punktacja.setString("0");
	punktacja.setPosition(1800, 10);

	textura_pomocy.loadFromFile("pomoc.png");
	pomoc.setTexture(textura_pomocy);
	pomoc.setPosition(480, 270);

	textura_chmury.loadFromFile("cloud.png");
	chmura1.setTexture(textura_chmury);
	chmura1.scale(3, 2);
	chmura1.setPosition(600, 50);
	chmura2.setTexture(textura_chmury);
	chmura2.setPosition(600, 200);
	chmura2.rotate(180);

	textura_sun.loadFromFile("sun.png");
	sun.setTexture(textura_sun);
	sun.setPosition(1080, 0);

	textura_pauzy.loadFromFile("pauza.png");
	pauza.setTexture(textura_pauzy);
	pauza.setPosition(660,371);

	text.setFont(czcionka);
	text.setFillColor(sf::Color::White);
	text.setPosition(1650,1010);
	text.setString("F1 - pomoc, Esc - pauza");
	text.setCharacterSize(45);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(2);

	zycie.setFont(czcionka);
	zycie.setCharacterSize(65);
	zycie.setOutlineColor(sf::Color::Black);
	zycie.setOutlineThickness(2);
	zycie.setPosition(40, 960);

	zaladujustawienia(wybranysamolot);
}

void GRA::draw(sf::RenderWindow& window) {
	window.draw(text);
	window.draw(gracz);
	window.draw(sun);
	window.draw(zycie);
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
	window.draw(chmura1);
	window.draw(chmura2);

	for (int i = 0; i < ilosc_explozji; i++) {
		window.draw(expl[i]);
	}
}

void GRA::aktualizajca_punktow() {
	punkty_string = std::to_string(punkty);
	punktacja.setString(punkty_string);
	zycie.setString("Twoja wytrzymalosc: "+std::to_string(hp_gracza));
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
		dmg_gracza = 2;
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

	if (i == 0 && gracz.getPosition().x>10) {
		gracz.move(-v, 0);
	}
	if (i == 1&&gracz.getPosition().x<1800) {
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


int GRA::sprawdz_kolizje() {//zwraca numer przeciwnika ktory zginal
	//KOLIZJE POCISKOW SOJUSZNIKA Z PRZECIWNIKAMI
	for (int i = 0; i < ilosc_sojuszniczych_pociskow; i++) {
		sf::IntRect bullet_sojusz(sojuszniczy_pocisk[i].getPosition().x, sojuszniczy_pocisk[i].getPosition().y, sojuszniczy_pocisk[i].getTextureRect().width, sojuszniczy_pocisk[i].getTextureRect().height);
		for (int j = 0; j < ilosc_wrogow; j++) {
			sf::IntRect enemy(wrog[j].getPosition().x, wrog[j].getPosition().y, wrog[j].getTextureRect().width, wrog[j].getTextureRect().height);
			if (bullet_sojusz.intersects(enemy)) {
				hp_wroga[j]--;
				if (hp_wroga[j] <= 0) {
					hp_wroga[j] = max_hp_wroga[j];
					return j;
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
					punkty++;
					return j;
				}
				pocisk[i].setPosition(-3000, -3000);
				std::cout << "\nKOLIZJA, wrog:" << j << " pocisk" << i << std::endl;
			}
		}
	}
	return -1;
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


int GRA::petlaglowna(sf::RenderWindow& window) {
	std::ifstream odczyt;
	odczyt.open("dane.txt");
	odczyt >> rekord;
	odczyt.close();
	ANIMACJA czerwony_wrog(&textura_wroga[0], sf::Vector2u(2, 1), 0.6f);
	ANIMACJA heli_wrog1(&textura_wroga[1], sf::Vector2u(2, 1), 0.3f);
	ANIMACJA heli_wrog2(&textura_wroga[2], sf::Vector2u(2, 1), 0.3f);
	ANIMACJA animacja(&textura_gracza[wybranysamolot], sf::Vector2u(2, 1), 0.3f);//animacja gracza
	ANIMACJA explozja0(&textura_expl[0], sf::Vector2u(6, 6), 0.1f);
	ANIMACJA explozja1(&textura_expl[1], sf::Vector2u(6, 6), 0.1f);
	ANIMACJA explozja2(&textura_expl[2], sf::Vector2u(6, 6), 0.1f);
	ANIMACJA explozja3(&textura_expl[3], sf::Vector2u(6, 6), 0.1f);

	while (window.isOpen()) {
		deltatime = zegar.restart().asSeconds();
		window.clear(sf::Color::Blue);

		if (hp_gracza == 0) {//PRZEGRANA
			hp_gracza = -10;
			window.clear(sf::Color::White);
			nowe_punkty = punkty;
			GAME_OVER game_over(nowe_punkty, rekord);
			if (game_over.petlaglowna(window))
				return 1;
		}

		animacja.update(0, deltatime,0);//.update -> zmiany pozycji textur spriteow
		czerwony_wrog.update(0, deltatime,0);
		heli_wrog1.update(0, deltatime,0);
		heli_wrog2.update(0, deltatime,0);

		///
		expl[0].setTextureRect(explozja0.poleobrazu);//przypisanie aktua;nej pozycji textury dla spritea
		expl[1].setTextureRect(explozja1.poleobrazu);
		expl[2].setTextureRect(explozja2.poleobrazu);
		expl[3].setTextureRect(explozja3.poleobrazu);

		gracz.setTextureRect(animacja.poleobrazu);
		wrog[1].setTextureRect(heli_wrog1.poleobrazu);
		wrog[2].setTextureRect(heli_wrog2.poleobrazu);
		wrog[0].setTextureRect(czerwony_wrog.poleobrazu);
		///

		respawn();
		ruchbota();
		ruchpociskow(deltatime);
		aktualizajca_punktow();
		ktory = sprawdz_kolizje();
		if (ktory != -1) {
			licznik_expl++;
			switch (licznik_expl) {
			case 0:
				expl[0].setPosition(wrog[ktory].getPosition());
				wrog[ktory].setPosition(-2500, wrog[ktory].getPosition().y);
				explozja0.reset();
				break;
			case 1: 
				expl[1].setPosition(wrog[ktory].getPosition());
				wrog[ktory].setPosition(2500, wrog[ktory].getPosition().y);
				explozja1.reset();
				break;
			case 2:
				expl[2].setPosition(wrog[ktory].getPosition());
				wrog[ktory].setPosition(-2500, wrog[ktory].getPosition().y);
				explozja2.reset();
				break;
			case 3:
				expl[3].setPosition(wrog[ktory].getPosition());
				wrog[ktory].setPosition(2500, wrog[ktory].getPosition().y);
				explozja3.reset();
				break;
			case ilosc_explozji:
				licznik_expl = -1;
				break;
			}
		}

		explozja0.update(0, deltatime, 1);
		explozja1.update(0, deltatime, 1);
		explozja2.update(0, deltatime, 1);
		explozja3.update(0, deltatime, 1);

		draw(window);
		window.display();
		sf::Event evn;

		while (window.pollEvent(evn)) {
			if (evn.type==sf::Event::KeyReleased && evn.key.code == sf::Keyboard::Escape) {
				window.draw(pauza);
				window.display();
				while (1) {
					if (evn.type == sf::Event::KeyPressed && evn.key.code == sf::Keyboard::Escape) {
						nowe_punkty = punkty;
						if (rekord < nowe_punkty) {
							std::ofstream zapis;
							zapis.open("dane.txt");
							zapis << nowe_punkty;
							zapis.close();
						}
						window.close();
						return 1;
					}
					if (window.waitEvent(evn) && evn.type == sf::Event::KeyReleased && evn.key.code==sf::Keyboard::Return) {
						break;
					}
				}
			}
			if (evn.type == sf::Event::KeyReleased && evn.key.code == sf::Keyboard::Space) {
				strzal();
			}
			if (evn.type == sf::Event::KeyReleased && evn.key.code == sf::Keyboard::F1) {				
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
		case sf::Event::KeyPressed:
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