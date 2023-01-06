#include <SFML/Graphics.hpp>
#include <iostream>
#include "MENU.h"
#include "trudnosc.h"
#include "GRA.h"

int wybranastrona = 0;
bool wyswietlPomoc = 0;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1800, 1000), "Moja GRA", sf::Style::Default);
//	MENU glownemenu(window.getSize().x, window.getSize().y);
	sf::RectangleShape POMOC(sf::Vector2f(500, 500));

	window.setFramerateLimit(60);

	POMOC.setFillColor(sf::Color::Blue);
	POMOC.setPosition(50, 50); 

	MENU glownemenu;
	trudnosc poziom(window.getSize().x, window.getSize().y);
	GRA gra(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		if (wybranastrona == 0) {
			sf::Event evn;
			//std::cout << "test\n";
			window.clear();
			glownemenu.draw(window);

			if (wyswietlPomoc == 1) {
				window.draw(POMOC);
			}
			
			window.display();
			
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
					case sf::Keyboard::F2:
						if (wyswietlPomoc == 1)
							wyswietlPomoc = 0;
						else
							wyswietlPomoc = 1;
						break;
					case sf::Keyboard::Up:
						if(!wyswietlPomoc)
							glownemenu.wGore();
						break;

					case sf::Keyboard::Down:
						if(!wyswietlPomoc)
							glownemenu.wDol();
						break;
					case sf::Keyboard::Return:
						switch (glownemenu.menuNacisniete()) {
						case 0:
							//rozpoczinj gre
							if (!wyswietlPomoc) {
								std::cout << "zatwierdzono menu rozpocznij || ";
								wybranastrona = 1;
							}
							break;
						case 1:
							//opcje
							if (!wyswietlPomoc) {
								std::cout << "zatwierdzono menu opcje || ";
								wybranastrona = 3;
							}
							break;
						case 2:
							//pomoc
							if (!wyswietlPomoc) {
								std::cout << "zatwierdzono menu pomoc || ";
								wybranastrona = 4;
							}
							break;
						case 3:
							//window
							if (!wyswietlPomoc) {
								std::cout << "wybrano menu wyjdz";
								window.close();
							}
							break;
						}

					}
				}
			}
		}
		if (wybranastrona == 1) {//wybor samolotu
			window.clear();
			poziom.draw(window);
			window.display();
			sf::Event evn;
			while (window.pollEvent(evn) && wybranastrona == 1) {

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
						poziom.Enter();
						if (poziom.stan() == 1) {
							poziom.pow = 0;
							std::cout << "powrot";
							wybranastrona = 0;
						}
						if (poziom.stan() == 2 && poziom.licznik == 0) {
							std::cout << "graj----------\n";
							wybranastrona = 2;
						}
						break;
					case sf::Keyboard::Left:
						poziom.wLewo();
						break;
					case sf::Keyboard::Right:
						poziom.wPrawo();
						break;
					}
				}
			}
		}
		if (wybranastrona == 2) {//faktyczna gra
			
				window.setFramerateLimit(60);
				gra.ruchbota();
				window.clear(sf::Color::White);
				gra.draw(window);
				window.display();
				sf::Event evn;
				
				while (window.pollEvent(evn)) {
					if (evn.type == sf::Event::Closed || evn.key.code == sf::Keyboard::Escape)
						window.close();
					gra.ruchbota();
				}
/*
				switch (evn.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (evn.key.code == sf::Keyboard::Escape)
						window.close();
					if (evn.key.code == sf::Keyboard::Left) {
						gra.ruchgracza(0);
				//		std::cout << "lewo\n";
					}
					if (evn.key.code == sf::Keyboard::Right) {
						gra.ruchgracza(1);
				//		std::cout << "prawo\n";
					}
				}*/

			
		}
		if (wybranastrona == 4) {//pomoc

			std::cout << "wybrano pomoc poprawnie\n";;

			window.clear(sf::Color::White);
			window.draw(POMOC);
			window.display();
			sf::Event(evn);
			while (window.pollEvent(evn) && wybranastrona == 4) {
				std::cout << "window.pollEvent dziala\n\n";
				switch (evn.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyReleased:
					if (evn.key.code == sf::Keyboard::Escape)
						window.close();
					if (evn.key.code == sf::Keyboard::Return) {
						std::cout << "\n - zamknieto pomoc enterem -\n";
						wybranastrona = 0;
					}
					if (evn.key.code == sf::Keyboard::F2) {
						std::cout << "\n - zamknieto pomoc F2 -\n";
						wybranastrona = 0;
					}
					break;
				}
			}

		}
	}
		return 0;
}