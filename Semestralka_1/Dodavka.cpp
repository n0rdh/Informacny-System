#include "Dodavka.h"

using namespace std;

Dodavka::Dodavka(const Mineralna_voda& mineralka, unsigned int mnozstvo, int datum) :
	mineralka_(mineralka),
	datumPlnenia_(datum),
	mnozstvo_(mnozstvo)
{
}

Dodavka::Dodavka(const Dodavka & dalsiaDodavka) :
	mineralka_(dalsiaDodavka.mineralka_),
	datumPlnenia_(dalsiaDodavka.datumPlnenia_),
	mnozstvo_(dalsiaDodavka.mnozstvo_)
{
}

Dodavka::~Dodavka()
{
}

Dodavka & Dodavka::operator=(const Dodavka & dalsiaDodavka)
{
	if (this != &dalsiaDodavka) {
		mineralka_ = dalsiaDodavka.mineralka_;
		mnozstvo_ = dalsiaDodavka.mnozstvo_;
		datumPlnenia_ = dalsiaDodavka.datumPlnenia_;
	}
	return *this;
}

string Dodavka::toString() const
{
	string pom = "";
	pom.append(mineralka_.dajNazov());
	pom.append(" - ");
	pom.append(to_string(mnozstvo_));
	pom.append(" - ");
	pom.append(to_string(datumPlnenia_));
	return pom;
}

const Mineralna_voda & Dodavka::dajMinetralku()
{
	return mineralka_;
}

int Dodavka::dajDatumPlnenia() const
{
	return datumPlnenia_;
}

int Dodavka::dajMnozstvo() const
{
	return mnozstvo_;
}				

void Dodavka::znizMnozstvo(int kolko)
{
	mnozstvo_ -= kolko;
}

