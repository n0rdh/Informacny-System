#include "PrikazZakaznik.h"



PrikazZakaznik::PrikazZakaznik(string param[])
{
	for (int i = 0; i < 10; i++)
		_param[i] = param[i];
}


PrikazZakaznik::~PrikazZakaznik()
{
}

void PrikazZakaznik::pomoc()
{
	cout << "** zakaznik pridaj |meno| |adresa|" << endl;
	cout << "** zakaznik najdiMaxVoda |mineralnaVoda| |odkedy| |dokedy|" << endl;
	cout << "** zakaznik najdiMaxDodavatel |dodavatel| |odkedy| |dokedy|" << endl;
}

void PrikazZakaznik::vykonaj()
{
	if (_param[1].empty()) {
		throw runtime_error("~ Prazdny vstup");
	}
	else {
		if (_param[1] == "pridaj" && !(_param[3].empty()) && _param[4].empty())
		{
			System::dajInstanciu().pridanieNovehoZakaznika(_param[2], _param[3]);
		}
		else if (_param[1] == "najdiMaxVoda" && !(_param[4].empty()) && _param[5].empty() )
		{
			System::dajInstanciu().vyhladanieOdberatelaTypuMinVody(_param[2], _param[3], _param[4]);
		}
		else if (_param[1] == "najdiMaxDodavatel" && !(_param[4].empty()) && _param[5].empty() )
		{
			System::dajInstanciu().vyhladanieOdberatelaOdDodavatela(_param[2], _param[3], _param[4]);
		}
		else
		{
			throw runtime_error("~ Neplatny vtup");
		}
	}
}