#include <SFML/Graphics.hpp>
#include <iostream>
#include "MENU.h"
#include "trudnosc.h"
#include "GRA.h"

int wybranastrona = 0;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1800, 1000), "Moja GRA", sf::Style::Default);
	MENU glownemenu(window.getSize().x, window.getSize().y);
	trudnosc poziom(window.getSize().x, window.getSize().y);
	GRA gra(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		if (wybranastrona == 0) {
			//std::cout << "test\n";
			window.clear();
			glownemenu.draw(window);
			window.display();
			sf::Event evn;
			while (window.pollEvent(evn))
			{

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
					case sf::Keyboard::Up:
						glownemenu.wGore();
						break;

					case sf::Keyboard::Down:
						glownemenu.wDol();
						break;
					case sf::Keyboard::Return:
						switch (glownemenu.menuNacisniete()) {
						case 0:
							std::cout << "zatwierdzono menu 0 || ";
							wybranastrona = 1;
							break;
						case 1:
							std::cout << "zatwierdzono menu 1 || ";
							wybranastrona = 2;
							break;
						case 2:
							std::cout << "zatwierdzono menu 2 || ";
							wybranastrona = 3;
							break;
						case 3:
							std::cout << "wybrano menu 3";
							window.close();
							break;
						}

					}
				}
			}
		}
		if (wybranastrona == 1) {
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
		if (wybranastrona == 2) {
			window.clear();
			gra.draw(window);
			window.display();
			sf::Event evn;
			while (window.pollEvent(evn) && wybranastrona == 2) {
				switch (evn.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (evn.key.code == sf::Keyboard::Escape)
						window.close();
					if (evn.key.code == sf::Keyboard::Left) {
						gra.ruch1(0);
				//		std::cout << "lewo\n";
					}
					if (evn.key.code == sf::Keyboard::Right) {
						gra.ruch1(1);
				//		std::cout << "prawo\n";
					}
					if (evn.key.code == sf::Keyboard::A) {
						gra.ruch2(0);
						std::cout << "lewo\n";
					}
					if (evn.key.code == sf::Keyboard::D) {
						gra.ruch2(1);
						std::cout << "prawo\n";
					}
					break;
				}

			}
		}
	}
		return 0;
}