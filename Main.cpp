#include <iostream>
#include <cstdlib>
#include "Gra.h"

class gracz {
private:
	std::string imie;
	int punkty;
	int poziom;
public:

};


int main() {
	
	Gra gra;

	while (gra.wtrakcie())
	{
		gra.update();


		gra.render();

		
	}
	return 0;
}