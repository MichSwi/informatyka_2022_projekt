#include <SFML/Graphics.hpp>
#include <iostream>
#include "MENU.h"
#include "trudnosc.h"

int wybranastrona = 0;

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 800), "Moja GRA", sf::Style::Default);
	MENU glownemenu(window.getSize().x, window.getSize().y);
	trudnosc poziom(window.getSize().x, window.getSize().y);
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
						poziom.Enter();
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
	}
	return 0;
}