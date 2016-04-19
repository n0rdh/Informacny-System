#include "Predajna.h"
using namespace std;

Predajna::Predajna(const string & menoZakaznika, const string& adresa, const int zona) :
	menoZakaznika_(new string(menoZakaznika)),
	adresa_(new string(adresa)),
	zona_(zona)
{
}

Predajna::Predajna(const Predajna & dalsiaPredajna) :
	menoZakaznika_(new string(*dalsiaPredajna.menoZakaznika_)),
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

string& Predajna::dajMenoZakaznika() const
{
	return *menoZakaznika_;
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
