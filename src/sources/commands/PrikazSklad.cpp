#include "PrikazSklad.h"
#include <iostream>

PrikazSklad::PrikazSklad(string param[])
{
	for (int i = 0; i < 10; i++)
		_param[i] = param[i];
}


PrikazSklad::~PrikazSklad()
{
}

void PrikazSklad::pomoc()
{
	cout << "** sklad vyskladni" << endl;
	cout << "** sklad odovzdaj" << endl;
	cout << "** sklad vypis" << endl;
	cout << "** sklad kontrola" << endl;
}

void PrikazSklad::vykonaj()
{
	if (_param[1].empty()) {
		throw runtime_error("~ Prazdny vstup");
	}
	else {
		if (_param[1] == "vyskladni" && _param[2].empty())
		{
			System::dajInstanciu().vyskladnenie();
		}
		else if (_param[1] == "odovzdaj" && _param[2].empty())
		{
			System::dajInstanciu().odovzdanieZakaznikovi();
		}
		else if (_param[1] == "vypis" && _param[2].empty())
		{
			System::dajInstanciu().vypisSkladu();
		}
		else if (_param[1] == "kontrola" && _param[2].empty())
		{
			System::dajInstanciu().kontrolaPoziadaviekZ();
		}
		else {
			throw runtime_error("~ Neplatny prikaz");
		}
	}
}
