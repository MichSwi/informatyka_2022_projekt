#include "TRUDNOSC.h"
#include "ANIMACJA.h"
#include "GRA.h"
#include "GAME_OVER.h"


//RYSOWANIE I UZYWANIE USTAWIEN GRY PO WYBRANIU "ROZPOCZNIJ" W GLOWNYM MENU

TRUDNOSC::TRUDNOSC() {
	if (!czcionka.loadFromFile("czcionka.ttf")) {
		std::cout << "Brak czcionki\n";
	}

	//sojusznik czy samemu?
	text1.setFont(czcionka);
	text1.setFillColor(sf::Color::White);
	text1.setCharacterSize(70);
	text1.setString("Czy chcesz miec sojusznika?");
	text1.setPosition(180, 100);

	//samemu 
	gracz[0].setFont(czcionka);
	gracz[0].setFillColor(sf::Color::Red);
	gracz[0].setCharacterSize(70);
	gracz[0].setString("Nie");
	gracz[0].setPosition(300, 200);

	//z sojusznikiem
	gracz[1].setFont(czcionka);
	gracz[1].setFillColor(sf::Color::White);
	gracz[1].setCharacterSize(70);
	gracz[1].setString("Tak");
	gracz[1].setPosition(500, 200);

	//Wybierz samolot
	text2.setFont(czcionka);
	text2.setFillColor(sf::Color::White);
	text2.setCharacterSize(70);
	text2.setString("Wybierz samolot:");
	text2.setPosition(280, 400);

	samolot[0].setFont(czcionka);
	samolot[0].setFillColor(sf::Color::White);
	samolot[0].setCharacterSize(50);
	samolot[0].setString("samolot 0");
	samolot[0].setPosition(175, 500);

	samolot[1].setFont(czcionka);
	samolot[1].setFillColor(sf::Color::White);
	samolot[1].setCharacterSize(50);
	samolot[1].setString("samolot 1");
	samolot[1].setPosition(350, 500);

	samolot[2].setFont(czcionka);
	samolot[2].setFillColor(sf::Color::White);
	samolot[2].setCharacterSize(50);
	samolot[2].setString("samolot 2");
	samolot[2].setPosition(525, 500);

	samolot_textura[0].loadFromFile("gracz_szary_idle.png");
	samolot_sprite[0].scale(2, 2);
	samolot_sprite[0].setTexture(samolot_textura[0]);
	samolot_sprite[0].setPosition(1000, 200);

	samolot_textura[1].loadFromFile("gracz_nie_pixel.png");
	samolot_sprite[1].setTexture(samolot_textura[1]);
	samolot_sprite[1].setPosition(1000, 200);
	samolot_sprite[1].scale(2, 2);

	samolot_textura[2].loadFromFile("gracz_paap.png");
	samolot_sprite[2].setTexture(samolot_textura[2]);
	samolot_sprite[2].setPosition(1000, 200);
	samolot_sprite[2].scale(2.6, 2.6);

	sojusznik_textura.loadFromFile("bot.png");
	sojusznik_sprite.setTexture(sojusznik_textura);
	sojusznik_sprite.setPosition(1050, 250);
	sojusznik_sprite.scale(2, 2);

	//NAPIS ZATWIERDZ
	zatw.setFont(czcionka);
	zatw.setFillColor(sf::Color::White);
	zatw.setCharacterSize(70);
	zatw.setString("Zatwierdz");
	zatw.setPosition(250, 700);

	//NAPIS POWROT
	powr.setFont(czcionka);
	powr.setFillColor(sf::Color::White);
	powr.setCharacterSize(70);
	powr.setString("Powrot");
	powr.setPosition(480, 700);

	//STATYSTYKI
	for (int i = 0; i < 3; i++) {
		statystyki[i].setFont(czcionka);
		statystyki[i].setFillColor(sf::Color::White);
		statystyki[i].setCharacterSize(90);
		statystyki[i].setPosition(1000, 600);
	}
	statystyki[0].setString("Predkosc:15\nObrazenia:3\nWytrzymalosc:20");
	statystyki[1].setString("Predkosc:7\nObrazenia:2\nWytrzymalosc:8");
	statystyki[2].setString("Predkosc:3.5\nObrazenia:1\nWytrzymalosc:1");

	sojusznik_staty.setFont(czcionka);
	sojusznik_staty.setString("Predkosc:3\nObrazenia:1\nWytrzymalosc:+inf\nPrzeladowanie: 0.5s");
	sojusznik_staty.setCharacterSize(80);
	sojusznik_staty.setPosition(1000, 460);
	sojusznik_staty.setFillColor(sf::Color::White);

	sojusznik = 0;
	rysuj_sojusznika = 0;


}
void TRUDNOSC::draw(sf::RenderWindow& window) {
	window.draw(text1);
	window.draw(gracz[0]);
	window.draw(gracz[1]);
	window.draw(text2);
	for (int i = 0; i < 3; i++) {
		window.draw(samolot[i]);
	}
	switch (rysuj_staty) {
	case 0:
		window.draw(statystyki[0]);
		window.draw(samolot_sprite[0]);
		break;
	case 1:
		window.draw(statystyki[1]);
		window.draw(samolot_sprite[1]);
		break;
	case 2:
		window.draw(statystyki[2]);
		window.draw(samolot_sprite[2]);
		break;
	}
	if (rysuj_sojusznika) {
		window.draw(sojusznik_sprite);
		window.draw(sojusznik_staty);
	}
	window.draw(zatw);
	window.draw(powr);
}


//FUNKCJA SIE WYKONUJE PO NACISNIECIU ENTER
void TRUDNOSC::Enter() {
	licznik++; // LICZY OD 0 DO 2 (PRZY 3 RESET) - MOWI W JAKIEJ LINI JESTESMY
	if (licznik == 3) {
		licznik = 0;
	}
	if (licznik == 0 && sojusznik == 1) {						//LINIA 0 - SAMEMU / Z SOJUSZNIKIEM
		gracz[0].setFillColor(sf::Color::Red);
		rysuj_sojusznika = 1;
	}

	if (licznik == 1) {									//LINIA 1 - SAMOLOT 1/2/3
		rysuj_sojusznika = 0;
		samolot[1].setFillColor(sf::Color::Red);
		wybranysamolot = 1;//domyslnie wybierany srodkowy samolot
		rysuj_staty = 1;
	}
	if (licznik == 2) {
		zatw.setFillColor(sf::Color::Red);
		pow = 2;//domyslnie wybierane zatwierdz
	}
	if (licznik == 0 && pow == 1) {
		//reset kolorow po powrocie do menu glownego
		gracz[1].setFillColor(sf::Color::White);
		samolot[0].setFillColor(sf::Color::White);
		samolot[1].setFillColor(sf::Color::White);
		samolot[2].setFillColor(sf::Color::White);
		powr.setFillColor(sf::Color::White);
		zatw.setFillColor(sf::Color::White);
		rysuj_staty = -1;
	}
}

//co sie dzieje po kliknieciu strzalki w lewo
void TRUDNOSC::wLewo() {
	if (licznik == 0) {							//wybor ilosci graczy
		pow = 0;
		gracz[0].setFillColor(sf::Color::Red);
		gracz[1].setFillColor(sf::Color::White);
		sojusznik = 0;
		rysuj_sojusznika = 0;
		
	}
	if (licznik == 1 && wybranysamolot == 1) {	//wybor samolotu
		pow = 0;
		samolot[0].setFillColor(sf::Color::Red);
		samolot[1].setFillColor(sf::Color::White);
		samolot[2].setFillColor(sf::Color::White);
		wybranysamolot = 0;
		rysuj_staty = 0;

		//	std::cout << wybranysamolot;

	}
	if (licznik == 1 && wybranysamolot == 2) {	//wybor samolotu
		samolot[0].setFillColor(sf::Color::White);
		samolot[1].setFillColor(sf::Color::Red);
		samolot[2].setFillColor(sf::Color::White);
		wybranysamolot = 1;
		rysuj_staty = 1;

		//std::cout << wybranysamolot;

	}
	if (licznik == 2) {							//wybor zatwierdz/powrot
		zatw.setFillColor(sf::Color::Red);
		powr.setFillColor(sf::Color::White);
		pow = 2;//zatwierdz
	}
}

//co sie dzieje po kliknieciu strzalki w prawo
void TRUDNOSC::wPrawo() {
	if (licznik == 0) {							//wybor 1gracz/2graczy
		gracz[0].setFillColor(sf::Color::White);
		gracz[1].setFillColor(sf::Color::Red);
		sojusznik = 1;//2 graczy
		rysuj_sojusznika = 1;
	}
	if (licznik == 1 && wybranysamolot == 1) {	//wybor samolotow
		samolot[0].setFillColor(sf::Color::White);
		samolot[1].setFillColor(sf::Color::White);
		samolot[2].setFillColor(sf::Color::Red);
		wybranysamolot = 2;
		rysuj_staty = 2;

		//std::cout << wybranysamolot;

	}
	if (licznik == 1 && wybranysamolot == 0) {
		samolot[0].setFillColor(sf::Color::White);
		samolot[1].setFillColor(sf::Color::Red);
		samolot[2].setFillColor(sf::Color::White);
		wybranysamolot = 1;
		rysuj_staty = 1;
		//std::cout << wybranysamolot;

	}
	if (licznik == 2) {							//wybor zatwierdz/powrot
		zatw.setFillColor(sf::Color::White);
		powr.setFillColor(sf::Color::Red);
		pow = 1;// powrot
	}
}

int TRUDNOSC::petlaglowna(sf::RenderWindow& window) {
	ANIMACJA szary_menu(&samolot_textura[0], sf::Vector2u(2, 1), 0.6f);
	ANIMACJA czarny_menu(&samolot_textura[1], sf::Vector2u(2, 1), 0.6f);
	ANIMACJA papierowy_menu(&samolot_textura[2], sf::Vector2u(2, 1), 0.6f);


	while (window.isOpen()) {

		deltatime = zegar.restart().asSeconds();

		window.clear();
		draw(window);

		czarny_menu.update(0, deltatime);
		szary_menu.update(0, deltatime);
		papierowy_menu.update(0, deltatime);
		samolot_sprite[0].setTextureRect(szary_menu.poleobrazu);
		samolot_sprite[1].setTextureRect(czarny_menu.poleobrazu);
		samolot_sprite[2].setTextureRect(papierowy_menu.poleobrazu);


		window.display();
		sf::Event evn;
		while (window.pollEvent(evn)) {

			switch (evn.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (evn.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			case sf::Event::KeyReleased:
				switch (evn.key.code) {
				case sf::Keyboard::Return:
					Enter();
					if (stan() == 1) {//powrot
						pow = 0;
						return 1;////POWROT
						std::cout << "powrot\n";
					}
					if (stan() == 2 && licznik == 0) {//start
						GRA gra(sojusznik, wybranysamolot);
						if (gra.petlaglowna(window))
							return 1;
					}
					break;
				case sf::Keyboard::Left:
					wLewo();
					break;
				case sf::Keyboard::Right:
					wPrawo();
					break;
				}
			}
		}
	}
}