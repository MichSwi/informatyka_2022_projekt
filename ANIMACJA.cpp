#include "ANIMACJA.h"
#include <iostream>

ANIMACJA::ANIMACJA(sf::Texture *teksturaanimacji, sf::Vector2u licznikobrazu, float czaszmiany) {
	this->licznikobrazu = licznikobrazu;
	this->czaszmiany = czaszmiany;
	calyczas = 0.0f;
	wybranyobraz.x = 0;

	poleobrazu.width = teksturaanimacji->getSize().x / float(licznikobrazu.x);
	poleobrazu.height = teksturaanimacji->getSize().y / float(licznikobrazu.y);


}

void ANIMACJA::update(int row, float deltatime) {
	wybranyobraz.y = row;
	calyczas += deltatime;
	if (calyczas >= czaszmiany)
	{
		calyczas -= czaszmiany;
		wybranyobraz.x++;

		if (wybranyobraz.x >= licznikobrazu.x) {
			wybranyobraz.x = 0;
		}

	}
	poleobrazu.left = wybranyobraz.x * poleobrazu.width;
	poleobrazu.top = wybranyobraz.y * poleobrazu.height;
}
