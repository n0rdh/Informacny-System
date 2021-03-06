#include "Objednavka.h"
using namespace std;
using namespace DS;

Objednavka::Objednavka(const Predajna & predajna, int datum) :
	predajna_(&predajna),
	datum_(new Datum(datum)),
	polozky_(new ArrayList<Polozka*>())
{
	stavObjednavky_ = soCAKAJUCA;
}

Objednavka::Objednavka(const Objednavka & objednakaD) :
	predajna_(objednakaD.predajna_),
	datum_(new Datum(*objednakaD.datum_)),
	polozky_(new ArrayList<Polozka*>(*objednakaD.polozky_))
{
}

Objednavka & Objednavka::operator=(const Objednavka & objednakaD)
{
	if (this != &objednakaD) {
		predajna_ = objednakaD.predajna_;
		stavObjednavky_ = objednakaD.stavObjednavky_;
		*polozky_ = *objednakaD.polozky_;
	}
	return *this;
}

const Predajna & Objednavka::dajPredajnu() const
{
	return *predajna_;
}

string Objednavka::dajStavObjednavky() const
{
	if (stavObjednavky_ == soCAKAJUCA)
	{
		return "CAKAJUCA";
	}
	else if (stavObjednavky_ == soNEPLATNA)
	{
		return "NEPLATNA";
	}
	else if (stavObjednavky_ == soVYEXPEDOVANA)
	{
		return "VYEXPEDOVANA";
	}
	else if (stavObjednavky_ == soODOSLANA)
	{
		return "ODOSLANA";
	}
}

int Objednavka::dajDatumDorucenia() const
{
	return datum_->celeCislo();
}

string Objednavka::vypisObjednavku() const
{
	string str;
	int i = 0;
		i++;  
		str.append("	 - ");
		str.append(datum_->toString());
		str.append(" - ");
		str.append(dajStavObjednavky());
		str.append(" \n ");
		for (auto polozka : *polozky_)
		{
			str.append("	      - ");
			str.append(polozka->dajMineralku().dajNazov());
			str.append(" - ");
			str.append(to_string(polozka->dajMnozstvo()));
			str.append(" \n ");
		}
		if (i > 1) { str.append("\n"); }
	return str;
}		

void Objednavka::pridajPolozku(Mineralna_voda & typVody, int mnozstvo)
{
	polozky_->add(new Polozka(typVody,mnozstvo));
}

const ArrayList<Polozka*>* Objednavka::dajPolozky()
{
	return polozky_;
}

bool Objednavka::jeNeplatna() const
{
	if (stavObjednavky_ == soNEPLATNA) {
		return true;
	}
	else {
		return false;
	}
}

bool Objednavka::jeCakajuca() const
{
	if (stavObjednavky_ == soCAKAJUCA) {
		return true;
	}
	else {
		return false;
	}
}

bool Objednavka::jeOdoslana() const
{
	if (stavObjednavky_ == soODOSLANA) {
		return true;
	}
	else {
		return false;
	}
}

bool Objednavka::jeVyexpedovana() const
{
	if (stavObjednavky_ == soVYEXPEDOVANA) {
		return true;
	}
	else {
		return false;
	}
}


bool Objednavka::oznacNeplatnu()
{
	if (stavObjednavky_ == soCAKAJUCA) {
		stavObjednavky_ = soNEPLATNA;
		return true;
	}
	else
	{
		return false;
	}
}

bool Objednavka::oznacOdoslana()
{
	if (stavObjednavky_ == soVYEXPEDOVANA) {
		stavObjednavky_ = soODOSLANA;
		return true;
	}
	else
	{
		return false;
	}
}

bool Objednavka::oznacVyexpedovanu()
{
	if (stavObjednavky_ == soCAKAJUCA) {
		stavObjednavky_ = soVYEXPEDOVANA;
		return true;
	}
	else
	{
		return false;
	}
}

Objednavka::~Objednavka()
{
	for (auto polozka : *polozky_)
	{
		delete polozka;
	}
	delete polozky_;
}
string Objednavka::dajPrikazNaUlozenie() const
{
	string str = "objednavka pridaj " + predajna_->dajMenoZakaznika() + " "
		+ predajna_->dajNazov() + " " + to_string(predajna_->dajZona()) + " " +
		to_string(datum_->celeCislo()) + "\n";
	for (int i = 0; i < static_cast<int>(polozky_->size()); i++)
	{
		string koniec = " \n";
		if (i == (polozky_->size() - 1))
		{
			koniec = ";";
		}
		str += (*polozky_)[i]->dajMineralku().dajEAN() + " " +
			to_string((*polozky_)[i]->dajMnozstvo()) + koniec;
	}
	return str;
}