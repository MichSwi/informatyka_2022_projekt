#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class gracz {
private:
	std::string imie;
	int punkty;
	int poziom;
public:

};













int main() {
	sf::RenderWindow okno(sf::VideoMode(1280, 720), "Gra", sf::Style::Titlebar | sf::Style::Close);
	sf::Event zamkniecie;

	while (okno.isOpen()) {
		while(okno.pollEvent(zamkniecie))
			switch (zamkniecie.type) {


			case sf::Event::Closed:
				okno.close();
				break;

			case sf::Event::KeyPressed:
				if (zamkniecie.key.code == sf::Keyboard::Escape)
				okno.close();
				break;
			}

	}
	


	okno.clear();
	
	

	
	okno.display();
	



	return 0;
}