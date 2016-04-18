#include "Predajna.h"
using namespace std;

Predajna::Predajna(Zakaznik * zakaznik, const string& adresa,const int zona) :
	zakaznik_(zakaznik), adresa_(new string(adresa)), zona_(zona)
{
}

Predajna::Predajna(const Predajna & dalsiaPredajna) :
	adresa_(new string(*dalsiaPredajna.adresa_)),
	zona_(dalsiaPredajna.zona_)
{
}

Predajna & Predajna::operator=(const Predajna & dalsiaPredajna)
{
	if (this != &dalsiaPredajna) {
		delete adresa_;
		adresa_ = new string(*dalsiaPredajna.adresa_);
		zona_ = dalsiaPredajna.zona_;
	}
	return *this;
}

bool Predajna::operator==(const Predajna& dalsiaPredajna) const
{
	if (*adresa_ != *dalsiaPredajna.adresa_ || zona_ != dalsiaPredajna.zona_) {
		return false;
	}
	else
	{
		return true;
	}
}

string& Predajna::dajNazov() const
{
	return *adresa_;
}

Zakaznik * Predajna::dajZakaznika() const
{
	return zakaznik_;
}

int Predajna::dajZona() const
{
	return zona_;
}

Predajna::~Predajna()
{

	cout << "###################################################  Destruktor Predajna   ###" << endl;
	delete adresa_;
}
