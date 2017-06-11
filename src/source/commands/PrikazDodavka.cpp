#include "PrikazDodavka.h"
#include <iostream>

PrikazDodavka::PrikazDodavka(string param[])
{
	for (int i = 0; i < 10; i++)
		_param[i] = param[i];
}


PrikazDodavka::~PrikazDodavka()
{
}

void PrikazDodavka::pomoc()
{
	cout << "** dodavka pridaj |typMineralnejVody| |mnozstvo| |datumPlnenia|" << endl;
}

void PrikazDodavka::vykonaj()
{
	if (_param[3].empty()) {
		throw runtime_error("~ Prazdny vstup");
	}
	else if (_param[1] == "pridaj" && !(_param[4].empty()) && _param[5].empty()) {
		System::dajInstanciu().zaevidovanieNovejDodavky(_param[2], _param[3], _param[4]); 
	}
	else {
		throw runtime_error("~ Nplatny vstup");
	}
}
