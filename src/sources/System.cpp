#include "System.h"
#include "PriorityQueue_Heap.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace DS;
using namespace std;

static bool porovnajDodavatelov(Dodavatel*& a, Dodavatel*& b)
{
	return *a == *b;
}

static bool porovnajPredajne(Predajna*& a, Predajna*& b)
{
	return *a == *b;
}

static bool porovnajMineralneVody(Mineralna_voda*& a, Mineralna_voda*& b)
{
	return *a == *b;
}

static bool porovnajZakaznikov(Zakaznik*& a, Zakaznik*& b)
{
	return *a == *b;
}

System::System():
	zakaznici_(new ArrayList<Zakaznik*>(10,
		reinterpret_cast<EqualityFunction<Zakaznik*>>(porovnajZakaznikov))),
    predajne_(new ArrayList<Predajna*>(10,
		reinterpret_cast<EqualityFunction<Predajna*>>(porovnajZakaznikov))),
	mineralky_(new ArrayList<Mineralna_voda*>(10,
		reinterpret_cast<EqualityFunction<Mineralna_voda*>>(porovnajZakaznikov))),
	dodavatelia_(new ArrayList<Dodavatel*>(10,
		reinterpret_cast<EqualityFunction<Dodavatel*>>(porovnajZakaznikov))),
	sklad_(new Velkosklad())
{
	nastavDatum();
}

System::~System()
{
	vymazZoZoznamu<Zakaznik*>(*zakaznici_);
	delete zakaznici_;
	vymazZoZoznamu<Predajna*>(*predajne_);
	delete predajne_;
	vymazZoZoznamu<Mineralna_voda*>(*mineralky_);
	delete mineralky_;
	vymazZoZoznamu<Dodavatel*>(*dodavatelia_);
	delete dodavatelia_;
	delete sklad_;
}

System& System::dajInstanciu()
{
	static System instancia;
	return instancia;
}
//  PRIDANIE DODAVATELA
bool System::pridanieNovehoDodavatela(const string& nazov, 
									  const string& adresa)
{
	if (najdiDodavatela(nazov) != nullptr)
	{
		cout << "~ Dodavatel '" << nazov << "'uz existuje!!" << endl;
		return false;
	}
	Dodavatel* novyDodavatel = new Dodavatel(nazov, adresa);
	dodavatelia_->add(novyDodavatel);
	cout << "$ Pridany dodavatel s nazvom '"<< nazov <<"' "<< endl;
	return true;						  
}
// PRIDANIE ZAKAZNIKA
bool System::pridanieNovehoZakaznika(const string& meno,
									 const string& adresa)
{
	Zakaznik* zak = najdiZakaznika(meno);
	if (zak != nullptr)
	{
		cout << "~ Zakaznik '" << meno << "' uz existuje!!" << endl;
		return false;
	}
	Zakaznik* novyZakaznik = new Zakaznik(meno, adresa);
	zakaznici_->add(novyZakaznik);
	cout << "$ Pridany zakaznik s nazvom '" << meno << "' " << endl;
	return true;
}
// PRIDANIE PREDAJNE
bool System::pridanieNovejPredajne(const string& menoZakaznika,
								   const string& adresa,
								   const string& zonaS)
{
	int zona = prevedNaInt(zonaS);
	Zakaznik* zak = najdiZakaznika(menoZakaznika);
	if (zak == nullptr)
	{
		cout << "~ Zakaznik '" << menoZakaznika << "' neexistuje!!" << endl;
		return false;
	}	 
	Predajna* predaj = najdiPredajnu(adresa);
	if (predaj != nullptr)
	{
		cout << "~ Predajna na tejto adrese uz existuje!!" << endl;
		return false;
	}
	
	Predajna* novaPredajna = new Predajna(menoZakaznika, adresa, zona);
	predajne_->add(novaPredajna);
	cout << "$ Pridana predajna na adrese '" << novaPredajna->dajNazov() << "' zakaznikovi '"
		<< novaPredajna->dajMenoZakaznika() << "' " << endl;
	return true;
}
// PRIDANIE NOVEHO TYPU MINERALNEJ VODY 
bool System::pridanieNovehoTypuMVody(const string& nazov,
									 const string& ean,
									 const string& nazovDodavatela)
{
	if (!kontrolaEAN(ean)) return false;
	Dodavatel* dodavatel = najdiDodavatela(nazovDodavatela);
	if (dodavatel == nullptr)
	{
		cout << "~ Dodavatel '" << nazov << "'neexistuje!!" << endl;
		return false;
	}
	Mineralna_voda* miner = najdiMineralnuVodu(ean);
	if (miner != nullptr)
	{
		cout << "~ Min.voda '" << ean << "' - '" << nazov
			 << "' uz existuje !!!" << endl;
		return false;
	}
	Mineralna_voda* novaMineralka = new Mineralna_voda(nazov, ean, *dodavatel);
	mineralky_->add(novaMineralka);
	cout << "$ Pridana min.voda '" << ean << "' - '" << nazov << "'" << endl;
	return true;
}
// ZAEVIDOVANIE DODAVKY
bool System::zaevidovanieNovejDodavky(const string& ean,
									  const string& mnozstvoS,
									  const string& datumPlneniaS)
{
	int mnozstvo = prevedNaInt(mnozstvoS);
	int datumPlnenia = prevedNaInt(datumPlneniaS);
	if (!kontrolaEAN(ean)) return false;
	if (kontrolaDatumu(datumPlnenia)) return false;
	if (datumPlnenia > aktualDatum_)
	{
		cout << "~ Datum plnenia este nenastal " << endl;
		return false;
	}
	Mineralna_voda * mineralka = najdiMineralnuVodu(ean);
	if (mineralka == nullptr)
	{
		cout << "~ Mineralka '" << ean << "' neexistuje!!" << endl;
		return false;
	}
	Dodavka* novaDodavka = new Dodavka(*mineralka, mnozstvo, datumPlnenia);
	sklad_->zaevidujDodavku(novaDodavka);
	cout << "$ Pridana dodavka mineralok '" << ean << "' - '" << mineralka->dajNazov() << "'" << endl;
	return true; 		
} 

// ZAEVIDOVANIE OBJEDNAVKY
bool System::zaevidovanieObjednavky(const string& zakaznik,
									const string& predajna,
									const string& zona,
									const string& datumDoruceniaS,
									const string& polozky)
{
	int datumDorucenia = prevedNaInt(datumDoruceniaS);
	if (kontrolaDatumu(datumDorucenia))	return false;
	if (datumDorucenia < aktualDatum_)
	{
		cout << "~ Datum objednavky je stary " << endl;
		return false;
	}
	/*
	if (aktualDatum_ + 2 >= datumDorucenia)
	{
		cerr << "~ Neobjednam koli datumu..." << endl;
		return false;
	}
	*/
	Predajna* predajnaInst = najdiPredajnu(predajna);
	Objednavka *objednavka = new Objednavka(*predajnaInst, datumDorucenia);

	int pocetOddelovacov = static_cast<int>(count(polozky.begin(), polozky.end(), '|'));
	int pocetPoloziek = pocetOddelovacov + 1;
	int bytePrecitaneCelkovo = 0;
	for (int i = 0; i < pocetPoloziek; i++)
	{
		int bytePrecitaneTeraz = 0;
		char nazov[30];
		int mnozstvo;
		if (i == (pocetPoloziek - 1))
		{
			sscanf(polozky.c_str() + bytePrecitaneCelkovo, "%s %d%n", nazov, &mnozstvo,
				&bytePrecitaneTeraz);
		}
		else
		{
			sscanf(polozky.c_str() + bytePrecitaneCelkovo, "%s %d %*c%n", nazov, &mnozstvo,
				&bytePrecitaneTeraz);
		}
		bytePrecitaneCelkovo += bytePrecitaneTeraz;
		cout << "\tmineralka: " << nazov << " s mnozstvom " << mnozstvo << endl;
		Mineralna_voda* minVodaInst = najdiMineralnuVodu(string(nazov));
		if (minVodaInst == nullptr)
		{
			cerr << "~ Neexistujuca mineralna voda" << endl;
			delete objednavka;
			return false;
		}
		objednavka->pridajPolozku(*minVodaInst, mnozstvo);
	}
	sklad_->zaevidujObjednavku(objednavka);

	return true;
}		
// KONTROLA POZIADAVIEK ZAKAZNIKA 
void System::kontrolaPoziadaviekZ()	
{
	cout << endl;
	sklad_->kontrolaPoziadaviek();
}
// VYHLADANIE NAJPOZADOVANEJSIEHO DODAVATELA														  
void System::vyhladanieDodavatela(const string & odkedyS,
								  const string & dokedyS)
{
	int odkedy = prevedNaInt(odkedyS);
	int dokedy = prevedNaInt(dokedyS);
	cout << endl;
	sklad_->vyhladanieDodavatela(odkedy,dokedy);
}
// VYHLADANIE NAJ ODBERATELA	    
void System::vyhladanieOdberatelaTypuMinVody(const string & ean,
											 const string & odkedyS,
											 const string & dokedyS)
{
	int odkedy = prevedNaInt(odkedyS);
	int dokedy = prevedNaInt(dokedyS);
	cout << endl;
	sklad_->vyhladanieOdberatelaVody(ean, odkedy, dokedy);
}

void System::vyhladanieOdberatelaOdDodavatela(const string & dodavatel,
											  const string & odkedyS,
											  const string & dokedyS)
{
	int odkedy = prevedNaInt(odkedyS);
	int dokedy = prevedNaInt(dokedyS);
	cout << endl;
	sklad_->vyhladanieOdberatelaOdDodavatela(dodavatel, odkedy, dokedy);
}
// VYPISANIE SKLADU
void System::vypisSkladu()
{
	cout << endl;
	sklad_->vypisSklad();
}
// VYPIS NEPLATNYCH OBJEDNAVOK
void System::vypisanieVsetkychPoziadaviekNeplat()
{
	cout << endl;
	sklad_->vypisNeplatneObjednavky();
}
// ULOZENIE DO SUBORU
void System::ulozitDoSuboru(ostream& subor)
{
	for (auto zakaznik : *zakaznici_)
	{
		subor << zakaznik->dajPrikazNaUlozenie() << endl;
	}

	for (auto predajna : *predajne_)
	{
		subor << predajna->dajPrikazNaUlozenie() << endl;
	}

	for (auto dodavatel : *dodavatelia_)
	{
		subor << dodavatel->dajPrikazNaUlozenie() << endl;
	}

	for (auto voda : *mineralky_)
	{
		subor << voda->dajPrikazNaUlozenie() << endl;
	}

	sklad_->ulozDoSuboru(subor);
}
// ODOVZDANIE ZAKAZNIKOVI
void System::odovzdanieZakaznikovi()
{
	cout << endl;
	sklad_->odovzdajZakanikovy();
}
// VYSKLADNENIE
void System::vyskladnenie()
{
	cout << endl;
	sklad_->vyskladnenie(aktualDatum_);
}
//___________________________________________________________________________POMOCNE FUNKCIE
void System::nastavDatum()
{
	Datum* aktualnyDatum = new Datum();
	aktualDatum_ = aktualnyDatum->aktualnyDatum();
}

void System::zoradPole(DS::ArrayList<string>& pole)
{
	bool vymeneny = true;
	while (vymeneny)
	{
		vymeneny = false;
		for (int i = 0; i < static_cast<int>(pole.size() - 1); i++)
		{
			if (pole[i] > pole[i+1])
			{
				string pom = pole[i];
				pole[i] = pole[i + 1];
				pole[i + 1] = pom;
				vymeneny = true;
			}
		}
	}
}
// NAJDI PREDAJNU ak neexistuje vrati nullptr
Predajna * System::najdiPredajnu(const string & adresa)
{
	for (auto predajna : *predajne_)
	{
		if (predajna->dajNazov() == adresa)
		{
			return predajna;
		}
	}
	return nullptr;
}
// NAJDI ZAKAZNIKA ak neexistuje vrati nullptr
Zakaznik * System::najdiZakaznika(const string & nazov)
{
	for (auto zakaznik: *zakaznici_)
	{
		if (zakaznik->dajNazov() == nazov)
		{
			return zakaznik;
		}
	}
	return nullptr;
}
// NAJDI DODAVATELA ak neexistuje vrati nullptr
Dodavatel * System::najdiDodavatela(const string & nazov)
{
	for (auto dodavatel : *dodavatelia_)
	{
		if (dodavatel->dajNazov() == nazov)
		{
			return dodavatel;
		}
	}
	return nullptr;
}
// NAJDI MINERALKU ak neexistuje vrati nullptr
Mineralna_voda * System::najdiMineralnuVodu(const std::string & ean)
{
	for (auto voda : *mineralky_)
	{
		if (voda->dajEAN() == ean)
		{
			return voda;
		}
	}
	return nullptr;	
}

template <typename T>
void System::vymazZoZoznamu(DS::ArrayList<T>& zoznam)
{
	for (auto prvok : zoznam)
	{
		delete prvok;
	}
	zoznam.clear();
}

bool System::kontrolaEAN(const std::string & ean)
{
	if (ean.size() != 13)
	{
		cout << "~ Neplatny EAN kod ! " << endl;
		return false;
	}
}
// KONTROLOVANIE DATUMU
bool System::kontrolaDatumu(int datumP)
{
	if (datumP > 20300000)
	{
		return true;
	}
	Datum* datum = new Datum(datumP);
	if (!datum->kontrolaDatumu())
	{
		cout << "~ Neplatny datum !" << endl;
		delete datum;
		return true;
	}
	delete datum;
	return false;
}

int System::prevedNaInt(const std::string & naInt)
{
	int intS = stoi(naInt);
	return intS;
}