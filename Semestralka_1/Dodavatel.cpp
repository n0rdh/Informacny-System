#include "Dodavatel.h"
using namespace std;

Dodavatel::Dodavatel(const string& obch_nazov, const  string& adresa) :
	nazov_(new string(obch_nazov)), adresa_(new string(adresa))
{
}

Dodavatel::Dodavatel(const Dodavatel & dalsiDodavatel)
{
	nazov_ = new string(*dalsiDodavatel.nazov_);
	adresa_ = new string(*dalsiDodavatel.adresa_);
}

Dodavatel::~Dodavatel()
{
	delete nazov_;
	delete adresa_;
}

Dodavatel & Dodavatel::operator=(const Dodavatel & dalsiDodavatel)
{
	if (this != &dalsiDodavatel) {
		delete nazov_;
		delete adresa_;
		nazov_ = new string(*dalsiDodavatel.nazov_);
		adresa_ = new string(*dalsiDodavatel.adresa_);
	}
	return *this;
}

string & Dodavatel::dajNazov() const
{
	return *nazov_;
}

string & Dodavatel::dajAdresu() const
{
	return *adresa_;
}