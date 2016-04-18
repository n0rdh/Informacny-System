#pragma once
#include "PolozkaOBJ.h"
#include "Zakaznik.h"
#include "Predajna.h"
#include "Mineralna_voda.h"
#include "Dodavatel.h"
#include "Datum.h"
#include "Velkosklad.h"
#include "ArrayList.h"
#include <string>

class System
{
public:
	System();
	System& getInstancia();
	
	bool pridanieNovehoTypuMVody(const std::string& nazov,
								 const  std::string& kodEAN,
								 const std::string& nazovDodavatela);
	bool pridanieNovehoDodavatela(const std::string& nazov,
								  const std::string& adresa);
	bool pridanieNovehoZakaznika(const std::string& meno,
								 const std::string& adresa);
	bool pridanieNovejPredajne(const std::string& menoZakaznika,	  
							   const std::string& adresa, const int zona);
	bool zaevidovanieObjednavky(const std::string& adresaPredajna,
								int datumDorucenia,
								const std::string& nazovMV,
								unsigned int mnozstvo);
	bool zaevidovanieNovejDodavky(const std::string& nazovMV,
								 unsigned int mnozstvo, int datumPlnenia);
	void kontrolaPoziadaviekZ();
	void odovzdanieZakaznikovi(); 
	void vyskladnenie(); 
	void vyhladanieDodavatela(int odkedy, int dokedy) const;
	void vypisSkladu(); 
	void vypisanieVsetkychPoziadaviekNeplat();
	void vyhladanieOdberatela(int odkedy, int dokedy) const;
	void ulozitDoSuboru(const std::string& subor);
	void nacitatZoSuboru(const std::string& subor);

	bool kontrolaDatumu(int datum);
	template <typename T>
	void vymazZoZoznamu(DS::ArrayList<T>& zoznam);
	void vypisDodavky();

	void zoradPole(DS::ArrayList<std::string>& pole);

	Dodavatel* najdiDodavatela(const std::string& nazov);
	Mineralna_voda* najdiMineralnuVodu(const std::string& nazov);
	Zakaznik * najdiZakaznika(const std::string & nazov);
	Predajna * najdiPredajnu(const std:: string & adresa);

	void nastavDatum();

	~System();

private:
	;
	int aktualDatum_;
	Velkosklad* sklad_;
	DS::ArrayList<Zakaznik*>* zakaznici_;
	DS::ArrayList<Predajna*>* predajne_;
	DS::ArrayList<Mineralna_voda*>* mineralky_;
	DS::ArrayList<Dodavatel*>* dodavatelia_;
};