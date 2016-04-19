#include "PrikazObjednavka.h"
#include <iostream>


PrikazObjednavka::PrikazObjednavka(string param[])
{
	for (int i = 0; i < 10; i++)
		parameter[i] = param[i];
}


PrikazObjednavka::~PrikazObjednavka()
{
}

void PrikazObjednavka::pomoc()
{
	cout << "** objednavka pridaj |zakaznik| |predajna| |zona| |datumDorucenia| |polozky...|" << endl;
	cout << "** objednavka vypis neplatne" << endl;
}

void PrikazObjednavka::vykonaj()
{
	if (parameter[2].empty()) {
		throw runtime_error("~ Pradny vstup");
	}
	else if (parameter[1] == "pridaj" && parameter[7].empty() ) {
		System::dajInstanciu().zaevidovanieObjednavky(parameter[2], parameter[3],
			parameter[4], parameter[5], parameter[6]);
	}
	else if (parameter[1] == "vypis" && parameter[2] == "neplatne"  && parameter[3].empty()) {
		System::dajInstanciu().vypisanieVsetkychPoziadaviekNeplat();
	}
	else {
		throw runtime_error("~ Neplatny vstup");
	}
}
