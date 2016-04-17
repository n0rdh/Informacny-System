#pragma once
#include <iostream>

class Dodavatel 
{
public: 
	Dodavatel(const std::string& nazov, const std::string& adresa);
	Dodavatel(const Dodavatel& dodavatel);

	Dodavatel& operator=(const Dodavatel& dalsi);

	std::string & dajNazov() const;
	std::string & dajAdresu() const;

	~Dodavatel();

private:												
	std::string* nazov_;
	std::string* adresa_;
};