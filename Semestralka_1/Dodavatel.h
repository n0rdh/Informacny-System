#pragma once
#include <iostream>
#include "IUkladatelny.h"

class Dodavatel : public IUkladatelny
{
public: 
	Dodavatel(const std::string& nazov, const std::string& adresa);
	Dodavatel(const Dodavatel& dodavatel);

	Dodavatel& operator=(const Dodavatel& dalsi);
	friend bool operator==(const Dodavatel& dalsi1, const Dodavatel& dalsi2);

	const std::string & dajNazov() const;
	const std::string & dajAdresu() const;
	std::string dajPrikazNaUlozenie() const override;
	~Dodavatel();

private:												
	std::string* nazov_;
	std::string* adresa_;
};

inline bool operator==(const Dodavatel& dalsi1, const Dodavatel& dalsi2)
{
	return *dalsi1.nazov_ == *dalsi2.nazov_;
}