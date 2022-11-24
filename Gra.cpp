#include "Gra.h"

Gra::Gra() 
{
	this->wgrajZmienne();
	this->wgrajOkno();
}

Gra::~Gra()
{
	delete this->okno;
}

const bool Gra::wtrakcie() const
{
	return this->okno->isOpen();
}

void Gra::pollEvents()
{
	while (this->okno->pollEvent(this->ev))
	{
		switch (this->ev.type) {


		case sf::Event::Closed:
			this->okno->close();
			break;

		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->okno->close();
			break;
		}
	}

}






void Gra::update() 
{
	this->pollEvents();

}

void Gra::render()
{
	this->okno->clear(sf::Color(255,0,0,255));

	this->okno->display();
}

void Gra::wgrajZmienne() 
{
	this->okno = nullptr;
}

void Gra::wgrajOkno() 
{
	this->videomode.height = 600;
	this->videomode.width = 800;
	this->okno = new sf::RenderWindow(sf::VideoMode(800, 600), "Gra", sf::Style::Titlebar | sf::Style::Close);
}