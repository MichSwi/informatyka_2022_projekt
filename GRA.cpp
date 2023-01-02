#include "GRA.h"

GRA::GRA(float szer,float wys) {

	texture.loadFromFile("test.png");

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(10, 10, 100, 300));
	sprite.setColor(sf::Color(255, 255, 255, 200));
	sprite.setPosition(100, 25);

	texture2.loadFromFile("test2.png");

	sprite2.setTexture(texture2);
	sprite2.setTextureRect(sf::IntRect(10, 10, 100, 300));
	sprite2.setColor(sf::Color(255, 255, 255, 200));
	sprite2.setPosition(100, 25);

}

void GRA::draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.draw(sprite2);
}
void GRA::ruch1(int i) {
		if (i == 0) {
			sprite.move(-v, 0);
		}
		if (i == 1) {
			sprite.move(v, 0);
		}
 }

void GRA::ruch2(int i) {
	if (i == 0) {
		sprite2.move(-v, 0);
	}
	if (i == 1) {
		sprite2.move(v, 0);
	}
}