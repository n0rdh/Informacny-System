#pragma once
#include "Zakaznik.h"
#include <iostream>
#include "IUkladatelny.h"

using namespace std;
class Predajna : IUkladatelny
{
public:
	Predajna(const std::string & menoZakaznika, const std::string& pAdresa, const  int pZona);
	Predajna(const Predajna& predajnaD); 

	Predajna& operator=(const Predajna& dalsiaPredajna);
	friend inline bool operator==(const Predajna& prva, const Predajna& druha);
	
	const int dajZona() const;
	const std::string& dajNazov() const;
	const std::string& dajMenoZakaznika() const;
	std::string dajPrikazNaUlozenie() const override;
	~Predajna();
private:
	int zona_;
	std::string * adresa_; 
	std::string* menoZakaznika_;
};

inline bool operator==(const Predajna& prva, const Predajna& druha)
{
	return ((*prva.adresa_ == *druha.adresa_) && (prva.zona_ == druha.zona_));
}
