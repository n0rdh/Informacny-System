#pragma once
#include <iostream>
#include "PolozkaOBJ.h"
#include "LinkedList.h"
#include "Stack.h"
#include "ArrayList.h"
#include "Objednavka.h"
#include "Dodavka.h"

class Velkosklad
{
public:
	Velkosklad();
	Velkosklad(const Velkosklad& skladD);
																	
	bool zaevidujObjednavku(Objednavka * pObjednavka);
	bool zaevidujDodavku(Dodavka * pDodavka);

	void vyskladnenie(int datum);
	void vyhladanieDodavatela(int odkedy, int dokedy);
	void odovzdajZakanikovy();
	void vypisNeplatneObjednavky();		
	void vypisVsetkyObjednavky();
	void vypisSklad();
	void vypisVsetkyDodavky();
	void kontrolaPoziadaviek();
	void zoradDodavkyDodavky();
	
	void vyprazdnitAuto();
	void zoradPole(DS::ArrayList<std::string>& pole);
	template <typename T>
	void vymazZoZoznamu(DS::ArrayList<T>& zoznam);


	~Velkosklad();

private:
	DS::ArrayList<PolozkaOBJ*>* sklad_;
	DS::Stack<Objednavka*>* autoPrevoz_;
	DS::ArrayList<Dodavka*>* dodavky_;
	DS::ArrayList<Objednavka*>* objednavky_;
};