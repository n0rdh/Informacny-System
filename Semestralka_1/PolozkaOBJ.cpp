#include "PolozkaOBJ.h"
#include <string>

using namespace std;

Polozka::Polozka(const Mineralna_voda & mineralka, int mnozstvo) :
	mineralka_(&mineralka), mnozstvo_(mnozstvo)
{
}

Polozka::Polozka(const Polozka& dalsiaPolozka) :
	mineralka_(dalsiaPolozka.mineralka_),
	mnozstvo_(dalsiaPolozka.mnozstvo_)
{
}

Polozka & Polozka::operator=(const Polozka& dalsiaPolozka)
{
	if (this != &dalsiaPolozka) {
		mineralka_ = dalsiaPolozka.mineralka_;
		mnozstvo_ = dalsiaPolozka.mnozstvo_;
	}
	return *this;
}

int Polozka::dajMnozstvo()
{
	return mnozstvo_;
}

const Mineralna_voda & Polozka::dajMineralku() const
{
	return *mineralka_;
}

void Polozka::zvysMnozstvo(int kolko)
{
	mnozstvo_ += kolko;
}

void Polozka::znizMnozstvo(int kolko)
{
	mnozstvo_ -= kolko;
}

string Polozka::dajVypisPolozky()
{
	string pom;
	pom.append(mineralka_->dajNazov());
	pom.append(" - ");
	pom.append(to_string(mnozstvo_));
	return pom;
}

Polozka::~Polozka()
{

	cout << "###################################################  Destruktor Polozka		###" << endl;
}