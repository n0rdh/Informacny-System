#include "PrikazProgram.h"
#include <iostream>
#include <fstream>
#include "Parser.h"
#include "IPrikaz.h"
#include "System.h"

PrikazProgram::PrikazProgram(string param[])
{
	for (int i = 0; i < 10; i++)
		_param[i] = param[i];
}


PrikazProgram::~PrikazProgram()
{
}

void PrikazProgram::pomoc()
{
	cout << "** program nacitaj" << endl;
	cout << "** program uloz" << endl;
}

void PrikazProgram::vykonaj()
{
	if (_param[1].empty()) {
		throw runtime_error("~ Prazdny vstup");
	}
	else {
		if (_param[1] == "uloz"  && _param[2].empty())
		{
			ulozDoSuboru();
		}
		else if (_param[1] == "nacitaj"  && _param[2].empty())
		{
			nacitajZoSuboru();
		}
		else {
			throw runtime_error("~ Neplatny prikaz");
		}
	}
}

void PrikazProgram::nacitajZoSuboru()
{
	ifstream subor;
	subor.open("testovanie.txt");
	Parser parser(&subor);

	while (true)
	{
		IPrikaz* prikaz = parser.nacitajPrikaz();
		if (prikaz == nullptr)
		{
			cout << "$ HOTOVO, nacitane" << endl;
			break;
		}
		try
		{
			prikaz->vykonaj();
		}
		catch (const std::exception& e)
		{
			cerr << "~ Chyba pri vykonani prikazu: " << e.what() << endl;
			delete prikaz;
			break;
		}
		delete prikaz;
	}
	subor.close();
}

void PrikazProgram::ulozDoSuboru()
{
	ofstream subor;
	subor.open("ulozenie.txt");

	System::dajInstanciu().ulozitDoSuboru(subor);

	subor.close();
}
 