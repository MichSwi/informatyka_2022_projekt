#include "MENU.h"


//RYSOWANIE I UZYWANIE GLOWNEGO MENU

MENU::MENU() {
	if (!czcionka.loadFromFile("czcionka.ttf")) {
		std::cout << "Brak czcionki\n";
	}

	//ROZPOCZNIJ GRE
	pozycjeMenu[0].setFont(czcionka);
	pozycjeMenu[0].setFillColor(sf::Color::Red);
	pozycjeMenu[0].setCharacterSize(70);
	pozycjeMenu[0].setString("Rozpocznij Gre");
	pozycjeMenu[0].setPosition(400, 200);
	//OPCJE
	pozycjeMenu[1].setFont(czcionka);
	pozycjeMenu[1].setFillColor(sf::Color::White);
	pozycjeMenu[1].setCharacterSize(70);
	pozycjeMenu[1].setString("Opcje");
	pozycjeMenu[1].setPosition(400, 300);
	//POMOC
	pozycjeMenu[2].setFont(czcionka);
	pozycjeMenu[2].setFillColor(sf::Color::White);
	pozycjeMenu[2].setCharacterSize(70);
	pozycjeMenu[2].setString("Pomoc");
	pozycjeMenu[2].setPosition(400, 400);
	//WYJDZ
	pozycjeMenu[3].setFont(czcionka);
	pozycjeMenu[3].setFillColor(sf::Color::White);
	pozycjeMenu[3].setCharacterSize(70);
	pozycjeMenu[3].setString("Wyjdz");
	pozycjeMenu[3].setPosition(400, 500);

	menuWybrane = 0;
}

MENU::~MENU() {
}


void MENU::draw(sf::RenderWindow &window) {
	for (int i = 0; i < 4; i++) {
		window.draw(pozycjeMenu[i]);
	}
}

//PRZESUNIECIE W GORE (STRZALKA W GORE)
void MENU::wGore() {
	if (menuWybrane == -1) {
		menuWybrane = 3;
		pozycjeMenu[menuWybrane].setFillColor(sf::Color::Red);
	}
	else {

		pozycjeMenu[menuWybrane].setFillColor(sf::Color::White);
		menuWybrane--;
		if (menuWybrane == -1) {
			menuWybrane = 3;
		}
		pozycjeMenu[menuWybrane].setFillColor(sf::Color::Red);
	}
}

//PRZESUNIECIE W DOL (STRZALKA W DOL)
void MENU::wDol() {
	if (menuWybrane == -1) {
		menuWybrane = 0;
		pozycjeMenu[menuWybrane].setFillColor(sf::Color::Red);
	}
	else {
		pozycjeMenu[menuWybrane].setFillColor(sf::Color::White);
		menuWybrane++;
		if (menuWybrane == 4) {
			menuWybrane = 0;
		}
		pozycjeMenu[menuWybrane].setFillColor(sf::Color::Red);
	}
}