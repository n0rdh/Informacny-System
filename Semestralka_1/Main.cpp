
#include <iostream>
#include "Parser.h"

using namespace std;

int main()
{
	cout << "**************************************************************** " << endl;
	cout << "		    Semestralna praca 1			    " << endl;
	cout << "		  autor Tomas Illo 5ZI02B			    " << endl;
	cout << "		System pre sklad mineralnych vod	    " << endl;
	cout << "*****************************************************************" << endl;

	try
	{
		Parser parser(&cin);

		while (parser.bolPrikazUkonceniaSpusteny() == false)
		{
			try
			{
				cout << "#### zadaj prikaz >>>>>  ";
				IPrikaz* prikaz = parser.nacitajPrikaz();
				if (prikaz == nullptr)
				{
					cerr << "Nespravny prikaz!" << endl;
				}
				else
				{
					prikaz->vykonaj();
					delete prikaz;
				}
			}
			catch (const std::exception& e)
			{
				cerr << "Chyba " << e.what() << endl;
			}
		}
	}
	catch (const std::exception& e)
	{
		cerr << "Chyba: " << e.what() << endl;
	}

















	/*
	string nazovDod = "RajecSRO";
	string adresaDod = "RajeckeTeplice";
	string nazovDod2 = "CocacolaSRO";
	string adresaDod2 = "Zilina";
	string menoZak = "ZakaznikPrvy";
	string menoZak2 = "Druhy zakaznik";
	string adresaZak = "Trebisov";
	string adresaPredajne = "Trebisov 01";
	string zilina = "Zilina";
	string eanRajec = "1588546541651";
	string eanCoca = "3267535749199";
	string eanBudis = "8946535749156";
	string eanBublinky = "0152535749156";
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
	sys->pridanieNovehoTypuMVody(rajecVoda, eanRajec, nazovDod);
	sys->pridanieNovehoTypuMVody(cocacola, eanCoca, nazovDod2);
	sys->pridanieNovehoTypuMVody(budiska, eanBudis, nazovDod2);
	sys->pridanieNovehoTypuMVody(bublinky, eanBublinky, nazovDod);
	cout << endl;
	sys->zaevidovanieNovejDodavky(eanBublinky, 10000, 20160701);
	sys->zaevidovanieNovejDodavky(eanRajec, 10000, 20160803);
	sys->zaevidovanieNovejDodavky(eanBudis, 10000, 20150112);
	sys->zaevidovanieNovejDodavky(eanCoca, 10000, 20160101);
	cout << endl;
	sys->zaevidovanieObjednavky(adresaPredajne, 20160410, eanRajec, 60);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160420, eanBublinky, 30);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160420, eanCoca, 10);
	sys->vypisSkladu();
	sys->vyskladnenie();
	sys->vypisSkladu();
	sys->zaevidovanieObjednavky(adresaPredajne, 20160613, eanCoca, 188);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160417, eanBublinky, 321);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160418, eanCoca, 18);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160410, eanRajec, 61);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160419, eanBublinky, 30);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160813, eanCoca, 10);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160417, eanCoca, 18);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160421, eanRajec, 6);
	sys->zaevidovanieObjednavky(adresaPredajne, 20160416, eanBublinky, 30);
	
	sys->vyskladnenie();
	sys->vypisSkladu();
	sys->vyskladnenie();
	sys->vypisSkladu();

	sys->vyskladnenie();
	sys->vypisSkladu();
	sys->odovzdanieZakaznikovi();
	sys->kontrolaPoziadaviekZ();
	sys->vyhladanieDodavatela(20160416, 20160813);
	//cout << endl;
	//cout << endl;
	//cout << endl;
	sys->kontrolaPoziadaviekZ();
	sys->vyhladanieOdberatelaTypuMinVody(eanCoca, 20160410, 20160813);
	sys->vyhladanieOdberatelaOdDodavatela(nazovDod,20160410, 20160813);
	cout << endl;
	sys->kontrolaPoziadaviekZ();
	sys->vyskladnenie();
	sys->kontrolaPoziadaviekZ();
	sys->vypisanieVsetkychPoziadaviekNeplat();
	sys->kontrolaPoziadaviekZ();
	sys->vypisSkladu();
	sys->vypisanieVsetkychPoziadaviekNeplat();
	sys->kontrolaPoziadaviekZ();
	sys->vyhladanieDodavatela(20160416, 20160813);
	//cout << endl;
	//cout << endl;
	//cout << endl;
	sys->vyhladanieOdberatelaTypuMinVody(eanCoca, 20160410, 20160813);
	sys->vyhladanieOdberatelaOdDodavatela(nazovDod, 20160410, 20160813);
	cout << endl;
	sys->vyskladnenie();
	sys->vypisanieVsetkychPoziadaviekNeplat();
	sys->vypisSkladu();
	sys->vypisanieVsetkychPoziadaviekNeplat();
	sys->kontrolaPoziadaviekZ();
	//cout << endl;
	//cout << endl;
	//cout << endl;
	cout << endl;
	return 0;				
	*/
}  