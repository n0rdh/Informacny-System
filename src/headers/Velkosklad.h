#pragma once
#include <iostream>
#include "Zakaznik.h"
#include "Polozka.h"
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
	void vyhladanieOdberatelaVody(const std::string & voda, int odkedy, int dokedy);
	void vyhladanieOdberatelaOdDodavatela(const std::string & dodvatel, int odkedy, int dokedy);
	void odovzdajZakanikovy();
	void vypisNeplatneObjednavky();		
	void vypisVsetkyObjednavky();
	void vypisSklad();
	void kontrolaPoziadaviek();
	void ulozDoSuboru(std::ostream& subor);

	~Velkosklad();

private:
	DS::ArrayList<Polozka*>* sklad_;
	DS::Stack<Objednavka*>* autoPrevoz_;
	DS::LinkedList<Dodavka*>* dodavky_;
	DS::ArrayList<Objednavka*>* objednavky_;

	void vyprazdnitAuto();
	void zoradDodavky();
	void zaskladni();
	void zoradPole(DS::ArrayList<std::string>& pole);
	template <typename T>
	void vymazZoZoznamu(DS::ArrayList<T>& zoznam);
	void triedeniePoloziek(DS::ArrayList<Polozka*>& polozky);
	void pripravVyskladnenieUpravDodavky(Objednavka * objednavka);
	bool skontrolujMnozstvoVsklade(Objednavka * objednavka);
};