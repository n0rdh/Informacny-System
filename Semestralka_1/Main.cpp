
#include <iostream>
#include "System.h"

using namespace std;

int main()
{
	
	string nazovDod = "RajecSRO";
	string adresaDod = "RajeckeTeplice";
	string nazovDod2 = "CocacolaSRO";
	string adresaDod2 = "Zilina";
	string menoZak = "ZakaznikPrvy";
	string adresaZak = "Trebisov";
	string adresaPredajne = "Trebisov 01";
	string zilina = "Zilina";
	string ean1 = "1588546541651";
	string ean2 = "8946535749156";
	string cocacola = "cocacola";
	string rajecVoda = "rajecVoda";
	string budiska = "budiska";
	string bublinky = "bublinky";


	System* sys = new System();
	sys->pridanieNovehoDodavatela(nazovDod, adresaDod);
	sys->pridanieNovehoDodavatela(nazovDod2, adresaDod2);
	sys->pridanieNovehoZakaznika(menoZak, adresaZak);
	sys->pridanieNovejPredajne(menoZak, adresaPredajne,4);
	cout << endl;
	sys->pridanieNovehoTypuMVody(rajecVoda, ean1, nazovDod);
	sys->pridanieNovehoTypuMVody(cocacola, ean1, nazovDod2);
	sys->pridanieNovehoTypuMVody(budiska, ean2, nazovDod2);
	sys->pridanieNovehoTypuMVody(bublinky, ean1, nazovDod);
	cout << endl;
	sys->zaevidovanieNovejDodavky(budiska, 4774899, 20160413);
	sys->zaevidovanieNovejDodavky(rajecVoda, 9564, 20160101);
	sys->zaevidovanieNovejDodavky(cocacola, 97546, 20160101);
	sys->zaevidovanieNovejDodavky(bublinky, 175456, 20160101);
	sys->zaevidovanieNovejDodavky(budiska, 77489, 20160101);
	sys->zaevidovanieNovejDodavky(cocacola, 5646646, 20160101);
	cout << endl;
	sys->zaevidovanieObjednavky(adresaPredajne, 20160613, cocacola, 188);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160913, rajecVoda, 6821);
	sys->zaevidovanieObjednavky(adresaPredajne, 20161013, bublinky, 3316);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160813, cocacola, 10);
	//adresaPredajna,typMinVody, mnozstvo, datumDorucenia
	//sys->vypisanieVsetkychPoziadaviekNeplat();
	cout << endl;
	cout << endl;
	sys->kontrolaPoziadaviekZ();
	sys->vypisSkladu();
	sys->vyhladanieDodavatela(20160613, 20161013);
	cout << endl;
	cout << endl;
	sys->vypisSkladu();
	cout << endl;
	cout << endl;
	//sys->vyhladanieDodavatela(20161010, 20171213);
	return 0;
}  