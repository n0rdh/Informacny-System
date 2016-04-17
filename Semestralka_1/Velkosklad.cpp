#include "Velkosklad.h"
#include "PriorityQueue_Heap.h"
#include <map>
using namespace std;
using namespace DS;

Velkosklad::Velkosklad() :
	sklad_(new ArrayList<PolozkaOBJ*>()),
	dodavky_(new ArrayList<Dodavka*>()),
	objednavky_(new ArrayList<Objednavka*>()),
	autoPrevoz_(new Stack<Objednavka*>())
{
}

Velkosklad::Velkosklad(const Velkosklad & dalsiVelkosklad) :
	sklad_(new ArrayList<PolozkaOBJ*>(*dalsiVelkosklad.sklad_)),
	dodavky_(new ArrayList<Dodavka*>(*dalsiVelkosklad.dodavky_)),
	objednavky_(new ArrayList<Objednavka*>(*dalsiVelkosklad.objednavky_)),
	autoPrevoz_(new Stack<Objednavka*>(*dalsiVelkosklad.autoPrevoz_))
{															
}

bool Velkosklad::zaevidujObjednavku(Objednavka * pObjednavka)
{
	objednavky_->add(pObjednavka);
	return true;
}

bool Velkosklad::zaevidujDodavku(Dodavka * pDodavka)
{
	dodavky_->add(pDodavka);
	for (auto polozka : *sklad_)
	{
		if (polozka->dajMineralku().dajNazov() == pDodavka->dajMinetralku().dajNazov())
		{
			polozka->zvysMnozstvo(pDodavka->dajMnozstvo());
			return true;
		}
	}
	PolozkaOBJ* novaPolozka = new PolozkaOBJ(pDodavka->dajMinetralku(), pDodavka->dajMnozstvo());
	sklad_->add(novaPolozka);
	return true;
}

void Velkosklad::odovzdajZakanikovy()
{
	if (autoPrevoz_->isEmpty())
	{
		cout << "  Auto je uz pradne" << endl;
		return;
	}
	cout << "$ Objednavka: ";
	autoPrevoz_->pop()->vypisObjednavku();
	cout << "ODOVZDANA zakaznikovi !" << endl;
}

void Velkosklad::vyskladnenie(int datum)
{
	PriorityQueue_Heap<Objednavka*>* zoradenie = new PriorityQueue_Heap<Objednavka*>();
	for (Objednavka* objednavka : *objednavky_)
	{

	}
	delete zoradenie;
}

void Velkosklad::vyhladanieDodavatela(int odkedy, int dokedy)
{
	map <Dodavatel*, int> zoznam;
	for (auto objednavka : *objednavky_)
	{
		if (!(objednavka->dajDatumDorucenia() >= dokedy
			&& objednavka->dajDatumDorucenia() <= dokedy)) continue;
		
		for (auto polozka : *objednavka->dajPolozky())
		{
			Dodavatel* dodPom = &polozka->dajMineralku().dajDodavatela();
			if (zoznam.count(dodPom) == 0)
			{
				zoznam[&polozka->dajMineralku().dajDodavatela()] = polozka->dajMnozstvo();
			}
			else
			{
				zoznam[&polozka->dajMineralku().dajDodavatela()] += polozka->dajMnozstvo();
			}
		}
	}
	Dodavatel* maxDodavatel = NULL;
	int maxMnozstvo = 0;
	for (auto prvok : zoznam)
	{
		if (prvok.second > maxMnozstvo)
		{
			maxMnozstvo = prvok.second;
			maxDodavatel = prvok.first;
		}
	}
	cout << "$ Najziadanejsi dodavatel \n	- " 
		 << maxDodavatel->dajNazov() << " - " << maxMnozstvo << " ks"<< endl;
}

void Velkosklad::kontrolaPoziadaviek()
{
	string pom;
	cout << "$ Chybajuce pozadovane mineralne vody: " << endl;
	ArrayList<PolozkaOBJ*>* polozkyVsklade = new ArrayList<PolozkaOBJ*>();
	ArrayList<PolozkaOBJ*>* pozadovanePolozky = new ArrayList<PolozkaOBJ*>();
	ArrayList<string>* vypisZoradenie = new ArrayList<string>();
	for (auto polozkaS : *sklad_)
	{
		PolozkaOBJ* nova = new PolozkaOBJ(polozkaS->dajMineralku(), polozkaS->dajMnozstvo());
		polozkyVsklade->add(nova);
	}
	for (auto objednavka : *objednavky_)
	{
		for (auto polozka : *objednavka->dajPolozky())
		{
			PolozkaOBJ* pom = new PolozkaOBJ(polozka->dajMineralku(), polozka->dajMnozstvo());
			pozadovanePolozky->add(pom);
		}
	}
	for (auto polS : *polozkyVsklade)
	{
		for (auto poz : *pozadovanePolozky)
		{
			if (polS->dajMineralku().dajNazov() == poz->dajMineralku().dajNazov())
			{
				polS->znizMnozstvo(poz->dajMnozstvo());
			}										   			
		}
	}
	int i = 0;
	for (auto polozkaVypis : *polozkyVsklade)
	{
		if (polozkaVypis->dajMnozstvo() < 0)
		{
			pom = "";
			pom.append(polozkaVypis->dajMineralku().dajNazovDodavatela());
			pom.append(" - ");
			pom.append(polozkaVypis->dajMineralku().dajNazov());
			pom.append(" - ");
			pom.append(to_string(polozkaVypis->dajMnozstvo()*(-1)));
			pom.append(" ks ");
			vypisZoradenie->add(pom);
			i++;
		}
	}	
	if (i == 0)
	{
		cout << "        - Nechybaju ziadne vody\n" << endl;
		return;
	}
	zoradPole(*vypisZoradenie);
	for (auto vyp : *vypisZoradenie)	
	{
		cout << "        - " << vyp << endl;
	}
	vymazVsetkypolozky(pozadovanePolozky);
	vymazVsetkypolozky(polozkyVsklade);
	delete vypisZoradenie;
	delete pozadovanePolozky;
	delete polozkyVsklade;
}

void Velkosklad::vypisVsetkyDodavky()
{
	//zoradDodavkyDodavky();
	for (auto dodavka : *dodavky_)
	{
		cout << dodavka->toString() << endl;
	}
}

void Velkosklad::zoradDodavkyDodavky()
{

	PriorityQueue_Heap<Dodavka*>*  zoradenie = new PriorityQueue_Heap<Dodavka*>();
	for (auto dodavka : *dodavky_)
	{
		Dodavka* nova = new Dodavka(dodavka->dajMinetralku(), dodavka->dajMnozstvo(), dodavka->dajDatumPlnenia());
		zoradenie->push(nova->dajDatumPlnenia(), nova);
		delete dodavka;
	}
	while (!zoradenie->isEmpty())
	{
		dodavky_->add(zoradenie->pop());
	}
	delete zoradenie;
}

void Velkosklad::vypisNeplatneObjednavky()
{
	cout << "Neplatne objednavky: " << endl;
	for (auto objednavka : *objednavky_)
	{
		if (objednavka->dajStavObjednavky() == "NEPLATNA")
		{
			cout << "		- ";
			cout << objednavka->vypisObjednavku() << endl;
		}		   		
	}	
	cout << endl;
}

void Velkosklad::vypisVsetkyObjednavky()
{
	cout << "Vsetky objednavky :" << endl;
	for (auto objednavka : *objednavky_)
	{
		cout << objednavka->vypisObjednavku() << endl;
	}
}

void Velkosklad::vypisSklad()
{
	ArrayList<string>* vypisZoradenie = new ArrayList<string>();
	string pom;
	cout << "$ Obsah skladu je:" << endl;
	for (auto polozka : *sklad_)
	{
		pom = "";
		pom.append(polozka->dajMineralku().dajNazov());
		pom.append(" - ");
		pom.append(polozka->dajMineralku().dajNazov());
		pom.append(" - ");
		pom.append(to_string(polozka->dajMnozstvo()));
		pom.append(" ks  \n");
		vypisZoradenie->add(pom);
	}
	zoradPole(*vypisZoradenie);
	for (auto vypis : *vypisZoradenie)
	{
		cout << "	- " << vypis;
	}
	delete vypisZoradenie;
}

void Velkosklad::zoradPole(DS::ArrayList<string>& pole)
{
	bool vymeneny = true;
	while (vymeneny)
	{
		vymeneny = false;
		for (int i = 0; i < static_cast<int>(pole.size() - 1); i++)
		{
			if (pole[i] > pole[i + 1])											 
			{
				string pom = pole[i];
				pole[i] = pole[i + 1];
				pole[i + 1] = pom;
				vymeneny = true;
			}
		}
	}
}

void Velkosklad::vymazVsetkoVAute()
{
	while (!autoPrevoz_->isEmpty())
	{
		autoPrevoz_->pop();
	}
}

void Velkosklad::vymazVsetkyObjednavky()
{
	for (auto poz : *objednavky_)
	{
		delete poz;
	}
}

void Velkosklad::vymazVsetkyDodavky()
{
	for (auto poz : *dodavky_)
	{
		delete poz;
	}
}

void Velkosklad::vymazVsetkypolozky(ArrayList<PolozkaOBJ*>* p)
{
	for (auto poz : *p)
	{
		delete poz;
	}
}

Velkosklad::~Velkosklad()
{
	vymazVsetkyDodavky();
	delete dodavky_;
	vymazVsetkoVAute();
	delete autoPrevoz_;
	vymazVsetkyObjednavky();
	delete objednavky_;
	vymazVsetkypolozky(sklad_);
	delete sklad_;
}