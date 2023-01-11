#include <SFML/Graphics.hpp>
#include <iostream>
#include "MENU.h"
#include "trudnosc.h"
#include "GRA.h"
#include "ANIMACJA.h"

int wybranastrona = 0;
int wybranysamolot = 0;
bool wyswietlPomoc = 0;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Moja GRA", sf::Style::Default);
	window.setFramerateLimit(60);


	sf::Texture pomoctextura;
	if (!pomoctextura.loadFromFile("prost.png")) {
		std::cout << "nie zaladowano prostokata!\n";
	}

	sf::RectangleShape POMOC(sf::Vector2f(120, 81));
	POMOC.setFillColor(sf::Color::Blue);
	POMOC.setPosition(50, 50);

	float deltatime = 0.0f;
	sf::Clock zegar;



	MENU glownemenu;

	trudnosc poziom(window.getSize().x, window.getSize().y);

	GRA gra(window.getSize().x, window.getSize().y);

	ANIMACJA animacja(&gra.textura_gracza[wybranysamolot], sf::Vector2u(2, 1), 0.3f);//animacja gracza

	ANIMACJA szary_menu(&poziom.samolot_textura[0], sf::Vector2u(2, 1), 0.6f);
	ANIMACJA czarny_menu(&poziom.samolot_textura[1], sf::Vector2u(2, 1), 0.6f);
	ANIMACJA papierowy_menu(&poziom.samolot_textura[2], sf::Vector2u(2, 1), 0.6f);
	


	while (window.isOpen())
	{
		deltatime = zegar.restart().asSeconds();

		if (wybranastrona == 0) {
			sf::Event evn;
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
						if (!wyswietlPomoc)
							glownemenu.wGore();
						break;

					case sf::Keyboard::Down:
						if (!wyswietlPomoc)
							glownemenu.wDol();
						break;
					case sf::Keyboard::Return:
						switch (glownemenu.menuNacisniete()) {
						case 0:
							//rozpocznij gre
							if (!wyswietlPomoc) {
								wybranastrona = 1;
							}
							break;
						case 1:
							//opcje
							if (!wyswietlPomoc) {
								wybranastrona = 3;
							}
							break;
						case 2:
							//pomoc
							if (!wyswietlPomoc) {
								wybranastrona = 4;
							}
							break;
						case 3:
							//window
							if (!wyswietlPomoc) {
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
			czarny_menu.update(0, deltatime);
			szary_menu.update(0,deltatime);
			papierowy_menu.update(0, deltatime);
			poziom.samolot_sprite[0].setTextureRect(szary_menu.poleobrazu);
			poziom.samolot_sprite[1].setTextureRect(czarny_menu.poleobrazu);
			poziom.samolot_sprite[2].setTextureRect(papierowy_menu.poleobrazu);

			if (wyswietlPomoc == 1)
				window.draw(POMOC);
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
							if (!wyswietlPomoc) {
								poziom.Enter();
								if (poziom.stan() == 1) {//powrote
									poziom.pow = 0;
									wybranastrona = 0;
									std::cout << "powrot\n";
								}
								if (poziom.stan() == 2 && poziom.licznik == 0) {//start
									wybranysamolot = poziom.wybranysamolot;
									wybranastrona = 2;
									std::cout << "start\n";
								}
							}
							break;
						case sf::Keyboard::Left:
							if (!wyswietlPomoc) {
								poziom.wLewo();
							}
							break;
						case sf::Keyboard::Right:
							if (!wyswietlPomoc) {
								poziom.wPrawo();
							}
							break;
						case sf::Keyboard::F2:
							if (wyswietlPomoc == 1) 
								wyswietlPomoc = 0;
							else
								wyswietlPomoc = 1;
							break;
						}
				}
			}
		}
		if (wybranastrona == 2) {//faktyczna gra


			window.clear(sf::Color::Blue);
			gra.wybierzsamolot(wybranysamolot);
			animacja.update(0, deltatime);
			////////////////////////////////////////////CZY TO MA BYC?
			gra.gracz.setTextureRect(animacja.poleobrazu);
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if (poziom.wybranygracz == 2) {
				gra.ruchbota();
				gra.draw_bot(window);
			}
			gra.sprawdz_kolizje();
			gra.ruchpociskow();
			gra.draw(window);
			window.display();

			sf::Event evn;

			


			while (window.pollEvent(evn)) {
				if (evn.type == sf::Event::Closed || evn.key.code == sf::Keyboard::Escape)
					window.close();
				if (evn.type == sf::Event::KeyReleased && evn.key.code == sf::Keyboard::Space) {
					gra.strzal();
				}
			}
				
			switch (evn.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (evn.key.code == sf::Keyboard::Escape)
						window.close();
					if (evn.key.code == sf::Keyboard::Left) {
						gra.ruchgracza(0);
					}
					if (evn.key.code == sf::Keyboard::Right) {
						gra.ruchgracza(1);
					}
					break;					
			}
		}

			if (wybranastrona == 4) {//pomoc
				window.clear(sf::Color::Blue);
				window.draw(POMOC);
				window.display();
				sf::Event(evn);
				while (window.pollEvent(evn) && wybranastrona == 4) {
					switch (evn.type) {
					case sf::Event::Closed:
						window.close();
						break;
					case sf::Event::KeyReleased:
						if (evn.key.code == sf::Keyboard::Escape)
							window.close();
						if (evn.key.code == sf::Keyboard::Return) {
							wybranastrona = 0;
						}
						if (evn.key.code == sf::Keyboard::F2) {
							wybranastrona = 0;
						}
						break;
					}
				}
			}
		}
		return 0;
	}
