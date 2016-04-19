#pragma once
#include "Polozka.h"
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
	static System& dajInstanciu();
	
	bool pridanieNovehoTypuMVody(const std::string& nazov,
								 const  std::string& kodEAN,
								 const std::string& nazovDodavatela);
	bool pridanieNovehoDodavatela(const std::string& nazov,
								  const std::string& adresa);
	bool pridanieNovehoZakaznika(const std::string& meno,
								 const std::string& adresa);
	bool pridanieNovejPredajne(const std::string& menoZakaznika,	  
							   const std::string& adresa, 
							   const std::string& zona);
	bool zaevidovanieObjednavky(const std::string& adresaPredajna,
								const std::string& datumDorucenia,
								const std::string& nazovMV,
								const std::string& mnozstvo,
								const std::string& polozky);
	bool zaevidovanieNovejDodavky(const std::string& nazovMV,
								  const std::string& mnozstvo,
								  const std::string& datumPlnenia);

	void vyhladanieDodavatela(const std::string & odkedy,
							  const std::string & dokedy);
	void vyhladanieOdberatelaTypuMinVody(const std::string & voda,
										 const std::string & odkedy,
										 const std::string & dokedy);
	void vyhladanieOdberatelaOdDodavatela(const std::string & dodavatel,
										  const std::string & odkedy,
										  const std::string & dokedy);
	void kontrolaPoziadaviekZ();
	void odovzdanieZakaznikovi(); 
	void vyskladnenie(); 
	void vypisSkladu(); 
	void vypisanieVsetkychPoziadaviekNeplat();
	void ulozitDoSuboru(std::ostream& subor);
	void nacitatZoSuboru(std::string& subor);

	
	bool kontrolaEAN(const std::string & ean);
	void nastavDatum();
	void zoradPole(DS::ArrayList<std::string>& pole);
	int prevedNaInt(const std::string & naInt);
	Dodavatel* najdiDodavatela(const std::string& nazov);
	Mineralna_voda* najdiMineralnuVodu(const std::string& nazov);
	Zakaznik * najdiZakaznika(const std::string & nazov);
	Predajna * najdiPredajnu(const std:: string & adresa);
	bool kontrolaDatumu(int datum);
	template <typename T>
	void vymazZoZoznamu(DS::ArrayList<T>& zoznam);

	~System();

private:	  
	int aktualDatum_;
	Velkosklad* sklad_;
	DS::ArrayList<Zakaznik*>* zakaznici_;
	DS::ArrayList<Predajna*>* predajne_;
	DS::ArrayList<Mineralna_voda*>* mineralky_;
	DS::ArrayList<Dodavatel*>* dodavatelia_;
};