#include "Objednavka.h"
using namespace std;
using namespace DS;

Objednavka::Objednavka(const Predajna & predajna, int datum) :
	predajna_(&predajna),
	datum_(new Datum(datum)),
	polozky_(new ArrayList<Polozka*>())
{
	odoslanie_ = false;
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
		odoslanie_ = objednakaD.odoslanie_;
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
}

int Objednavka::dajDatumDorucenia() const
{
	return datum_->celeCislo();
}

string Objednavka::vypisObjednavku() const
{
	string str;
	int i = 0;
	for (auto &polozka : *polozky_)
	{
		i++;  
		str.append(" - ");
		str.append(polozka->dajMineralku().dajNazov());
		str.append(" - ");
		str.append(to_string(polozka->dajMnozstvo()));
		str.append(" - ");
		str.append(datum_->toString());
		if (i > 1) { str.append("\n"); }
	}
	return str;
}		

void Objednavka::pridajPolozku(Mineralna_voda & typVody, int mnozstvo)
{
	polozky_->add(new Polozka(typVody,mnozstvo));
}

ArrayList<Polozka*>* Objednavka::dajPolozky()
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
	if (stavObjednavky_ == soCAKAJUCA && odoslanie_ != true) {
		stavObjednavky_ = soNEPLATNA;
		return true;
	}
	else
	{
		return false;
	}
}

bool Objednavka::oznacVyexpedovanu()
{
	if (stavObjednavky_ == soCAKAJUCA && odoslanie_ == true) {
		stavObjednavky_ = soVYEXPEDOVANA;
		return true;
	}
	else
	{
		return false;
	}
}

bool Objednavka::oznacOdoslanu()
{
	if (stavObjednavky_ == soCAKAJUCA && odoslanie_ == false) {
		odoslanie_ = true;
		return true;
	}
	else
	{
		return false;
	}
}

Objednavka::~Objednavka()
{

	cout << "###################################################  Destruktor Objednavka    ###" << endl;
	for (auto polozka : *polozky_)
	{
		delete &polozka;
	}
	delete polozky_;
}