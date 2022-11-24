#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#pragma once

class Gra
{
private:
	sf::RenderWindow* okno;
	sf::VideoMode videomode;
	sf::Event ev;


	void wgrajZmienne();
	void wgrajOkno();
public:
	Gra();
	virtual ~Gra();


	 
	const bool wtrakcie() const;


	void pollEvents();
	void update();
	void render();

};
