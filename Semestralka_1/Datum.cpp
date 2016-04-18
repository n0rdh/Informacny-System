#include "Datum.h"
#include <ctime>
#include <iostream>

using namespace std;

Datum::Datum(int datum)
{
	int rok = datum;      // 20201230
	den_ = datum % 100;	 //	 30
	rok /= 100;		 //	 202012
	mesiac_ = rok % 100; //	 12
	rok /= 100;	 //	 2020
	rok_ = rok;
	
}

Datum::Datum(const Datum &dalsiDatum) {
	den_ = dalsiDatum.den_;
	mesiac_ = dalsiDatum.mesiac_;
	rok_ = dalsiDatum.rok_;
}

Datum::Datum() {
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	den_ = timePtr->tm_mday;
	mesiac_ = timePtr->tm_mon;
	rok_ = 1900 + timePtr->tm_year;
}

Datum::~Datum()
{
	cout << "##############################################  Destruktor Datumu    ###" << endl;
}


int Datum::aktualnyDatum()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	return (timePtr->tm_year + 1900) * 10000 + (timePtr->tm_mon + 1) * 100 + (timePtr->tm_mday);
}

string Datum::toString() const
{
	return to_string(den_) + "." + to_string(mesiac_) + "." + to_string(rok_);
}

bool Datum::priestupny()
{
	return 	(rok_ % 4 == 0 && rok_ % 100 == 0 || rok_ % 400 == 0);
}

int Datum::pocetDniVMesiaci()
{
	switch (mesiac_)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return priestupny() ? 29 : 28;
		default:
			return 0;
	}
}

bool Datum::kontrolaDatumu()
{
	return (den_ >= 1 && den_ <= pocetDniVMesiaci() && mesiac_ >= 1 && mesiac_ < 13);
}

int Datum::celeCislo() const
{
	return rok_ * 10000 + mesiac_ * 100 + den_;
}
