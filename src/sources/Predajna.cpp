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

const string& Predajna::dajNazov() const
{
	return *adresa_;
}

const string& Predajna::dajMenoZakaznika() const
{
	return *menoZakaznika_;
}

const int Predajna::dajZona() const
{
	return zona_;
}

Predajna::~Predajna()
{
	delete adresa_;
}

string Predajna::dajPrikazNaUlozenie() const
{
	return "predajna pridaj " + *menoZakaznika_
		+ " " + *adresa_ + " " + to_string(zona_);
}
