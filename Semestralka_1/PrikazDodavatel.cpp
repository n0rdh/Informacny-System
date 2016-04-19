#include "PrikazDodavatel.h"


PrikazDodavatel::PrikazDodavatel(string param[])
{
	for (int i = 0; i < 10; i++)
		_param[i] = param[i];
}

PrikazDodavatel::~PrikazDodavatel()
{
}

void PrikazDodavatel::pomoc()
{
	cout << "** dodavatel pridaj |meno| |adresa|" << endl;
	cout << "** dodavatel najdiMax |odkedy| |dokedy|" << endl;
}

void PrikazDodavatel::vykonaj()
{
	if (_param[1].empty()) {
		throw runtime_error("~ Prazdny vstup");
	}
	else {
		if (_param[1] == "pridaj" && !(_param[3].empty()) && _param[4].empty())
		{
			System::dajInstanciu().pridanieNovehoDodavatela(_param[2], _param[3]);
		}
		else if (_param[1] == "najdimax" && !(_param[3].empty()) && _param[4].empty())
		{
			System::dajInstanciu().vyhladanieDodavatela(_param[2], _param[3]);
		}
		else {
			throw runtime_error("~ Neplatny vstup");
		}
	}
}
