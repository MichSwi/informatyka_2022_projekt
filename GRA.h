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
#define ilosc_explozji 4


class GRA
{
public:
	GRA(bool czy_sojusznik, int ktory_samolot);
	int petlaglowna(sf::RenderWindow& window);

private:
	//gracz
	sf::Sprite gracz;
	sf::Texture textura_gracza[3];
	float v; // PREDKOSC gracza
	void ruchgracza(int i); //RUCH GRACZA
	void strzal();
	int wybranysamolot,
		dmg_gracza,
		hp_gracza = -10;//NIE ZALADOWANO HP Z WYBORU SAMOLOTU

	//sojusznik
	sf::Sprite bot;
	sf::Texture textura_bota;
	bool sojusznik,
		 lewo_bota = 0;
	float calyczas_sojusznika = 0.0f,
		  przeladowanie_sojusznika = 0.5f;
	void ruchbota(); //RUCH BOTA


	//pociski
	sf::Sprite  
		pocisk[ilosc_pociskow_gracza],
		sojuszniczy_pocisk[ilosc_sojuszniczych_pociskow],
		wrogi_szybki_pocisk[ilosc_szybkich_pociskow],
		rakieta[ilosc_rakiet];
	sf::Texture 
		textura_pocisku,
		textura_szybkiego_pocisku,
		textura_pocisku_w_gore,
		textura_rakiety;
	int 
		licznik_pociskow_gracza = 0,
		licznik_rakiet = 0,
		licznik_sojuszniczych = 0,
		licznik_pociskow = 0;

	//wrodzy
		//   0-czerw    1,2-heli   3-bomber   4-zielony   5-niebieski
	sf::Sprite wrog[ilosc_wrogow];
	sf::Texture textura_wroga[ilosc_wrogow];
	const int max_hp_wroga[ilosc_wrogow] = { 4,2,2,12,7,7 };
	int hp_wroga[ilosc_wrogow] = { 4,2,2,12,7,6 };
	const float v_wroga[ilosc_wrogow] = { 3.5,5,5,2.2,4,4 },
				przeladowanie[ilosc_wrogow] = { 2,0.8,0.8,2.5,2.3,2 }; // w sekundach
	float calyczas[ilosc_wrogow] = { 0,0,0,0,0,0 };
	bool lewo[ilosc_wrogow] = { 0,1,0,1,0,1 }; //zmienna odpowidadjaca za zmiane predkosci po odbiciu od sciany
		//   0-czerw    1,2-heli   3-bomber   4-zielony   5-niebieski

	//FIZYKA
	int sprawdz_kolizje();
	void ruchpociskow(float deltatime);
	void respawn();

	//otoczenie
	sf::Texture textura_chmury,
				textura_sun;

	sf::Sprite chmura1,
			   chmura2,
			   sun;
	
	//tekst
	sf::Vector2f pozycjabota,
				 pozycjagracza,
				 pozycjawroga[ilosc_pociskow_gracza];
	sf::Font czcionka;
	sf::Text text,//f1 lub esc
			 zycie,
			 punktacja;
	std::string punkty_string;
	void aktualizajca_punktow();
	int rekord,
		nowe_punkty,
		punkty=0;

	//pauza i pomoc
	sf::Texture textura_pauzy,
				textura_pomocy;
	sf::Sprite pauza,
			   pomoc;

	//eksplozje
	sf::Texture textura_expl[4];
	sf::Sprite expl[ilosc_explozji];
	int ktory; // ktory samolot zostal zestrzelony
	int licznik_expl;// by pokazywaæ kolejn¹ animacjê

	//inne
	sf::Clock zegar;
	float deltatime = 0.0f;
	void zaladujustawienia(int wybranysamolot);
	void draw(sf::RenderWindow& window);
};