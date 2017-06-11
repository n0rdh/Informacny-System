#pragma once
#include "Mineralna_voda.h"
#include <iostream>

class Polozka
{
public:
	Polozka(const Mineralna_voda & mineralka, int mnozstvo);
	Polozka(const Polozka& dalsiaPolozka);

	Polozka & operator=(const Polozka& dalsiaPolozka);

	int dajMnozstvo();
	const Mineralna_voda & dajMineralku() const;
	std::string dajVypisPolozky();
	void zvysMnozstvo(int kolko);
	void znizMnozstvo(int kolko);

	~Polozka();

private:
	const Mineralna_voda * mineralka_;
	int mnozstvo_;

};