#include "ANIMACJA.h"
#include <iostream>

ANIMACJA::ANIMACJA(sf::Texture* teksturaanimacji, sf::Vector2u licznikobrazu, float czaszmiany) {
	this->licznikobrazu = licznikobrazu;
	this->czaszmiany = czaszmiany;
	calyczas = 0.0f;
	wybranyobraz.x = 0;

	poleobrazu.width = teksturaanimacji->getSize().x / float(licznikobrazu.x);
	poleobrazu.height = teksturaanimacji->getSize().y / float(licznikobrazu.y);

	wybranyobraz.y = 1;
}

void ANIMACJA::update(int row, float deltatime, bool tryb) {
	if (tryb == 0)//w kolko
		wybranyobraz.y = 1;
	if (tryb == 0)//jednorazowo
		wybranyobraz.y = row;
	calyczas += deltatime;
	if (calyczas >= czaszmiany)
	{
		calyczas -= czaszmiany;
		wybranyobraz.x++;

		if (wybranyobraz.x >= licznikobrazu.x && tryb==0) {
			wybranyobraz.x = 0;
		}
		else if (wybranyobraz.x >= licznikobrazu.x && tryb == 1) {
			wybranyobraz.x = 0;
			wybranyobraz.y++;
		}

	}
	if (wybranyobraz.y < 7) {
		poleobrazu.left = wybranyobraz.x * poleobrazu.width;
		poleobrazu.top = wybranyobraz.y * poleobrazu.height;
	}
}

void ANIMACJA::reset() {
		wybranyobraz.y = 0;	
}