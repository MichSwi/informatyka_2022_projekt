#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "MENU.h"
#include "TRUDNOSC.h"
#include "GRA.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Moja GRA", sf::Style::Default);
	window.setFramerateLimit(60);

	MENU glownemenu;

	glownemenu.petlaglowna(window);


	return 0;
}