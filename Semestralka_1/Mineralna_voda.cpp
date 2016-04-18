#include "Mineralna_voda.h"	 
using namespace std;

Mineralna_voda::Mineralna_voda(const string& nazov, const string& ean, Dodavatel& dodavatel) :
	ean_(new string(ean)),
	nazov_(new string(nazov)),
	dodavatel_(&dodavatel) 
{
}

Mineralna_voda::Mineralna_voda(const Mineralna_voda & paDalsia) :
	nazov_(new string(*paDalsia.nazov_)),
	dodavatel_(paDalsia.dodavatel_),
	ean_(new string(*paDalsia.ean_))
{
}

Mineralna_voda & Mineralna_voda::operator=(const Mineralna_voda & dalsiaMineralka)
{
	if (this != &dalsiaMineralka) {
		delete nazov_;
		delete ean_;
		nazov_ = new string(*dalsiaMineralka.nazov_);
		ean_ = new string(*dalsiaMineralka.ean_);
		dodavatel_ = dalsiaMineralka.dodavatel_;
	}
	return *this;
}

string & Mineralna_voda::dajNazov() const
{
	return *nazov_;
}

string & Mineralna_voda::dajNazovDodavatela() const
{
	return dodavatel_->dajNazov();
}

string & Mineralna_voda::dajEAN() const
{
	return *ean_;
}

Dodavatel * Mineralna_voda::dajDodavatela() const
{
	return dodavatel_;
}

Mineralna_voda::~Mineralna_voda()
{

	cout << "###################################################  Destruktor Minreralky     ###" << endl;
	delete nazov_;
	delete ean_;
}