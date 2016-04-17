#include "PolozkaOBJ.h"
#include <string>

using namespace std;

PolozkaOBJ::PolozkaOBJ(const Mineralna_voda & mineralka, int mnozstvo) :
	mineralka_(&mineralka), mnozstvo_(mnozstvo)
{
}

PolozkaOBJ::PolozkaOBJ(const PolozkaOBJ& dalsiaPolozka) :
	mineralka_(dalsiaPolozka.mineralka_),
	mnozstvo_(dalsiaPolozka.mnozstvo_)
{
}

PolozkaOBJ & PolozkaOBJ::operator=(const PolozkaOBJ& dalsiaPolozka)
{
	if (this != &dalsiaPolozka) {
		mineralka_ = dalsiaPolozka.mineralka_;
		mnozstvo_ = dalsiaPolozka.mnozstvo_;
	}
	return *this;
}

int PolozkaOBJ::dajMnozstvo()
{
	return mnozstvo_;
}

const Mineralna_voda & PolozkaOBJ::dajMineralku() const
{
	return *mineralka_;
}

void PolozkaOBJ::zvysMnozstvo(int kolko)
{
	mnozstvo_ += kolko;
}

void PolozkaOBJ::znizMnozstvo(int kolko)
{
	mnozstvo_ -= kolko;
}

string PolozkaOBJ::dajVypisPolozky()
{
	string pom;
	pom.append(mineralka_->dajNazov());
	pom.append(" - ");
	pom.append(to_string(mnozstvo_));
	return pom;
}

PolozkaOBJ::~PolozkaOBJ()
{
}