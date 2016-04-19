#include "NazvyPrikazov.h"

#include "PrikazPomoc.h"
#include "PrikazZakaznik.h"
#include "PrikazObjednavka.h"
#include "PrikazProgram.h"
#include "PrikazSklad.h"
#include "PrikazDodavka.h"
#include "PrikazPredajna.h"
#include "PrikazDodavatel.h"
#include "PrikazUkonci.h"
#include "PrikazMineralnaVoda.h"
#include "PrikazPrazdny.h"

IPrikaz * NazvyPrikazov::dajPrikazBezParametrov(string nazov)
{
	string parametre[6];

	if (nazov == "pomoc")
	{
		return new PrikazPomoc(parametre);
	}
	else if (nazov == "__prazdny__")
	{
		return new PrikazPrazdny();
	}
	else if (nazov == "zakaznik")
	{
		return new PrikazZakaznik(parametre);
	}
	else if (nazov == "objednavka")
	{
		return new PrikazObjednavka(parametre);
	}
	else if (nazov == "program")
	{
		return new PrikazProgram(parametre);
	}
	else if (nazov == "sklad")
	{
		return new PrikazSklad(parametre);
	}
	else if (nazov == "dodavka")
	{
		return new PrikazDodavka(parametre);
	}
	else if (nazov == "predajna")
	{
		return new PrikazPredajna(parametre);
	}
	else if (nazov == "dodavatel")
	{
		return new PrikazDodavatel(parametre);
	}
	else if (nazov == "ukonci")
	{
		return new PrikazUkonci();
	}
	else if (nazov == "mineralnavoda")
	{
		return new PrikazMineralnaVoda(parametre);
	}
	else {
		throw runtime_error("~ Neplatny prikaz");
	}

	return nullptr;
}

IPrikaz * NazvyPrikazov::dajPrikaz(string parametre[])
{
	string nazov = parametre[0];

	if (nazov == "pomoc")
	{
		return new PrikazPomoc(parametre);
	}
	else if (nazov == "zakaznik")
	{
		return new PrikazZakaznik(parametre);
	}
	else if (nazov == "objednavka")
	{
		return new PrikazObjednavka(parametre);
	}
	else if (nazov == "program")
	{
		return new PrikazProgram(parametre);
	}
	else if (nazov == "sklad")
	{
		return new PrikazSklad(parametre);
	}
	else if (nazov == "dodavka")
	{
		return new PrikazDodavka(parametre);
	}
	else if (nazov == "predajna")
	{
		return new PrikazPredajna(parametre);
	}
	else if (nazov == "dodavatel")
	{
		return new PrikazDodavatel(parametre);
	}
	else if (nazov == "ukonci")
	{
		return new PrikazUkonci();
	}
	else if (nazov == "mineralnavoda")
	{
		return new PrikazMineralnaVoda(parametre);
	}
	else {
		throw runtime_error("~ Neplatny prikaz");
	}
	
	return nullptr;
}

void NazvyPrikazov::vypisVsetkyPrikazy()
{
	cout << "** Zoznam prikazov:" << endl;
	cout << "" << endl;

	string nazvy[] = { "dodavatel", "dodavka", "mineralnavoda",
		"objednavka", "pomoc", "predajna", "program", "sklad", "ukonci", "zakaznik" };

	for (int i = 0; i < 10; i++)
	{
		string parametre[10];
		parametre[0] = nazvy[i];
		IPrikaz* prikaz = dajPrikaz(parametre);
		prikaz->pomoc();
		cout << endl;
		delete prikaz;
	}
}
