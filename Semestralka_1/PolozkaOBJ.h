#pragma once
#include "Mineralna_voda.h"
#include <iostream>

class PolozkaOBJ
{
public:
	PolozkaOBJ(const Mineralna_voda & mineralka, int mnozstvo);
	PolozkaOBJ(const PolozkaOBJ& dalsiaPolozka);

	PolozkaOBJ & operator=(const PolozkaOBJ& dalsiaPolozka);

	int dajMnozstvo();
	const Mineralna_voda & dajMineralku() const;
	std::string dajVypisPolozky();
	void zvysMnozstvo(int kolko);
	void znizMnozstvo(int kolko);

	~PolozkaOBJ();

private:
	const Mineralna_voda * mineralka_;
	int mnozstvo_;

};