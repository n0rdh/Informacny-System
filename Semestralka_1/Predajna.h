#pragma once
#include "Zakaznik.h"
#include <iostream>

using namespace std;
class Predajna
{
public:
	Predajna(const std::string & menoZakaznika, const std::string& pAdresa, const  int pZona);
	Predajna(const Predajna& predajnaD); 

	Predajna& operator=(const Predajna& dalsiaPredajna);
	bool operator==(const Predajna& predajnaD) const;
	
	int dajZona() const;
	std::string& dajNazov() const;
	std::string& dajMenoZakaznika() const;
	//Zakaznik & dajZakaznika() const;

	~Predajna();
private:
	int zona_;
	std::string * adresa_; 
	std::string* menoZakaznika_;
	//Zakaznik * zakaznik_;
};
