#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#define ilosc_pociskow_gracza 20
#define ilosc_wrogow 6
#define ilosc_szybkich_pociskow 85
#define ilosc_wolnych_pociskow 10
#define ilosc_sojuszniczych_pociskow 10


class GRA
{
public:
	GRA(float wys, float szer);

	sf::Sprite gracz,
		bot,
		wrog[ilosc_wrogow],//   0-czerw    1,2-heli   3-bomber   4-zielony   5-niebieski
		pocisk[ilosc_pociskow_gracza],
		sojuszniczy_pocisk[ilosc_sojuszniczych_pociskow],
		wrogi_szybki_pocisk[85],
		wrogi_wolny_pocisk[5];

	sf::Texture textura_gracza[3],
		textura_wroga[ilosc_wrogow],
		textura_bota,
		textura_pocisku,
		textura_wolnego_pocisku,
		textura_szybkiego_pocisku;

	float v; // PREDKOSC gracza
	void draw(sf::RenderWindow &window);

	int sprawdz_kolizje();
	void ruchgracza(int i); //RUCH GRACZA
	void ruchbota(); //RUCH BOTA
	void ruchpociskow(float deltatime);
	void strzal();
	bool lewo[ilosc_wrogow] = { 0,1,0,1,0,1 }; //zmienna odpowidadjaca za zmiane predkosci po odbiciu od sciany
	bool lewo_bota = 0;
	void zaladujustawienia(int wybranysamolot);
	int n = 0;
	float calyczas[ilosc_wrogow] = {0,0,0,0,0,0};
	float przeladowanie_sojusznika = 0;
	int licznik_pociskow = 0;
	int licznik_sojuszniczych;
	int hp_gracza = -10;//NIE ZALADOWANO HP Z WYBORU SAMOLOTU
	int hp_wroga[ilosc_wrogow] = { 5,2,2,12,7,7 };
	float v_wroga[ilosc_wrogow] = { 5,4,4,1.6,5,5 };
	float przeladowanie[ilosc_wrogow] = { 2,2,2,2,2,2 }; // w sekundach
	int test;

private:
	sf::Vector2f pozycjabota;
	sf::Vector2f pozycjagracza;
	sf::Vector2f pozycjawroga[ilosc_pociskow_gracza];
};

