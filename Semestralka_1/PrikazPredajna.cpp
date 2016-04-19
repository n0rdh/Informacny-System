#include "PrikazPredajna.h"

PrikazPredajna::PrikazPredajna(string param[])
{
	for (int i = 0; i < 10; i++)
		_param[i] = param[i];
}

PrikazPredajna::~PrikazPredajna()
{
}

void PrikazPredajna::pomoc()
{
	cout << "** predajna pridaj |menoZakaznika| |adresa| |zona|" << endl;
}

void PrikazPredajna::vykonaj()
{
	if (_param[1].empty()) {
		throw runtime_error("~ Prazdny vstup");
	}
	else {
		if (_param[1] == "pridaj" && !(_param[4].empty()) && _param[5].empty())
		{
			System::dajInstanciu().pridanieNovejPredajne(_param[2], _param[3], _param[4]);
		}
		else {
			throw runtime_error("~ Neplatny prikaz");
		}
	}
}
