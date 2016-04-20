#include "PrikazMineralnaVoda.h"


PrikazMineralnaVoda::PrikazMineralnaVoda(string param[])
{
	for (int i = 0; i < 10; i++)
		_param[i] = param[i];
}

PrikazMineralnaVoda::~PrikazMineralnaVoda()
{
}

void PrikazMineralnaVoda::pomoc()
{
	cout << "** mineralnaVoda pridaj |nazov| |ean| |dodavatel|" << endl;
}

void PrikazMineralnaVoda::vykonaj()
{
	if (_param[1].empty()) {
		throw runtime_error("~ Prazdny vstup");
	}
	else {
		if (_param[1] == "pridaj" && !(_param[4].empty()) && _param[5].empty())
		{
			System::dajInstanciu().pridanieNovehoTypuMVody(_param[2], _param[3], _param[4]);
		}
		else {
			throw runtime_error("~ Neplatny vstup");
		}
	}
}