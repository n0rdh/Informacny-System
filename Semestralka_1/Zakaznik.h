#pragma once
#include "Predajna.h"
#include <vector>

class Zakaznik
{
public:
	Zakaznik(const std::string& nazov,const std::string& adresa);
	Zakaznik(const Zakaznik& zakaznikD);
	
	Zakaznik& operator=(const Zakaznik& zakaznikD);
	bool operator==(const Zakaznik& zakaznikD) const;

	std::string& dajNazov() const;
	std::string& dajAdresu() const;

	~Zakaznik();
private:
	std::string* nazov_;
	std::string* adresa_;

};
