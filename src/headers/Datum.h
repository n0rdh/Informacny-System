#pragma once
#include <string>
#include <stdexcept>

class Datum {
				
public:
	Datum(int datum);
	Datum(const Datum & dalsiDatum);
	Datum();
	~Datum();
	int celeCislo() const;
	int pocetDniVMesiaci();
	std::string toString() const;
	int aktualnyDatum();
	bool priestupny();
	bool kontrolaDatumu();
private:			
	short den_;
	short mesiac_;
	short rok_;
};

