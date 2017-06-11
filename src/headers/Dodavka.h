#pragma once
#include "Mineralna_voda.h"
#include "Datum.h"
#include "Uloz.h"

class Dodavka : Uloz
{	  
public:
	Dodavka(const Mineralna_voda& mineralka, unsigned int mnozstvo, int datum);
	Dodavka(const Dodavka& dodavkaD);

	Dodavka& operator=(const Dodavka& dodavkaD);
	int dajDatumPlnenia() const; 
	int dajMnozstvo() const;
	void znizMnozstvo(int kolko);
	const Mineralna_voda * dajMinetralku();
	std::string toString() const;
	std::string dajPrikazNaUlozenie() const override;

	~Dodavka();

private:
	const Mineralna_voda * mineralka_;
	unsigned int mnozstvo_;
	int datumPlnenia_;

};