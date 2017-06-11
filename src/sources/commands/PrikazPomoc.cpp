#include "PrikazPomoc.h"
#include "NazvyPrikazov.h"

using namespace std;

PrikazPomoc::PrikazPomoc(string param[])
{
	for (int i = 0; i < 10; i++)
		_param[i] = param[i];
}


PrikazPomoc::~PrikazPomoc()
{
}

void PrikazPomoc::pomoc()
{
	cout << "** pomoc" << endl;
	cout << "** pomoc |prikaz|" << endl;

}

void PrikazPomoc::vykonaj()
{
	if (_param[1].empty())
	{
		NazvyPrikazov nazvyPrikazov;

		nazvyPrikazov.vypisVsetkyPrikazy();
	}
	else if (!(_param[1].empty()) && _param[2].empty()) {
		NazvyPrikazov nazvyPrikazov;

		string params[10];
		params[0] = _param[1];

		IPrikaz * prikaz = nazvyPrikazov.dajPrikaz(params);
		if (prikaz == nullptr)
		{
			cerr << "~ Prikaz neexistuje." << endl;
			return;
		}

		prikaz->pomoc();

		delete prikaz;
	}
	else {
		throw runtime_error("~ Neplatny prikaz");
	}
}