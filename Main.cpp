#include <SFML/Graphics.hpp>
#include <iostream>
#include "MENU.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Moja GRA", sf::Style::Default);
	MENU glownemenu(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
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
			}
			if (evn.type == sf::Event::KeyReleased) {
				if (evn.key.code == sf::Keyboard::Up) {
					glownemenu.wGore();
					break;
				}
				if (evn.key.code == sf::Keyboard::Down) {
					glownemenu.wDol();
					break;
				}
				if (evn.key.code == sf::Keyboard::Return) {
					sf::RenderWindow Graj(sf::VideoMode(960, 720), "game_name");
					sf::RenderWindow Opcje(sf::VideoMode(960, 720), "opcjee");
					sf::RenderWindow Pomoc(sf::VideoMode(960, 720), "pomocc");

					int x = glownemenu.menuNacisniete();
					if (x == 0) {
						while (Graj.isOpen()) {
							sf::Event aevent;
							while (Graj.pollEvent(aevent)) {
								if (aevent.type == sf::Event::Closed) {
									Graj.close();
								}
							}
						}
						Opcje.close();
						Pomoc.close();
						Graj.clear();
						Graj.display();
					}
				}
			}
		}
		window.clear();
		glownemenu.draw(window);
		window.display();


	}
	return 0;
}