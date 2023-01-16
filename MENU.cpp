#include "MENU.h"
#include <fstream>
#include <string>


//RYSOWANIE I UZYWANIE GLOWNEGO MENU

MENU::MENU() {

	if (!czcionka.loadFromFile("czcionka.ttf")) {
		std::cout << "Brak czcionki\n";
	}

	obecny_rekord.setFont(czcionka);
	obecny_rekord.setFillColor(sf::Color::White);
	obecny_rekord.setCharacterSize(70);
	obecny_rekord.setPosition(1500, 930);

	



	//ROZPOCZNIJ GRE
	pozycjeMenu[0].setFont(czcionka);
	pozycjeMenu[0].setFillColor(sf::Color::Red);
	pozycjeMenu[0].setCharacterSize(150);
	pozycjeMenu[0].setString("Rozpocznij Gre");
	pozycjeMenu[0].setPosition(650, 200);
	//OPCJE
	pozycjeMenu[1].setFont(czcionka);
	pozycjeMenu[1].setFillColor(sf::Color::White);
	pozycjeMenu[1].setCharacterSize(150);
	pozycjeMenu[1].setString("Pomoc");
	pozycjeMenu[1].setPosition(800, 400);
	//POMOC
	pozycjeMenu[2].setFont(czcionka);
	pozycjeMenu[2].setFillColor(sf::Color::White);
	pozycjeMenu[2].setCharacterSize(150);
	pozycjeMenu[2].setString("Wyjdz");
	pozycjeMenu[2].setPosition(810, 600);
	//WYJDZ
	menuWybrane = 0;
}


void MENU::draw(sf::RenderWindow &window) {
	for (int i = 0; i < 3; i++) {
		window.draw(pozycjeMenu[i]);
	}
	window.draw(obecny_rekord);
}

//PRZESUNIECIE W GORE (STRZALKA W GORE)
void MENU::wGore() {
	menuWybrane--;
	if (menuWybrane == -1)
		menuWybrane = 2;
	switch (menuWybrane) {
	case 0:
		pozycjeMenu[0].setFillColor(sf::Color::Red);
		pozycjeMenu[1].setFillColor(sf::Color::White);
		pozycjeMenu[2].setFillColor(sf::Color::White);
		break;
	case 1:
		pozycjeMenu[0].setFillColor(sf::Color::White);
		pozycjeMenu[1].setFillColor(sf::Color::Red);
		pozycjeMenu[2].setFillColor(sf::Color::White);
		break;
	case 2:
		pozycjeMenu[0].setFillColor(sf::Color::White);
		pozycjeMenu[1].setFillColor(sf::Color::White);
		pozycjeMenu[2].setFillColor(sf::Color::Red);
		break;
	}
}

//PRZESUNIECIE W DOL (STRZALKA W DOL)
void MENU::wDol() {
	menuWybrane++;
	if (menuWybrane == 3)
		menuWybrane = 0;
	switch (menuWybrane) {
	case 0:
		pozycjeMenu[0].setFillColor(sf::Color::Red);
		pozycjeMenu[1].setFillColor(sf::Color::White);
		pozycjeMenu[2].setFillColor(sf::Color::White);
		break;
	case 1:
		pozycjeMenu[0].setFillColor(sf::Color::White);
		pozycjeMenu[1].setFillColor(sf::Color::Red);
		pozycjeMenu[2].setFillColor(sf::Color::White);
		break;
	case 2:
		pozycjeMenu[0].setFillColor(sf::Color::White);
		pozycjeMenu[1].setFillColor(sf::Color::White);
		pozycjeMenu[2].setFillColor(sf::Color::Red);
		break;
	}
}


int MENU::petlaglowna(sf::RenderWindow& window) {
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(0);
menu:
	int rekord;
	std::ifstream odczyt;
	odczyt.open("dane.txt");
	odczyt >> rekord;
	odczyt.close();
	obecny_rekord.setString("Obecny rekord: " + std::to_string(rekord));
	sf::Event evn;
	while (window.isOpen()) {
		window.clear(sf::Color::Black);
		draw(window);

		while (window.pollEvent(evn))
		{
			switch (evn.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (evn.key.code == sf::Keyboard::Escape) {
					std::cout << "WYJDZ - ESC\n\n";
					window.close();
				}
				break;
			case sf::Event::KeyReleased:
				switch (evn.key.code) {
				case sf::Keyboard::Up:
					wGore();
					break;
				case sf::Keyboard::Down:
					wDol();
					break;
				case sf::Keyboard::Return:
					std::cout << menuWybrane;
					TRUDNOSC poziom;
					switch (menuNacisniete()) {
					case 0:
						if (poziom.petlaglowna(window)) {
							goto menu;
						}
						break;
					case 1:
						//pomoc
						return 3;
						break;
					case 2:
						//wyjdz
						window.close();
						break;
					}
				}
			}
		}
		window.display();
	}
}