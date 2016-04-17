#include "AutoPrevoz.h"
#include <iostream>
#include <stack>

using namespace std;
using namespace DS;

AutoPrevoz::AutoPrevoz()
{
	objednavky_ = new Stack<Objednavka*>;
}

AutoPrevoz::AutoPrevoz(const AutoPrevoz & dalsiaDodavkaP)
{
	objednavky_ = dalsiaDodavkaP.objednavky_;
} 

AutoPrevoz & AutoPrevoz::operator=(const AutoPrevoz & dalsiaDodavkaP)
{
	if (this != &dalsiaDodavkaP) {
		delete objednavky_;
		objednavky_ = new Stack<Objednavka*>(*dalsiaDodavkaP.objednavky_);
	}
	return *this;
}

void AutoPrevoz::pridajObjednavku(Objednavka * novaObjednavka)
{
	objednavky_->push(novaObjednavka);
}		   

void AutoPrevoz::distribuj()
{
	while (!objednavky_->isEmpty()) {
		cout << "Objednavka: ";
		objednavky_->pop()->vypisObjednavku();
		cout << "ODOVZDANA zakaznikovi !" << endl;
		objednavky_->pop();
	}
}

AutoPrevoz::~AutoPrevoz()
{
	while(!objednavky_->isEmpty())
	{
		objednavky_->pop();
	}
	delete objednavky_;
}