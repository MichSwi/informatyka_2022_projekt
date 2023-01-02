#include "trudnosc.h"

trudnosc::trudnosc(float wys, float szer) {
	if (!czcionka.loadFromFile("czcionka.ttf")) {
		std::cout << "Brak czcionki\n";
	}

	//1 czy 2 graczy
	text1.setFont(czcionka);
	text1.setFillColor(sf::Color::White);
	text1.setCharacterSize(70);
	text1.setString("Wybierz ilosc graczy:");
	text1.setPosition(300, 100);

	//1 gracz 
	gracz[0].setFont(czcionka);
	gracz[0].setFillColor(sf::Color::Red);
	gracz[0].setCharacterSize(70);
	gracz[0].setString("1 gracz");
	gracz[0].setPosition(200, 200);

	//2 graczy
	gracz[1].setFont(czcionka);
	gracz[1].setFillColor(sf::Color::White);
	gracz[1].setCharacterSize(70);
	gracz[1].setString("2 graczy");
	gracz[1].setPosition(400, 200);

	//Wybierz samolot
	text2.setFont(czcionka);
	text2.setFillColor(sf::Color::White);
	text2.setCharacterSize(70);
	text2.setString("Wybierz samolot:");
	text2.setPosition(300, 300);

	samolot[0].setFont(czcionka);
	samolot[0].setFillColor(sf::Color::White);
	samolot[0].setCharacterSize(50);
	samolot[0].setString("samolot 0");
	samolot[0].setPosition(175,400);

	samolot[1].setFont(czcionka);
	samolot[1].setFillColor(sf::Color::White);
	samolot[1].setCharacterSize(50);
	samolot[1].setString("samolot 1");
	samolot[1].setPosition(350, 400);

	samolot[2].setFont(czcionka);
	samolot[2].setFillColor(sf::Color::White);
	samolot[2].setCharacterSize(50);
	samolot[2].setString("samolot 2");
	samolot[2].setPosition(525, 400);

	zatw.setFont(czcionka);
	zatw.setFillColor(sf::Color::White);
	zatw.setCharacterSize(70);
	zatw.setString("Zatwierdz");
	zatw.setPosition(250, 600);

	powr.setFont(czcionka);
	powr.setFillColor(sf::Color::White);
	powr.setCharacterSize(70);
	powr.setString("Powrot");
	powr.setPosition(450, 600);
}
void trudnosc::draw(sf::RenderWindow& window) {
	window.draw(text1);
	window.draw(gracz[0]);
	window.draw(gracz[1]);
	window.draw(text2);
	for(int i=0;i<3;i++)
	window.draw(samolot[i]);
	window.draw(zatw);
	window.draw(powr);
}

void trudnosc::Enter() {
	licznik++;
	std::cout << "licznik=" << licznik << "\n";
	if (licznik == 3) {
		licznik = 0;
	}
//	std::cout << licznik;
	if(licznik==0){
		gracz[0].setFillColor(sf::Color::Red);
		wybranygracz = 1;
	}
	if (licznik == 1) {
		samolot[1].setFillColor(sf::Color::Red);
		wybranysamolot = 1;
	}
	if (licznik == 2) {
		zatw.setFillColor(sf::Color::Red);
		pow = 2;//zatwierdz
	}
	if (licznik == 0 && pow == 1) {
		gracz[1].setFillColor(sf::Color::White);
		samolot[0].setFillColor(sf::Color::White);
		samolot[1].setFillColor(sf::Color::White);
		samolot[2].setFillColor(sf::Color::White);
		powr.setFillColor(sf::Color::White);
		zatw.setFillColor(sf::Color::White);
	}
}


void trudnosc::wLewo() {
	if (licznik == 0) {		
		pow = 0;//wybor ilosci graczy
		gracz[0].setFillColor(sf::Color::Red);
		gracz[1].setFillColor(sf::Color::White);
		wybranygracz = 1;//1gracz
	}
	if (licznik == 1 && wybranysamolot == 1) {	
		pow = 0;		//wybor samolotu
		samolot[0].setFillColor(sf::Color::Red);
		samolot[1].setFillColor(sf::Color::White);
		samolot[2].setFillColor(sf::Color::White);
		wybranysamolot = 0;
	//	std::cout << wybranysamolot;

	}
	if (licznik == 1 && wybranysamolot == 2) {
		samolot[0].setFillColor(sf::Color::White);
		samolot[1].setFillColor(sf::Color::Red);
		samolot[2].setFillColor(sf::Color::White);
		wybranysamolot = 1;
		//std::cout << wybranysamolot;

	}
	if (licznik == 2) {
		zatw.setFillColor(sf::Color::Red);
		powr.setFillColor(sf::Color::White);
		pow = 2;//zatwierdz
	}
}

void trudnosc::wPrawo() {
	if (licznik == 0) {
		gracz[0].setFillColor(sf::Color::White);
		gracz[1].setFillColor(sf::Color::Red);
		wybranygracz = 2;//2 graczy
	}
	if (licznik == 1 && wybranysamolot == 1) {
		samolot[0].setFillColor(sf::Color::White);
		samolot[1].setFillColor(sf::Color::White);
		samolot[2].setFillColor(sf::Color::Red);
		wybranysamolot = 2;
		//std::cout << wybranysamolot;

	}
	if (licznik == 1 && wybranysamolot==0) {
		samolot[0].setFillColor(sf::Color::White);
		samolot[1].setFillColor(sf::Color::Red);
		samolot[2].setFillColor(sf::Color::White);
		wybranysamolot = 1;
	//	std::cout << wybranysamolot;

	}
	if (licznik == 2) {
		zatw.setFillColor(sf::Color::White);
		powr.setFillColor(sf::Color::Red);
		pow = 1;// powrot
	}


}