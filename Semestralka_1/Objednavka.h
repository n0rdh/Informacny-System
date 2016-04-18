#pragma once
#include <utility>
#include "Predajna.h"
#include "Datum.h"
#include "ArrayList.h"
#include "Mineralna_voda.h"
#include "PolozkaOBJ.h"
#include <string>

enum StavObjednavky
{
	soCAKAJUCA, soNEPLATNA, soVYEXPEDOVANA
};

class Objednavka
{
public:
	Objednavka(const Predajna & predajna, int datum);
	Objednavka(const Objednavka & objednaka);

	Objednavka & operator=(const Objednavka & objednavka);

	const Predajna & dajPredajnu() const;
	std::string dajStavObjednavky() const;
	int dajDatumDorucenia() const;
	std::string vypisObjednavku() const;	
	void pridajPolozku(Mineralna_voda& typVody, int mnozstvo);
	DS::ArrayList<Polozka*>* dajPolozky();

	bool jeNeplatna() const;
	bool jeCakajuca() const;
	bool jeVyexpedovana() const;
	bool oznacNeplatnu();
	bool oznacVyexpedovanu();
	bool oznacOdoslanu();

	~Objednavka();

private:

	DS::ArrayList<Polozka*>* polozky_;
	const Predajna * predajna_;
	StavObjednavky stavObjednavky_;
	Datum* datum_;
	bool odoslanie_;
};