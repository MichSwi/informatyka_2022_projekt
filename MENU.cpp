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


void MENU::draw() {
	for (int i = 0; i < 4; i++) {
		//window.draw(pozycjeMenu[i]);
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

int MENU::petlaglowna(sf::RenderWindow& window) {
menu:
	sf::Event evn;
	while (window.isOpen()) {
		window.clear(sf::Color::Black);
		for (int i = 0; i < 4; i++) {
			window.draw(pozycjeMenu[i]);
			//std::cout << i;
		}
		//std::cout << "a";

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
					std::cout << "w gore";
					break;

				case sf::Keyboard::Down:
					wDol();
					break;
				case sf::Keyboard::Return:
					TRUDNOSC poziom(window.getSize().x, window.getSize().y);



					switch (menuNacisniete()) {
					case 0:
						if (poziom.petlaglowna(window)) {
							goto menu;
						}



						return 0;
						break;
					case 1:
						//opcje

						return 3;
						break;
					case 2:
						//pomoc
						return 4;
						break;
					case 3:
						//window
						window.close();
						break;
					}

				}
			}
		}
		window.display();
	}
}