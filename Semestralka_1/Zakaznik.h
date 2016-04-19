#pragma once
#include "Predajna.h"
#include <iostream>
#include "IUkladatelny.h"

class Zakaznik : public IUkladatelny
{
public:
	Zakaznik(const std::string& nazov,const std::string& adresa);
	Zakaznik(const Zakaznik& zakaznikD);
	
	Zakaznik& operator=(const Zakaznik& zakaznikD);
	friend inline bool operator==(const Zakaznik& prvy, const Zakaznik& druhy);

	const std::string& dajNazov() const;
	const std::string& dajAdresu() const;

	std::string dajPrikazNaUlozenie() const override;

	~Zakaznik();
private:
	std::string* nazov_;
	std::string* adresa_;
};

inline bool operator==(const Zakaznik& prvy, const Zakaznik& druhy)
{
	return *prvy.nazov_ == *druhy.nazov_;
}
