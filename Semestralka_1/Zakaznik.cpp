#include "Zakaznik.h"
using namespace std;

Zakaznik::Zakaznik(const string& nazov,const string& adresa) :
	nazov_(new string(nazov)), adresa_(new string(adresa))
{
}

Zakaznik::Zakaznik(const Zakaznik & zakaznikD) :
	nazov_(new string(*zakaznikD.nazov_)),
	adresa_(new string(*zakaznikD.adresa_))	
{
}

Zakaznik & Zakaznik::operator=(const Zakaznik & zakaznikD)
{
	if (this != &zakaznikD) {
		delete nazov_;
		delete adresa_;
		nazov_ = new string(*zakaznikD.nazov_);
		adresa_ = new string(*zakaznikD.adresa_);
	}
	return *this;
}

bool Zakaznik::operator==(const Zakaznik & zakaznikD) const
{
	return false;
}

string& Zakaznik::dajNazov() const
{
	return *nazov_;
}

string& Zakaznik::dajAdresu() const
{
	return *adresa_;
}

Zakaznik::~Zakaznik()
{
	delete nazov_;
	delete adresa_;
}
