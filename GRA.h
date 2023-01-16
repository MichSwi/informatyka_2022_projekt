#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TRUDNOSC.h"

#define ilosc_pociskow_gracza 20
#define ilosc_wrogow 6
#define ilosc_szybkich_pociskow 85
#define ilosc_rakiet 5
#define ilosc_sojuszniczych_pociskow 10


class GRA
{
public:
	GRA(bool czy_sojusznik, int ktory_samolot);

	sf::Sprite gracz,
		bot,
		wrog[ilosc_wrogow],//   0-czerw    1,2-heli   3-bomber   4-zielony   5-niebieski
		pocisk[ilosc_pociskow_gracza],
		sojuszniczy_pocisk[ilosc_sojuszniczych_pociskow],
		wrogi_szybki_pocisk[ilosc_szybkich_pociskow],
		rakieta[ilosc_rakiet],
		pomoc;

	sf::Texture textura_gracza[3],
		textura_wroga[ilosc_wrogow],
		textura_bota,
		textura_pocisku,
		textura_szybkiego_pocisku,
		textura_pocisku_w_gore,
		textura_rakiety;

	float v; // PREDKOSC gracza
	void draw(sf::RenderWindow& window);

	int petlaglowna(sf::RenderWindow& window);
	bool sojusznik;
	int wybranysamolot;
	float deltatime = 0.0f;
	sf::Clock zegar;
	int rekord, nowe_punkty;

	int sprawdz_kolizje();
	void ruchgracza(int i); //RUCH GRACZA
	void ruchbota(); //RUCH BOTA
	void ruchpociskow(float deltatime);
	void strzal();
	void respawn();
	bool lewo[ilosc_wrogow] = { 0,1,0,1,0,1 }; //zmienna odpowidadjaca za zmiane predkosci po odbiciu od sciany
	bool lewo_bota = 0;
	void zaladujustawienia(int wybranysamolot);
	int licznik_pociskow_gracza = 0;
	int licznik_rakiet = 0;
	int punkty = 0;
	float calyczas[ilosc_wrogow] = { 0,0,0,0,0,0 };
	float calyczas_sojusznika = 0.0f;
	float przeladowanie_sojusznika = 0.5f;
	int licznik_pociskow = 0;
	int licznik_sojuszniczych = 0;
	int hp_gracza = -10;//NIE ZALADOWANO HP Z WYBORU SAMOLOTU
	int dmg_gracza;

	//   0-czerw    1,2-heli   3-bomber   4-zielony   5-niebieski

	const int max_hp_wroga[ilosc_wrogow] = { 4,2,2,12,7,7 };
	int hp_wroga[ilosc_wrogow] = { 4,2,2,12,7,7 };
	float v_wroga[ilosc_wrogow] = { 3.5,5,5,2.2,4,4 };
	float przeladowanie[ilosc_wrogow] = { 2,0.8,0.8,2.5,2,2 }; // w sekundach
	void aktualizajca_punktow();
	void draw_pomoc(sf::RenderWindow &window);
	void petla_glowna(float deltatime);
	bool help;
private:
	sf::Vector2f pozycjabota;
	sf::Vector2f pozycjagracza;
	sf::Vector2f pozycjawroga[ilosc_pociskow_gracza];
	sf::Font czcionka;
	sf::Text punktacja;
	sf::Text gameover_text;
	std::string punkty_string;

	sf::Texture textura_pomocy;
};