#include <SFML/Graphics.hpp> 
#include "MENU.h"
int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pixel Dogfight", sf::Style::Fullscreen);
	MENU glownemenu;
	glownemenu.petlaglowna(window);
	return 0;
}