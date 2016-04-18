#pragma once
#include "Zakaznik.h"
#include <iostream>

class Predajna
{
public:
	Predajna(Zakaznik * zakaznik, const std::string& pAdresa, const  int pZona);
	Predajna(const Predajna& predajnaD);

	Predajna& operator=(const Predajna& dalsiaPredajna);
	bool operator==(const Predajna& predajnaD) const;
	
	int dajZona() const;
	std::string& dajNazov() const;
	Zakaznik * dajZakaznika() const;

	~Predajna();
private:
	;
	int zona_;
	std::string * adresa_; 
	Zakaznik * zakaznik_;
};
